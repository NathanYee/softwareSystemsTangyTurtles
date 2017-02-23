/**
	Arduino 1 bit DAC
	Tangy Turtles
*/

#define F_CPU 16000000UL // Sets the cpu frequency
#define BAUD 9600 // Sets the baud rate for serial 

#include <avr/interrupt.h> // Use timer interrupt library
#include <avr/io.h> // Use for register naming of io
#include <math.h> // Use for generating sine wave
#include "listing1.h"
#include "serial.h"

/*
	Initial sine wave parameters
*/
#define PI2 6.283185 // 2*PI saves calculation later
#define AMP 127 // Scaling factor for sine wave
#define OFFSET 128 // Offset shifts wave to all >0 values

int main() {
	uart_init(); // Initializing the uart port for serial
	stdin  = &uart_input;

	init_wave(); // Initializing the wave
	freq = 255;

	/****Set timer1 for 8-bit fast PWM output ****/
	DDRB = DDRB | _BV(DDB1);
	TCCR1B  = (1 << CS10); // Set prescaler to full 16MHz
	TCCR1A |= (1 << COM1A1); // Pin low when TCNT1=OCR1A
	TCCR1A |= (1 << WGM10); // Use 8-bit fast PWM mode
	TCCR1B |= (1 << WGM12);

	/******** Set up timer2 to call ISR ********/
	TCCR2A = 0; // No options in control register A
	TCCR2B = (1 << CS21); // Set prescaler to divide by 8
	TIMSK2 = (1 << OCIE2A); // Call ISR when TCNT2 = OCRA2
	OCR2A = round((2000000.0 / 256.0) * (1.0 / freq)); // Set frequency of generated wave
	sei(); // Enable interrupts to generate waveform!

	while(1){
		freq = getchar();
	}
}

void init_wave(){
	/* Populate the waveform table with a sine wave */
	for (int i=0; i<LENGTH; i++) { // Step across wave table
		float v = (AMP*sin((PI2/LENGTH)*i)); // Compute value
		wave[i] = (int) (v+OFFSET); // Store value as integer
	}
}

/******** Called every time TCNT2 = OCR2A ********/
ISR(TIMER2_COMPA_vect) { // Called when TCNT2 == OCR2A
	static uint8_t index=0; // Points to each table entry
	OCR1AL = wave[index++]; // Update the PWM output
	__asm("NOP;NOP"); // Fine tuning
	TCNT2 = 6; // Timing to compensate for ISR run time
}
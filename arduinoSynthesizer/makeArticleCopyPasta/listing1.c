#include <avr/interrupt.h> // Use timer interrupt library
#include <avr/io.h>
#include <math.h>


/******** Sine wave parameters ********/
#define PI2 6.283185 // 2*PI saves calculation later
#define AMP 127 // Scaling factor for sine wave
#define OFFSET 128 // Offset shifts wave to all >0 values
#define FREQUENCY 440 // Enter desired frequency here - 1450+ don't work with speaker

/******** Lookup table ********/
#define LENGTH 256 // Length of the wave lookup table
unsigned char wave[LENGTH]; // Storage for waveform

int main() {
	/* Populate the waveform table with a sine wave */
	for (int i=0; i<LENGTH; i++) { // Step across wave table
		float v = (AMP*sin((PI2/LENGTH)*i)); // Compute value
		wave[i] = (int) (v+OFFSET); // Store value as integer
	}

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
	// OCR2A = 18; // Set frequency of generated wave
	OCR2A = round((2000000.0 / 256.0) * (1.0 / FREQUENCY)); // Set frequency of generated wave
	sei(); // Enable interrupts to generate waveform!

	while(1){
	}
}

/******** Called every time TCNT2 = OCR2A ********/
ISR(TIMER2_COMPA_vect) { // Called when TCNT2 == OCR2A
	static unsigned char index=0; // Points to each table entry
	OCR1AL = wave[index++]; // Update the PWM output
	__asm("NOP;NOP"); // Fine tuning
	TCNT2 = 5; // Timing to compensate for ISR run time
}

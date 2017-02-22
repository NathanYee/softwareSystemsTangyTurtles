#include "serial.h"

/**
	This function initializes serial communication on the arduino
	We are only going to be recieving so we only set up RX
*/
void uart_init(void){
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	/*
		The following if/else determines whether the UART
		has to run in double speed mode
	*/
	#if USE_2X
		UCSR0A |= _BV(U2X0);
	#else
		UCSR0A &= ~(_BV(U2X0));
	#endif

	/*
		Setting the serial port to 8 bit mode
		and to recieve data 
	*/
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
	UCSR0B =  _BV(RXEN0);
}
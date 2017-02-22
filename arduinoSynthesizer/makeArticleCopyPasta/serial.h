#ifndef SERIAL_H
#define SERIAL_H

/*
	Defining cpu freq and baud rate if not already defined
*/
#ifndef F_CPU
	#define F_CPU 16000000UL // Sets the cpu frequency
#endif // F_CPU
#ifndef BAUD
	#define BAUD 9600 // Sets the baud rate for serial
#endif // BAUD 

#include <util/setbaud.h> // Use for serial communication
#include <avr/io.h> // Use for register naming of ios

void uart_init(void);

#endif // SERIAL_H
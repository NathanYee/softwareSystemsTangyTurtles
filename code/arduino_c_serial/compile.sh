#!/bin/bash
avr-gcc -Os -std=c11 -DF_CPU=16000000UL -mmcu=atmega328p -c -o listing1.o listing1.c
avr-gcc -Os -std=c11 -DF_CPU=16000000UL -mmcu=atmega328p -c -o serial.o serial.c

avr-gcc -mmcu=atmega328p listing1.o serial.o -o listing.o
avr-objcopy -O ihex -R .eeprom listing.o listing.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:listing.hex
#!/bin/bash
filename=$1
rm $filename
rm $filename.hex
rm $filename.o

avr-gcc -Os -std=c11 -DF_CPU=16000000UL -mmcu=atmega328p -c -o $filename.o $filename.c
avr-gcc -mmcu=atmega328p $filename.o -o $filename
avr-objcopy -O ihex -R .eeprom $filename $filename.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:$filename.hex

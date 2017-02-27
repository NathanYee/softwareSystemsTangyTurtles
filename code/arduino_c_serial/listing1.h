#ifndef LISTING_H
#define LISTING_H

/*
	Array to store the sine wave values
*/
#define LENGTH 256 // Length of the wave lookup table
int wave[LENGTH]; // Storage for waveform
char freq;

//FILE uart_output = FDEV_SETUP_STREAM(uart_put_char, NULL, _FDEV_SETUP_WRITE);
//FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_get_char, _FDEV_SETUP_READ);

void init_wave();

#endif // LISTING_H

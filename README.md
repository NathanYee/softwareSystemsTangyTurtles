# Arduino Synthesizer

A team repository for the class Software Systems at Olin College of Engineering for the team Tangy Turtles.

## Description

We have created an Arduino synthesizer that can be commanded to play a series of tones from an input file that specifies the frequency and duration of each sequential tone. The tones are played through a simple 1-bit DAC, which low-pass filters the output of the Arduino's PWM signals to create smooth waveforms.

## Authors

Shane Kelly, Carl Moser, Nathan Yee

## Resources

* [How to make a 1-bit DAC and play a tone from an Arduino in C.](http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/)

## Getting Started

## Usage

`./stdinToSerial -f little_lamb.txt -p /dev/ttyACM0`

## License

**MIT License**

See `LICENSE.txt`.

# Arduino Synthesizer

A team repository for the class Software Systems at Olin College of Engineering for the team Tangy Turtles.

[Here is a link to our github pages website.](https://nathanyee.github.io/softwareSystemsTangyTurtles/index.html)

## Description

We have created an Arduino synthesizer that can be commanded to play a series of tones from an input file that specifies the frequency and duration of each sequential tone. The tones are played through a simple 1-bit DAC, which low-pass filters the output of the Arduino's PWM signals to create smooth waveforms.

## Authors
[Shane Kelly](https://github.com/shanek21), 
[Carl Moser](https://github.com/cmoser96), 
[Nathan Yee](https://github.com/NathanYee)

## Resources

* [1-bit DAC and wave generation in C.](http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/)
* [Serial communications on an Arduino in C.](https://www.appelsiini.net/2011/simple-usart-with-avr-libc)
* [Arduino port registers.](https://www.arduino.cc/en/Reference/PortManipulation)

## Usage

Compile the Arduino code and upload it to the Uno.

`cd code/arduino`

`./compile.sh`

Send the desired song file to the serial port that the Arduino is currently connected to. Replace `little_lamb.txt` with the preferred song file name and `/dev/ttyACM0` with the current serial port of the Arduino.

`cd ../stdinToSerial`

`make`

`./stdinToSerial -f little_lamb.txt -p /dev/ttyACM0`

## License

[MIT License](https://github.com/NathanYee/softwareSystemsTangyTurtles/blob/master/LICENSE.txt)

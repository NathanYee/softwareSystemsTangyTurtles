# Preliminary report
**_1. State the goal of your project, ideally including a lower bound you are confident you can achieve and a stretch goal that is more ambitious.  This can be an updated version of the section you wrote in the proposal._**

_Lower:_ Produce square and Sine waves from an Arduino where we can tune the amplitude, frequency, and duty cycle. 
_Stretch:_ Play songs by using serial connection to process stdin and stdout.

**_2. Include a list of each project-related card you completed in Sprints 1 and 2. Annotate each card with a pointer to concrete evidence that the card has been completed (e.g. link to committed code, notes from a reading). If you have cards you can't provide evidence for, or work you did that doesn't have a card, make a note of it and use it to refine your cards for the next sprint._**

- Play with Arduino
 - We looked at a lot of Arduino example code in C and got all members of our team to upload C code to an Arduino outside of the Arduino IDE. Future points are evidence of this.
- Research about how to make a square wave
 - Check out our assembled resources!
- Implement listing 1 from Make article in C
 - We have implemented a version of an example from the Make article. Some errors existed in directly using the code, so we made some adjustments. We then compiled and uploaded the code to an Arduino using avr-gcc and avr-dude.
- Produce sound with a 1 bit DAC
 - We created a low-pass filter using a resistor and capacitor such that our jagged PWM signal is smoothed for playback as an analog wave. Though slight distortion may be audible, the circuit works quite well.


**_3. Show preliminary results from your code. Depending on the project this could be a short demo video, example text sequence of commands and outputs, or some other form. Looking ahead to your final report, (updated versions of) these can serve as your usage examples._**

[Video of one-bit dac](https://www.youtube.com/watch?v=xt1GqFKUC0s)

**_4. Demonstrate that you have assembled the resources you need to complete the project.  One good way to do that is to update your annotated bibliography (with a pointer to each resource and a few sentences that describe the content) from the proposal._**

- https://sites.google.com/site/softwaresystems2015/backlog/projects

	Gives an overview of a few Arduino Synthesizer projects and some different hardware
options for creating an ADC.
- http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/

	Gives information about a One-Bit DAC for both software and hardware.
- https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/

	Step-by-step instructions for writing C code to an AVR microcontroller.
- http://www.atmel.com/images/Atmel-8271-8-bit-AVR-Microcontroller-ATmega48A-48PA-88A-88PA-168A-168PA-328-328P_datasheet_Complete.pdf

	A reference sheet for the arduino that has information about the register and port
names.
- http://urbanhonking.com/ideasfordozens/2009/05/18/an_tour_of_the_arduino_interna/

	Goes into depth about the hardware of the arduino and how to program it in C.

**_5. Present a product backlog for the next sprint that represents a concrete plan that will keep the entire team productively engaged and get you to your stated goals (this can be a link to your Trello board). If you had trouble putting together evidence for your cards in the previous sprints, adjust your new cards accordingly._**

https://trello.com/b/YfRLZVmL/softsystangyturtles

**_6. Enumerate potential roadblocks and ways instructors can help.  Do you need materials? Do you have show-stopping questions you have not been able to answer?_**

- There is a lot of complexity hidden behind writing to registers on an Arduino. The sheer number of acronyms/random letter and number combinations is quite daunting. We are continuing to learn about registers and hope to master them soon.
- The frequency of the waves that we play is determined by how quickly our interrupt function is called. This rate is based on an overflow counter and our clock speed. One roadblock is figuring out the technical details behind all of these things and using a pre-scaler to chop up our clock signal to set wave frequency.
-There could be unforeseen roadblocks in the process of a user controlling the synthesizer through stdin to serial input.
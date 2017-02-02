#Software Systems: Tangy Turtles Project 1 Proposal

**_1. State the goal of your project, ideally including a lower bound you are confident you can achieve and a stretch goal that is more ambitious._**

Lower: Produce square and Sine waves from an Arduino where we can tune the amplitude, frequency, and duty cycle. 
Stretch: Implement additional waveforms such as triangle or sawtooth waves. 

**_2. Demonstrate that you have acquired the knowledge you need to get started.  We will know that you have this knowledge if the text of the proposal uses domain language effectively to convey ideas clearly and concisely._**

We will first create a square wave in sprint 2. We know that the first step will be to create a waveform of 1s and 0s. Modifying the percentage of 1s and 0s will be modify the duty cycle, which is the percentage that the waveform remains high or at 1. We decided to use the Arduino’s Timer 2 (TCNT2) which counts from 0 to 255 before overflowing and restarting its count at 0. The timer knows when to overflow and reset by comparing its value to the value stored in the “Output Compare Register” (OCR1A).  We can change the value at which TCNT2 overflows by adjusting the register value stored in OCR1A. We can change the wave’s frequency by changing the value stored in OCR1A. For example, if our Arduino system clock is running at 16MHz and we want the TCNT2 timer to update every 2MHz, then we can set the prescaler to 8MHz to slow down our timer and have a frequency of 2MHz.

We want to begin sine wave implementation around the end of sprint 2/beginning of sprint 3. We are still investigating exactly how to implement this, and will continue to research throughout sprint 2. From a high-level perspective, it may be as easy as creating an array of the desired sample length filled with values that represent time (maybe from 0-5000 milliseconds) and then pushing that array through a built-in sine function.

**_3. Demonstrate that you have assembled the resources you need to get started.  One good way to do that is to include an annotated bibliography with a pointer to each resource and a few sentences that describe the content._**

* https://sites.google.com/site/softwaresystems2015/backlog/projects

	Gives an overview of a few Arduino Synthesizer projects and some different hardware options for creating an ADC.
* http://makezine.com/projects/make-35/advanced-arduino-sound-synthesis/

	Gives information about a One-Bit DAC for both software and hardware.
* https://balau82.wordpress.com/2011/03/29/programming-arduino-uno-in-pure-c/

	Step-by-step instructions for writing C code to an AVR microcontroller.
* http://www.atmel.com/images/Atmel-8271-8-bit-AVR-Microcontroller-ATmega48A-48PA-88A-88PA-168A-168PA-328-328P_datasheet_Complete.pdf

	A reference sheet for the arduino that has information about the register and port names.
* http://urbanhonking.com/ideasfordozens/2009/05/18/an_tour_of_the_arduino_interna/

	Goes into depth about the hardware of the arduino and how to program it in C.

**_4. Present a product backlog for the next two sprints that represents a concrete plan that will keep the entire team productively engaged (this can be a link to your Trello board).  Each item in the product backlog should represent a good sized unit of work, and have an appropriate definition of done. NB: You will also complete ~4 chapters of core class activities each sprint in addition to your project-specific work._**

Trello board: https://trello.com/b/YfRLZVmL/softsystangyturtles

**_5. Enumerate potential roadblocks and ways instructors can help.  Do you need materials?  Do you have show-stopping questions you have not been able to answer?_**

It would be great to be able to borrow an Arduino or two!

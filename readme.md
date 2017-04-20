# Bodgecycle Computer
The bodged together bicycle computer for hackers.

In order to use Bodgecycle Computer you will need the following components:
1. An Arduino Uno or compatible board
2. A USB cable compatible with your chosen Arduino board
3. A SparkFun GPS Logger Shield
4. An Arduino stackable header set
5. A 12mm coin cell battery
6. A micro SD card
7. A 9v battery
8. A 9v battery holder

I sourced all of these parts from SparkFun. The total cost of the parts I used
was about $100. Some of the parts I used were unnecessary, and I also used an
Arduino Uno, which is perhaps not the cheapest Arduino Uno compatible board.
A person using a SparkFun RedBoard and a minimum of parts could probably build
a Bodgecycle Computer for $86.20 buying from SparkFun.

Users comfortable with system voltage could likely shave a further $5-8 off the
cost of this build by using an Arduino Pro or Diavolino. Changing boards
however is not guaranteed to have same results of the reference Bodgecycle
Computer built by Travis Rigg. Users choosing to use a different board will
also have to find their own way to power their board. Users choosing to use a
different board will also be required to know how to upload code to their board
of choice.

## Assembly
This guide will assume that the user is familiar with soldering and Arduino
assembly. There are many guides available online for how to develop these
skills. Attempting to produce a new guide or to replicate one of the existing
guides would likely not introduce anything useful to the experience of using
the Bodgecycle Computer. If anything is unclear about how to proceed, please
open an issue on GitHub.

1. Solder your stackable header set onto the SparkFun GPS Logger Shield.
2. Insert the GPS Logger Shield into your Arduino Uno compatible board.
3. Insert your coin cell battery into the Arduino Uno
  * Make sure the positve terminal is facing up

## Installation
This guide will assume that the user is familiar with the Arduino environment.
There are many guides available online for how to interact with this
environment. Attempting to produce a new guide or to replicate one of the
existing guides would likely not introduce anything useful to the experience of
using the Bodgecycle Computer. If anything is unclear about how to proceed,
please open an issue on GitHub.

1. Install the Arduino IDE
2. Open bodgecycle.ino in your IDE
3. Plug your Arduino into your computer
4. Make sure to select Arduino/Genuino Uno as the type of board you're using
5. Make sure that the serial port your Arduino is connected to is selected
6. Upload your code to the Arduino

## Usage
Before you can start recording data, you need to insert the micro SD card into
the micro SD card slot on your GPS Logger Shield. I don't really know how to
explain how to do that better. If this instruction is unclear, please open an
issue on GitHub.

Now that your SD card is in place, ready to receive data, you should be able to
insert your 9v battery into your 9v battery holder and plug your 9v battery
holder into the DC voltage jack on your Arduino Uno compatible board. Once
power is supplied to the board, it will start recording data as soon as a GPS
signal has been fixed. In order to stop recording, unplug your 9v battery from
your Arduino board.

Now you can take the micro SD card out of your GPS Logger Shield, put it in an
adapter of some sort, plug that adapter into your computer, and open the GPX
file you have recorded in some sort of GPX visualization software.

## Limitations
A Bodgecycle Computer can only store 10 files at a time. Hopefully, this can
represent at least a couple of days worth of rides. For the creator of the
Bodgecycle Computer, this represents a little over a week's worth of bike
rides. Hypothetically, you could run out of space on your bodgecycle computer
after a very long series of rides, however, the battery will run out before
that becomes a problem. A Bodgecycle Computer with a low battery is a very
unstable thing. An easy indication that your Bodgecycle Computer is low on
battery is when there are more files for recorded rides than you would expect
and the files contain incomplete data.

There is a very low chance that when you unplug the battery from your
Bodgecycle Computer that you will interrupt the writing of data. You don't need
to worry about this too much. Your Bodgecycle Computer logs data to the SD card
once a second. It has the ability to perform 16 million actions in a second. I
estimate the odds at interrupting your Bodgecycle Computer from recording data
is about 3:160,000 against. In other words you have a .002% chance of doing
that. You shouldn't worry about it too much, but it can happen.

The goal of the Bodgecycle Computer project is to create something that can
create data that can be uploaded and stored on the website Strava. I don't know
right now if that will work. If you are interested in building a Bodgecycle
Computer and testing this functionality, I would be very happy.

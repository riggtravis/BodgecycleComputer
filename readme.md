# Bodgecycle Computer
The bodged together bicycle computer for hackers.
![A picture of my Bodgecycle Computer](http://i.imgur.com/aNQw7sG.jpg)

In order to use Bodgecycle Computer you will need the following components:
1. An [Arduino Uno](https://www.arduino.cc/en/Main/arduinoBoardUno) or [compatible board](https://www.sainsmart.com/arduino/control-boards/sainsmart-uno-r3-atmega328-au-development-board-compatible-with-arduino-uno-r3.html)
2. A USB cable compatible with your chosen Arduino board
3. A [SparkFun GPS Logger Shield](https://www.sparkfun.com/products/13750)
4. An [Arduino stackable header set](https://www.sparkfun.com/products/11417)
5. A [12mm coin cell battery](https://www.sparkfun.com/products/337)
6. A [micro SD card](https://www.amazon.com/SANDISK-Micro-SDHC-Memory-SDSDQM-004G/dp/B001C0DJL4/ref=sr_1_2?s=pc&ie=UTF8&qid=1492750170&sr=1-2&keywords=sandisk+4gb+microsdhc+memory+card)
7. A [9v battery](https://www.amazon.com/AmazonBasics-Everyday-Alkaline-Batteries-8-Pack/dp/B00MH4QM1S/ref=sr_1_2_s_it?s=hpc&srs=2528919011&ie=UTF8&qid=1492750284&sr=1-2)
8. A [9v battery holder](https://www.adafruit.com/product/67)
9. A [sandwich bag](https://www.amazon.com/Glad-Food-Storage-Snack-Zipper/dp/B00ZKUCFUS/ref=sr_1_4_s_it?ie=UTF8&qid=1492750504&sr=1-4) for wet rides

I sourced all of these parts except for the sandwhich bag from [SparkFun](https://www.sparkfun.com/).
The sandwich bag I got at a [Food Lion](https://www.foodlion.com/). Also
the first 9v battery I had went dead. The new one came from a [Tractor Supply](https://www.tractorsupply.com/).
Philosophical discussion of where to source things to come later.
The total cost of the parts I used
was about \$100. Some of the parts I used were unnecessary. The parts that are
listed here cost about \$91.20. I also used an
Arduino Uno, which is perhaps not
[the cheapest Arduino Uno compatible board](http://www.electrodragon.com/product/arduino-compatible-visduino-uno-r3/).
A person using a SparkFun [RedBoard](https://www.sparkfun.com/products/13975)
and a minimum of parts could probably build a Bodgecycle Computer for $86.20
buying from SparkFun.

Users comfortable with system voltage could likely shave a further $5-8 off the
cost of this build by using an Arduino Pro, [Diavolino](http://shop.evilmadscientist.com/productsmenu/180),
or [Canaduino](https://universal-solder.com/product/canaduino-uno-bone-basic-alternative-arduino-uno-r3-atmega328p-pu/).
Changing boards
however is not guaranteed to have same results of the reference Bodgecycle
Computer built by Travis Rigg. Users choosing to use a different board will
also have to find their own way to power their board. Users choosing to use a
different board will also be required to know how to upload code to their board
of choice.

Bottom line, if you want to use a different board, feel free to do so, but don't
think it's my responsibility to bail you out, or to accept your fixes to your
problems. If you create a pull request that doesn't work with the Arduino Uno R3,
I'm not going to merge it. If you create a pull request that works with your board
and it still works with the Arduino Uno R3, I will probably accept this change. If
someone creates a pull request that I merge that breaks another board I don't care
about, you're going to be sorta on your own.

Users who are satisfied with the first version of the Bodgecycle Computer can also
save some money by getting [regular headers](https://www.sparkfun.com/products/116)
instead of stacking headers. This is not
recommended however because future updates may require more shields than just a GPS
logger shield.

A better way to save some money building this project that could still be expected
to work reliably would be to purchase a smaller and cheaper micro SD card. The one
I have linked in the parts list above is smaller and cheaper than the one I bought
from SparkFun. It should be satisfactory enough.

Users should also feel free to purchase parts their choice of retailer. I used
SparkFun because their website was easier for me to navigate than Adafruit
and I wanted to buy everything from one place. SparkFun's miniature version
of the GPS Logger Shield was also a big boon. I also, for personal reasons,
did want to buy products that supported the developers of the Arduino boards.
Certain Arduino clones don't help support Arduino development. Where you fall
on that philosophical line is up to you.

I do however ask that users not purchase parts from Tractor Supply. I know I
mentioned earlier that I got one of the batteries I used from there, but that
was back when they were the only retailer I could get certain products from. I
always encourage people not to go there if for no other reason than that I have
never been to a Tractor Supply during Chick Days without at least one dead
chicken that they refuse to remove and a chick habitat without enough water or
food. I have no problem owning animals. I own several in fact. I do have a
problem with letting them starve to death.

## Assembly
This guide will assume that the user is familiar with [soldering](http://www.sciencebuddies.org/science-fair-projects/project_ideas/Elec_primer-solder.shtml)
and [Arduino assembly](https://learn.sparkfun.com/tutorials/arduino-shields).
There are many guides available online for how to develop these
skills. Attempting to produce a new guide or to replicate one of the existing
guides would likely not introduce anything useful to the experience of using
the Bodgecycle Computer. If anything is unclear about how to proceed, please
open an issue on GitHub.

1. Solder your stackable header set onto the SparkFun GPS Logger Shield.
![Solder your board](http://i.imgur.com/TZFCenv.jpg)
2. Insert the GPS Logger Shield into your Arduino Uno compatible board.
![Line up all your pins](http://i.imgur.com/YPslNxY.jpg)
![Push down](http://i.imgur.com/GaE2MUe.jpg)
3. Insert your coin cell battery into the Arduino Uno
![Make sure the positive terminal is facing up](http://i.imgur.com/X0OpjMq.jpg)
  * Make sure the positive terminal is facing up
![Push it into the holder](http://i.imgur.com/z5CwGGA.jpg)

## Installation
This guide will assume that the user is familiar with the [Arduino](https://www.arduino.cc/)
environment. There are many
[guides available online for how to interact with this environment](https://www.arduino.cc/en/Guide/HomePage).
Attempting to produce a new guide or to replicate one of the
existing guides would likely not introduce anything useful to the experience of
using the Bodgecycle Computer. If anything is unclear about how to proceed,
please open an issue on GitHub.

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Open bodgecycle.ino in your IDE
3. Plug your Arduino into your computer
4. Make sure to select Arduino/Genuino Uno as the type of board you're using
![Arduino/Genuino Uno](http://i.imgur.com/qLa8NFZ.jpg)
5. Make sure that the serial port your Arduino is connected to is selected
![Serial port selection](http://i.imgur.com/gwHw4W7.png)
6. Upload your code to the Arduino
![Upload code](http://i.imgur.com/HqQ5HfC.png)

## Usage
Before you can start recording data, you need to insert the micro SD card into
the micro SD card slot on your GPS Logger Shield. I don't really know how to
explain how to do that better. If this instruction is unclear, please open an
issue on GitHub.
![The micro SD slot is the one that lines up right above the USB port](http://i.imgur.com/2noKay1.jpg)
![Push the micro SD card in until you hear it click](http://i.imgur.com/rhpKQqM.jpg)

Now that your SD card is in place, ready to receive data, you should be able to
insert your 9v battery into your 9v battery holder and plug your 9v battery
holder into the DC voltage jack on your Arduino Uno compatible board. Once
power is supplied to the board, it will start recording data as soon as a GPS
signal has been fixed. In order to stop recording, unplug your 9v battery from
your Arduino board.
![Battery and holder](http://i.imgur.com/Qh3AblE.jpg)
![Battery inserted](http://i.imgur.com/LQMKJG8.jpg)
![Recording data](http://i.imgur.com/H9VTk92.jpg)

Now you can take the micro SD card out of your GPS Logger Shield, put it in an
adapter of some sort, plug that adapter into your computer, and open the GPX
file you have recorded in some sort of [GPX visualization software](http://www.gpsvisualizer.com/).
![SD converter](http://i.imgur.com/EPlMlSY.jpg)
![More SD converter](http://i.imgur.com/xwB4yUw.jpg)
![Into the computer](http://i.imgur.com/eROZaRi.jpg)
![Again, listen for a click](http://i.imgur.com/Gzp8oLM.jpg)

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

Users who feel confident in their ability to edit the code of this project can
try to use an [Adafruit Ultimate GPS Shield](https://www.adafruit.com/product/1272)
instead of the SparkFun GPS Logger shield. That shield is claimed to have a lower
battery draw than other similar shields (which as far as I can tell is basically
just the SparkFun one). A future update of the Bodgecycle computer may even be based
on that shield depending on how this project goes.

There is a very low chance that when you unplug the battery from your
Bodgecycle Computer that you will interrupt the writing of data. You don't need
to worry about this too much. Your Bodgecycle Computer logs data to the SD card
once a second. It has the ability to perform 16 million actions in a second. I
estimate the odds at interrupting your Bodgecycle Computer from recording data
is about 3:160,000 against. In other words you have a .002% chance of doing
that. You shouldn't worry about it too much, but it can happen.

The goal of the Bodgecycle Computer project is to create something that can
create data that can be uploaded and stored on the website [Strava](strava.com). I don't know
right now if that will work. If you are interested in building a Bodgecycle
Computer and testing this functionality, I would be very happy.


# Bodgecycle Computer
The bodged together bicycle computer for hackers.
![A picture of my Bodgecycle Computer](http://i.imgur.com/aNQw7sG.jpg)

In order to use Bodgecycle Computer you will need the following components:
1. An [Arduino Uno](https://www.arduino.cc/en/Main/arduinoBoardUno) [compatible board](https://www.sainsmart.com/arduino/control-boards/sainsmart-uno-r3-atmega328-au-development-board-compatible-with-arduino-uno-r3.html)
  * Just as a heads up, I have recommendations about where and who from to get
your Arduino compatible board
  * You can buy official Arduino boards, but as of June 12th, 2017, I no longer
recommend them
  * Discussion about why I no longer recommend them are included in the
recommendations below
2. A USB cable compatible with your chosen Arduino compatible board
3. A [SparkFun GPS Logger Shield](https://www.sparkfun.com/products/13750)
4. An [Arduino stackable header set](https://www.sparkfun.com/products/11417)
5. A [12mm coin cell battery](https://www.sparkfun.com/products/337)
6. A [micro SD card](https://www.amazon.com/SANDISK-Micro-SDHC-Memory-SDSDQM-004G/dp/B001C0DJL4/ref=sr_1_2?s=pc&ie=UTF8&qid=1492750170&sr=1-2&keywords=sandisk+4gb+microsdhc+memory+card)
7. A [9v battery](https://www.amazon.com/AmazonBasics-Everyday-Alkaline-Batteries-8-Pack/dp/B00MH4QM1S/ref=sr_1_2_s_it?s=hpc&srs=2528919011&ie=UTF8&qid=1492750284&sr=1-2)
  * I have a few recommendations based on my experience with this project
  * These recommendations come from [wisebread](http://www.wisebread.com/the-5-best-9-volt-batteries)
    * AmazonBasics: Cheap. You can replace these a bunch
    * Energizer Advanced Lithium: Long battery life.
    * Duracell Procell: reliable and predictable. (These are now my preferred)
    * EBL High Volume: Rechargable. So that's fun.
    * Duracell Coppertop: Yup.
8. A [9v battery holder](https://www.adafruit.com/product/67)
9. A [sandwich bag](https://www.amazon.com/Glad-Food-Storage-Snack-Zipper/dp/B00ZKUCFUS/ref=sr_1_4_s_it?ie=UTF8&qid=1492750504&sr=1-4)
for wet rides or some sort of [butter tub](https://www.landolakes.com/products/butter/tubs/butter-with-canola-oil/)

I sourced all of these parts except for the sandwich bag from
[SparkFun](https://www.sparkfun.com/). The sandwich bag I got at a
[Food Lion](https://www.foodlion.com/). When I use a butter tub instead of a
sandwich bag, I use an old butter tub that I probably also got at a Food Lion,
though it might have been a Kroger, or even a Wades. Also the first 9v battery
I had went dead. For a while I used one by JobSmart which is the house brand of
[Tractor Supply](https://www.tractorsupply.com/).

These days I am using a Duracell Procell because it can operate under
vibrations better than previous batteries I used. Just as a heads up, your
bicycle computer is going to get vibrated. The reason for this is that it is on
a bicycle. Philosophical discussion of where to source things to come later.
The total cost of the parts I used was about \$100. Some of the parts I used
were unnecessary. The parts that are listed here cost about \$91.20. I also
used an Arduino Uno, which is perhaps not
[the cheapest Arduino Uno compatible board](http://www.electrodragon.com/product/arduino-compatible-visduino-uno-r3/).
A person using a SparkFun [RedBoard](https://www.sparkfun.com/products/13975)
and a minimum of parts could probably build a Bodgecycle Computer for $86.20
buying from SparkFun.

Users comfortable with system voltage could likely shave a further $5-8 off the
cost of this build by using an Arduino Pro,
[Diavolino](http://shop.evilmadscientist.com/productsmenu/180), or
[Canaduino](https://universal-solder.com/product/canaduino-uno-bone-basic-alternative-arduino-uno-r3-atmega328p-pu/).
Changing boards however is not guaranteed to have same results of the reference
Bodgecycle Computer built by Travis Rigg. Users choosing to use a different
board will also have to find their own way to power their board. Users choosing
to use a different board will also be required to know how to upload code to
their board of choice.

It is worth noting that I have done a little bit of testing with a Diavolino.
It didn't work for me, but all I did was plug in the shield, see that it didn't
work, and then added this statement to this readme file. It's possible that
someone less lazy than me who was dedicated to making it work with a Diavolino
could do that.

Bottom line, if you want to use a different board, feel free to do so, but
don't think it's my responsibility to bail you out, or to accept your fixes to
your problems into the Bodgecycle Computer codebase via a pull request. If you
create a pull request that doesn't work with the Arduino Uno R3, I'm not going
to merge it. If you create a pull request that works with your board and it
still works with the Arduino Uno R3, I will probably accept this change. If
someone creates a pull request that I merge that breaks another board I don't
care about, you're going to be sorta on your own.

Users who are satisfied with the first version of the Bodgecycle Computer can
also save some money by getting
[regular headers](https://www.sparkfun.com/products/116) instead of stacking
headers. This is not recommended however because future updates may require
more shields than just a GPS logger shield.

A better way to save some money building this project that could still be
expected to work reliably would be to purchase a smaller and cheaper micro SD
card. The one I have linked in the parts list above is smaller and cheaper than
the one I bought from SparkFun. It should be satisfactory enough.

Users should also feel free to purchase parts from their choice of retailer. I
used SparkFun because their website was easier for me to navigate than Adafruit
and I wanted to buy everything from one place. SparkFun's miniature version of
the GPS Logger Shield was also a big boon. I also, for personal reasons, did
want to buy products that supported the developers of the Arduino boards.
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

### On Arduino Uno compatible boards
I used an Arduino Uno when I built the first (and as far as I know only)
Bodgecycle Computer. At the time this made sense because it was easy to acquire
and I wanted to support the continued development of Arduino boards. The
Arduino organization has since gone through leadership changes that users
should be wary of. I recommend using a SparkFun RedBoard. There are other
cheaper boards, but the RedBoard helps SparkFun develop new boards.

Other alternatives incude:
* [Canaduino Uno](https://universal-solder.com/product/canaduino-uno-bone-basic-diy-arduino-uno/)
* [Sanjay Technologies ST1](https://www.indiamart.com/proddetail/st1-8348862762.html)
* [SainSmart Uno](https://www.sainsmart.com/sainsmart-uno-r3-atmega328-au-development-board-compatible-with-arduino-uno-r3.html)
* [CT Uno](https://www.cytron.com.my/p-ct-uno)
* [Freetronics Eleven](https://www.freetronics.com.au/products/eleven)
* [Alorium XLR8](http://www.aloriumtech.com/xlr8/)
* [Wholesale from China](https://www.aliexpress.com/item/high-quality-One-set-UNO-R3-CH340G-MEGA328P-for-Arduino-UNO-R3-NO-USB-CABLE/32680845470.html)

One note that I can share is that buying wholesale from China may require
burning a new bootloader onto the chip that comes installed on your board. This
isn't difficult if you already have an Arduino compatible board. If you don't,
it might be really frustrating.

An added bonus of the recommended RedBoard is that there are no through hole
componenets that might accidentally be shorted in a jersey pocket containing
something like a bicycle lock key. Not that I ever shorted anything by putting
my computer in a jersey pocket with a bicycle lock key. Just be aware that
doing that will likely cause a short curcuit which will reset the Arduino.

## Assembly
This guide will assume that the user is familiar with
[soldering](http://www.sciencebuddies.org/science-fair-projects/project_ideas/Elec_primer-solder.shtml)
and [Arduino assembly](https://learn.sparkfun.com/tutorials/arduino-shields).
There are many guides available online for how to develop these skills.
Attempting to produce a new guide or to replicate one of the existing guides
would likely not introduce anything useful to the experience of using the
Bodgecycle Computer. If anything is unclear about how to proceed, please open
an issue on GitHub.

1. Solder your stackable header set onto the SparkFun GPS Logger Shield.
![Solder your board](http://i.imgur.com/CCHxAFO.jpg)
2. Insert the GPS Logger Shield into your Arduino Uno compatible board.
![Line up all your pins](http://i.imgur.com/YPslNxY.jpg)
![Push down](http://i.imgur.com/GaE2MUe.jpg)
3. Insert your coin cell battery into the Arduino Uno
![Make sure the positive terminal is facing up](http://i.imgur.com/X0OpjMq.jpg)
  * Make sure the positive terminal is facing up
![Push it into the holder](http://i.imgur.com/z5CwGGA.jpg)

## Installation
This guide will assume that the user is familiar with the
[Arduino](https://www.arduino.cc/) environment. There are many
[guides available online for how to interact with this environment](https://www.arduino.cc/en/Guide/HomePage).
Attempting to produce a new guide or to replicate one of the existing guides
would likely not introduce anything useful to the experience of using the
Bodgecycle Computer. If anything is unclear about how to proceed, please open
an issue on GitHub.

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Open bodgecycle.ino in your IDE
3. Download and install
[TinyGPS++](http://arduiniana.org/libraries/tinygpsplus/)
  * Follow the installation directions provided by Mikal Heart on his website,
  Arduiniana
  * Doing this step has been different on different computers, so I can't give
  better advice than this
4. Plug your Arduino into your computer
5. Make sure to select Arduino/Genuino Uno as the type of board you're using
![Arduino/Genuino Uno](http://i.imgur.com/qLa8NFZ.jpg)
6. Make sure that the serial port your Arduino is connected to is selected
![Serial port selection](http://i.imgur.com/gwHw4W7.png)
7. Upload your code to the Arduino
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
file you have recorded in some sort of
[GPX visualization software](http://www.gpsvisualizer.com/).
![SD converter](http://i.imgur.com/EPlMlSY.jpg)
![More SD converter](http://i.imgur.com/xwB4yUw.jpg)
![Into the computer](http://i.imgur.com/eROZaRi.jpg)
![Again, listen for a click](http://i.imgur.com/Gzp8oLM.jpg)

## Contributing
You want to contribute? That's great! We would love to welcome you aboard. There are just a few things
you should know first. They are laid out in our
[Code of Conduct](https://github.com/riggtravis/BodgecycleComputer/blob/master/CODE_OF_CONDUCT.md) and
[Contributing Guide](https://github.com/riggtravis/BodgecycleComputer/blob/master/CONTRIBUTING.md).
Please go and read them before you do anything else.

## Limitations
However you take your Bodgecycle computer with you, be it in a sandwich bag, in
a butter tub, in an enclosure on your bike, or just loose in a jersey pocket,
please make cerain that there are no metal components that may accidentally
come in contact with the solders on the back of any through hole soldered
components. This is especially important to those using genuine Arduino Unos
and clones with through hole components.

A Bodgecycle Computer can only store 10 files at a time. Hopefully, this can
represent at least a couple of days worth of rides. For the creator of the
Bodgecycle Computer, this represents a little over a week's worth of bike
rides. Hypothetically, you could run out of space on your Bodgecycle Computer
after a very long series of rides, however, the battery will run out before
that becomes a problem. A Bodgecycle Computer with a low battery is a very
unstable thing. An easy indication that your Bodgecycle Computer is low on
battery is when there are more files for recorded rides than you would expect
and the files contain incomplete data.

Users who feel confident in their ability to edit the code of this project can
try to use an
[Adafruit Ultimate GPS Shield](https://www.adafruit.com/product/1272) instead
of the SparkFun GPS Logger shield. That shield is claimed to have a lower
battery draw than other similar shields (which as far as I can tell is
basically just the SparkFun one). A future update of the Bodgecycle computer
may even be based on that shield depending on how this project goes.

There is a very low chance that when you unplug the battery from your
Bodgecycle Computer that you will interrupt the writing of data. You don't need
to worry about this too much. Your Bodgecycle Computer logs data to the SD card
once a second. It has the ability to perform 16 million actions in a second. I
estimate the odds at interrupting your Bodgecycle Computer from recording data
is about 3:160,000 against. In other words you have a .002% chance of doing
that. You shouldn't worry about it too much, but it can happen.

The goal of the Bodgecycle Computer project is to create something that can
create data that can be uploaded and stored on the website
[Strava](strava.com). This can be done by putting your micro SD card into an SD
converter and then using the upload file interface on Strava.

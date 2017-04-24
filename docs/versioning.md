# Versioning
In order to keep track of what version of the Bodgecycle Computer you are using
and what it would take to use a different version of the Bodgecycle Computer,
you should be aware of what the version numbers mean.

Each of the numbers in a Bodgecycle Computer's version number represents
something about the Bodgecycle Computer. The version number of a Bodgecycle
Computer is in an X.X.X.X format. Often times, numbers are omitted. If a number
is omitted, you can assume that it is a zero. 1 is the same as 1.0 is the same
as 1.0.0 is the same as 1.0.0.0

Included in this document is a history of the versions that have come to pass
as well as the versions that are immediately planned. An immediately planned
version is one that while still ethereal, is already planned enough to know
what specifically creating that version will entail. Let's dig into these
numbers, shall we?

# The first number
The first number represents architecture. What processor was used to create
this Bodgecycle Computer?

## History/Plans
1. ATmega328
2. ATSAMD21G18

**NOTE:** All of the other future versions listed here are in the very
immediate future. The switch to an ATSAMD21G18 processor is not going to be
part of any of the next three releases to this project. The timeframe in which
changes in architecture will occur is much more of a mystery than other
changes. A change in architecture usually indicates that the previous of the
previous generation.

The reason I am sure that the architecture will be the ATSAMD21G18 is pricing,
software support, and specifications. I don't know when I'll be using all of
the ATmega328's SRAM, but I do know it will happen eventually. At this time I
believe it is unlikely that I will need an architecture with different
features rather than better specs, so the ATSAMD21G18 should be fine when
compared to something like the Intel Curie.

# The second number
The second number represents form factor. What specific development board was
used to create this Bodgecycle Computer? It should be noted that the board
listed is the board is the board that was used to create the Bodgecycle
Computer in question. Compatible boards should be perfectly fine. Listed after
each board are a few compatible boards that you should be able to trust.

Please note that compatible boards are not promised to be compatible. Use at
your own risk. Your mileage may vary. Please also keep in mind that this
project is available to you under an MIT/Expat License. Everything is provided
as is, without warranty, or any guarantee of usefulness.

## History/Plans
1. **1.0**: Arduino Uno
  * SparkFun Redboard
  * InVentor
  * Richduino
  * NerO
  * Eleven
  * Brasuino
  * DT-AVR Unoduino
  * ArduBoard
  * Visduino
2. **1.1**: Diavolino
  * Arduino Duemilanove
  * Arduino Pro
  * All boards from the **1.0** series
  * Cosmo Black Star
  * ARD128D2P
  * Seeeduino V2.21

# The third number
The third number represents what hardware needs to be attached to the
Bodgecycle Computer to make it work.

## History/Plans
1. **1.0.0**: Sparkfun GPS Logger Shield
2. **1.0.1**: Sparkfun LiPower Shield

# The fourth number
The fourth number represents software. Any Bodgecycle computer sharing the
first 3 numbers with a new x.x.x.X release can run the new release. For this
reason only the latest x.x.x.X code will be supported. Code for older
generations of architectures, form factors, and hardware will be left in the
repository for future users to utilize.

## History/Plans
1. **1.0.0.0**: Basic functionality and interoperability with popular services
2. **1.0.0.1**: Battery optimization

# Future Versions
As a general rule, only the next hardware release is concretely planned. A new
form factor release is also generally planned, but in a less concrete manner.
For example, the goal is to eventually take the 1.0.X.X series and port it to
the Arduino Pro Mini 328 3.3V 8MHz. Whether or not this happens in the future
will largely depend on what factors and limitations are discovered as the
1.0.X.X series is developed.

The next architecture is also usually planned in some manner, but it is even
less concrete than the next form factor release. Even if I have listed a future
architecture, you can assume that it will change and that you shouldn't plan a
purchase around it until it is listed in the milestones under issues in GitHub.

Most likely, once an architecture is no longer able to handle the expectations
of the Bodgecycle Computer project, a new form factor release of the previous
x.X.X.X series will be made before shifting all efforts to the new
architecture. For this reason an x.X release made just before an X release
can be considered to be the final version of that line. There is the
possibility that a new form factor will come about even after that, but it is
highly unlikely.

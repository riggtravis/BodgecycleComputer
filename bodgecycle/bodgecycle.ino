/******************************************************************************
 * Bodgecycle Computer v0.1
 * Track bike rides using Arduino
 * By Travis Rigg
 * April 15, 2017
 *
 * Based on:
 *  CSV_Logger_TinyGPSPlus.ino
 *  Log GPS data to a CSV file on a uSD card
 *  By Jim Lindblom @ SparkFun Electronics
 *  February 9, 2016
 *  https://github.com/sparkfun/GPS_Shield
 *
 * Inspired by:
 *  Geo Tracker
 *  A GPS Tracker for Android
 *  By Ilya Bogdanovich
 *  August 10, 2016
 *  https://geo-tracker.org
 *
 *  Arduino GPS Logger
 *  A functional logger and a good lesson about GPS modules, NMEA, and SD/FAT
 *    from Arduino
 *  By Mark Fickett
 *  Jan 4, 2016
 *  https://github.com/markfickett/gpslogger
 *
 *  OpenStreetMap
 *  A map built by a community of mappers that contribute and maintain data
 *    about roads, trails, cafes, and more
 *  By OpenStreetMap contributors
 *  www.openstreetmap.org
 *
 * Bodgecycle Computer uses an Arduino Uno to record GPS information to a uSD
 * card as a .gpx file. This .gpx file can then be uploaded to a website like
 * Strava. This means that cyclists with an interest in Arduino can quickly
 * have a working GPS unit that they can use instead of a smartphone. The
 * advantage of this is that their phone battery will be left in tact.
 *
 * Cyclists who already have a dedicated GPS head unit will likely be more
 * interested in continuing to use that rather than using the Bodgecycle
 * Computer. Cyclists who just want a GPS head unit should probably just buy
 * one. I spent $100 getting all the supplies together to build the Bodgecycle
 * Computer. For those same $100 I could have bought a Lezyne Macro or Micro.
 * Both have more functionality than the Bodgecycle Computer.
 *
 * Users who already own an arduino board might be especially interested. All
 * they will need to acquire will be a SparkFun GPS Logger Shield v2.0, a 9v
 * battery, a 9v battery hookup, a coin cell battery and a uSD card. Arduino
 * users will likely already own a good chunk of these supplies. So yeah. If
 * you've read all this, you should have an idea of whether or not Bodgecycle
 * computer is for you.
 *
 * Resources:
 *  TinyGPS++ Library  - https://github.com/mikalhart/TinyGPSPlus/releases
 *  SD Library (Built-in)
 *  SoftwareSerial Library (Built-in)
 *
 * Development/hardware environment specifics:
 *  Arduino IDE 1.8.2
 *  GPS Logger Shield v2.0 - Make sure the UART switch is set to SW-UART
 *  Arduino Uno R3
 *
 * TODO:
 *  Introduce battery monitoring
 *  Reduce power usage
 *    Find a way to see if bearing has changed
 */

#include <SPI.h>
#include <SD.h>
#include <TinyGPS++.h>

#define ARDUINO_USD_CS 10 // uSD card CS pin (pin 10: SparkFun GPS Shield)

/////////////////////////
// Log File Defintions //
/////////////////////////
// Keep in mind, the SD library has max file name lengths of 8.3 - 8 char
//  prefix, and a 3 char suffix.
// Our log files are called "rideX.csv, so "ride8.csv" is our max file.
#define LOG_FILE_PREFIX "ride" // Name of the log file.
#define MAX_LOG_FILES 8 // Number of log files that can be made
#define LOG_FILE_SUFFIX "gpx" // Suffix of the log file
char logFileName[10]; // Char string to store the log file name

//////////////////////
// Log Rate Control //
//////////////////////
#define DATA_AGGRESSIVENESS 10 // Controls how often data logging is scaled
unsigned int log_rate = 16384; // Start by logging every quarter of a minute
unsigned long lastLog = 0; // Global var to keep of last time we logged

/////////////////////////
// TinyGPS Definitions //
/////////////////////////
TinyGPSPlus tinyGPS; // tinyGPSPlus object to be used throughout
#define GPS_BAUD 9600 // GPS module's default baud rate
#define GPS_PRECISION 6 // How many decimals to store in latitude and longitude

/////////////////////////////////
// GPS Serial Port Definitions //
/////////////////////////////////
// If you're using an Arduino Uno, Mega, RedBoard, or any board that uses the
// 0/1 UART for programming/Serial monitor-ing, use SoftwareSerial:
#include <SoftwareSerial.h>
#define ARDUINO_GPS_RX 9 // GPS TX, Arduino RX pin
#define ARDUINO_GPS_TX 8 // GPS RX, Arduino TX pin
SoftwareSerial ssGPS(ARDUINO_GPS_TX, ARDUINO_GPS_RX); // Create a SoftwareSerial

// Set gpsPort to either ssGPS if using SoftwareSerial or Serial1 if using an
// Arduino with a dedicated hardware serial port
#define gpsPort ssGPS  // Alternatively, use Serial1 on the Leonardo

// Define the serial monitor port. On the Uno, Mega, and Leonardo this is
//  'Serial' on other boards this may be 'SerialUSB'
#define SerialMonitor Serial

///////////////////////
// BEARING VARIABLES //
///////////////////////
long int last_speed = 0;

void setup()
{
  SerialMonitor.begin(9600);
  gpsPort.begin(GPS_BAUD);

  SerialMonitor.println(F("\nSetting up."));
  // see if the card is present and can be initialized:
  if (!SD.begin(ARDUINO_USD_CS))
  {
    SerialMonitor.println(F("Error initializing."));
  }

  // Wait to start printing headers and such until there are enough satellites
  while (!tinyGPS.location.isUpdated())
  {
    // This code should make the gps tracker thrash less.
    if ((lastLog + log_rate) <= millis())
    {
      // Query the GPS unit
      getGPSData();

      SerialMonitor.print(F("Checking for satellites. Current count: "));
      SerialMonitor.println(tinyGPS.satellites.value());
    }
  }
  last_speed = tinyGPS.speed.kmph(); // Set last speed for later calculations
  log_rate = 1024; // Start logging about once a second
  updateFileName(); // Each time we start, create new file, increment the number
  printHeader(); // Print a header at the top of the new file
}

void loop()
{
  // It sure would be nice to have the log rate speed up once GPS is found.
  if ((lastLog + log_rate) <= millis())
  { // If it's been log_rate milliseconds since the last log:
    if (tinyGPS.location.isUpdated()) // If the GPS data is vaild
    {
      if (logGPSData()) // Log the GPS data
      {
        SerialMonitor.println(F("GPS logged.")); // Print a debug message
        lastLog = millis(); // Update the lastLog variable

        // Adjust the log rate based on the change in speed
        if ( // If the speed has changed by 5 kmph, reset the log rate
          last_speed - tinyGPS.speed.kmph() < DATA_AGGRESSIVENESS ||
          tinyGPS.speed.kmph() - last_speed < DATA_AGGRESSIVENESS)
        {
          log_rate = 1024;
        } else if (!(log_rate >= 8192)) {
          // At most wait about 8 seconds
          log_rate = log_rate * 2;
        }
      }
      else // If we failed to log GPS
      { // Print an error, don't update lastLog
        SerialMonitor.println(F("Failed to log data."));
      }
    }
    else // If GPS data isn't valid
    {
      // Print a debug message. Maybe we don't have enough satellites yet.
      SerialMonitor.print(F("No GPS data. Sats: "));
      SerialMonitor.println(tinyGPS.satellites.value());
    }
  }

  // If we're not logging, continue to "feed" the tinyGPS object:
  getGPSData();
}

void getGPSData()
{
  while (gpsPort.available())
    tinyGPS.encode(gpsPort.read());
}

byte logGPSData()
{
  File logFile = SD.open(logFileName, FILE_WRITE); // Open the log file

  SerialMonitor.println(F("Logging GPS"));

  if (logFile)
  { // Print longitude, latitude, altitude (in meters), date, and time
    // Scroll back 26 characters
    logFile.seek(logFile.size() - 26);

    logFile.print(F("\t\t<trkpt lat=\""));
    logFile.print(tinyGPS.location.lat(), GPS_PRECISION);
    logFile.print(F("\" lon=\""));
    logFile.print(tinyGPS.location.lng(), GPS_PRECISION);
    logFile.print(F("\"><ele>"));
    logFile.print(tinyGPS.altitude.meters(), 1);
    logFile.print(F("</ele>"));

    logFile.close();

    printTime();

    // Close the trkpt tag
    logFile = SD.open(logFileName, FILE_WRITE);

    if (logFile)
    {
      logFile.println(F("</trkpt>"));

      logFile.close();

      printFooter();
    }
    return 1; // Return success
  }
  return 0; // If we failed to open the file, return fail
}

// printHeader() - prints the start of our XML file
void printHeader()
{
  File logFile = SD.open(logFileName, FILE_WRITE); // Open the log file

  if (logFile)
  { // If the log file opened, print our column names to the file
    logFile.println(F("<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>"));

    // Print information about the file.
    logFile.println(F("<gpx version=\"1.1\" xmlns=\"http://www.topografix.com/GPX/1/1\" creator=\"BC by TR\">"));
    logFile.println(F("\t<metadata>"));

    // two different kinds of name tag; be more DRY
    logFile.println(F("\t\t<name>Ride</name>"));
    logFile.println(F("\t\t<author>"));
    logFile.println(F("\t\t\t<name>BC by TR</name>"));
    logFile.println(F("\t\t</author>"));

    // The header needs a valid time stamp in it. Get it from the GPS
    // Format the header to receive the timestamp
    logFile.print(F("\t\t"));
    logFile.close();

    // The first two time stamps provided by the GPS module are always wrong
    for(uint8_t i = 0; i < 2; i++)
    {
      getGPSData();
    }
    printTime();

    // Now we do the actual factual GPS tracking.
    logFile = SD.open(logFileName, FILE_WRITE);
    if(logFile) {
      logFile.println();
      logFile.println(F("\t</metadata>"));
      logFile.println(F("\t<trk><name>Ride</name><trkseg>"));
  
      // If I do this right, all of the tags will be closed.
  
      // Close the file.
      logFile.close();
      printFooter();
    }
  }
}

// Prints a time tag at the end of the file
void printTime()
{
  File logFile = SD.open(logFileName, FILE_WRITE); // Open the log file

  if (logFile)
  {
    // This section of code isn't very DRY. Do better.
    logFile.print(F("<time>"));
    logFile.print(tinyGPS.date.year());
    logFile.print(F("-"));

    if(tinyGPS.date.month() < 10)
    {
      logFile.print(F("0"));
    }
    logFile.print(tinyGPS.date.month());

    logFile.print(F("-"));

    if(tinyGPS.date.day() < 10)
    {
      logFile.print(F("0"));
    }
    logFile.print(tinyGPS.date.day());

    logFile.print(F("T"));

    if(tinyGPS.time.hour() < 10)
    {
      logFile.print(F("0"));
    }
    logFile.print(tinyGPS.time.hour());

    logFile.print(F(":"));

    if(tinyGPS.time.minute() < 10)
    {
      logFile.print(F("0"));
    }
    logFile.print(tinyGPS.time.minute());

    logFile.print(F(":"));

    if(tinyGPS.time.second() < 10)
    {
      logFile.print(F("0"));
    }
    logFile.print(tinyGPS.time.second());

    logFile.print(F("."));
    logFile.print(tinyGPS.time.centisecond());
    logFile.print(F("Z</time>"));

    logFile.close();
  }
}

// Puts closing tags at the end of the file.
void printFooter()
{
  File logFile = SD.open(logFileName, FILE_WRITE); // Open the log file
  if (logFile)
  { // Print the ending of the file.
    logFile.println(F("\t</trkseg></trk>"));
    logFile.println(F("</gpx>"));

    // Close the file.
    logFile.close();
  }
}

// updateFileName() - Looks through the log files already present on a card,
// and creates a new file with an incremented file index.
void updateFileName()
{
  SerialMonitor.println(F("Creating file"));

  uint8_t i = 0;
  for (; i < MAX_LOG_FILES; i++)
  {
    SerialMonitor.println(F("Searching for file"));
    memset(logFileName, 0, strlen(logFileName)); // Clear logFileName string
    // Set logFileName to "gpslogXX.csv":
    sprintf(logFileName, "%s%d.%s", LOG_FILE_PREFIX, i, LOG_FILE_SUFFIX);
    if (!SD.exists(logFileName)) // If a file doesn't exist
    {
      break; // Break out of this loop. We found our index
    }
    else // Otherwise:
    {
      SerialMonitor.print(logFileName);
      SerialMonitor.println(F(" exists")); // Print a debug statement
    }
  }
  SerialMonitor.print(F("File name: "));
  SerialMonitor.println(logFileName); // Debug print the file name
}

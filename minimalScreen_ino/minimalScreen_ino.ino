#include <Time.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using SPI to communicate
4 or 5 pins are required to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/



//11,12,10,9,13

// arduino nano pins
#define OLED_DC 9
#define OLED_CS 12
#define OLED_CLK 13
#define OLED_MOSI 11
#define OLED_RESET 10


Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

bool inverted = false;



SoftwareSerial mySerial(5, 4);

//Adafruit_GPS GPS(&mySerial);

// Set GPSECHO to 'false' to turn off echoing the GPS data to the Serial console
// Set to 'true' if you want to debug and listen to the raw GPS sentences. 
#define GPSECHO  true

// this keeps track of whether we're using the interrupt
// off by default!
boolean usingInterrupt = false;
void useInterrupt(boolean); // Func prototype keeps Arduino 0023 happy


void setup()   {                
  Serial.begin(9600);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("MINIMAL");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("application started");
  display.display();
  delay(2000);


}


void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("time since app start");
    display.println();
  
  display.setTextSize(3);
  display.println(digitalClockDisplay());
  display.display();
  delay(500);
}

String digitalClockDisplay(){
  String display_text = "" + printDigits(minute()) + ":" + printDigits(second());//printDigits(hour()) +
  return(display_text);
}

String printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  String val = "";
  if(digits < 10)
    val = val + '0';
  val = val + digits;
  
  return(val);
}

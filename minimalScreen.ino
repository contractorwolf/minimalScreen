

#include <Time.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



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


void setup()   { 

  //use this for the serial gps in future projects if necesarry  
  Serial.begin(9600);
  Serial.write("MINIMAL application started");
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  
  // init done
  display.clearDisplay();
  
  //splash text
  WriteTextToDisplay(12, 0, 2, "MINI OLED");
  WriteTextToDisplay(4, 30, 1, "application started");
  
  display.display();
  
  
//SCREEN UPDATE end*************************

  //wait to show splash text
  delay(2000);
}


void loop() {




//SCREEN UPDATE START*************************
  display.clearDisplay();
  
  WriteTextToDisplay(0, 0, 1, "time since app start");
  WriteTextToDisplay(0, 15, 2, "3585.4412N");
  WriteTextToDisplay(15, 40, 3, digitalClockDisplay());
  
  display.display();
//SCREEN UPDATE END*************************
  
  
  //delay between screen upda
  delay(200);
}

void WriteTextToDisplay(int x, int y, int fontsize, String messagetext){
  display.setCursor(x,y);
  display.setTextSize(fontsize);
  display.setTextColor(WHITE);
  display.print(messagetext);
}

String digitalClockDisplay(){
  String display_text = "" + printDigits(minute()) + ":" + printDigits(second());
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

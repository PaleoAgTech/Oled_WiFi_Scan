#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "ESP8266WiFi.h"

#define OLED_RESET D5

Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 
  display.setTextColor(WHITE);
  delay(2000);
   display.setTextSize(1);

}

void loop() {


  int n = WiFi.scanNetworks();
  if (n == 0) 
  {
    // here will go stuff when there is no WIFI networks  
  } 
  else 
  { 
    for (int i = 0; i < n; ++i) {
      display.clearDisplay();
      display.setCursor(0, 0); 
      display.println(WiFi.SSID(i));
      display.setCursor(45, 8);  
      display.println("("+String(WiFi.channel(i))+")");;
      display.setCursor(45, 19);  
      display.println(String(WiFi.RSSI(i)));
      display.setCursor(35, 30);  
      display.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? "open" : "password");
      
      signalBar(25,35,WiFi.RSSI(i));   // signalBar(x,y, RSSI data);
      
      display.display();
      delay(2000);
      
    }
  }

  delay(1000);
}

// THIS PART WILL CREATE WIFI SIGNAL BARS;

void loadingBar(int x, int y, int data)
{
  for(int i=0;i<data;i++)
  {
  display.drawPixel(x+i, y, WHITE);
  display.drawPixel(x+i, y+1, WHITE);
  display.drawPixel(x+i, y+2, WHITE);
  }
}

void signalBar(int x, int y, int data)
{
  if(abs(data)<=90)
  {
  for(int i = 0;i<8;i++)
  {
    display.drawPixel(x+i, y+20, WHITE);
    display.drawPixel(x+i, y+19, WHITE);
  } 
  }
  
  if(abs(data)<=80)
  {
  for(int i = 0;i<8;i++)
  {
    display.drawPixel(x+i+16, y+20, WHITE);
    display.drawPixel(x+i+16, y+19, WHITE);
    display.drawPixel(x+i+16, y+18, WHITE);
    display.drawPixel(x+i+16, y+17, WHITE);
  }
  }
  
  if(abs(data)<=70)
  {
    for(int i = 0;i<8;i++)
  {
      display.drawPixel(x+i+32, y+20, WHITE);
    display.drawPixel(x+i+32, y+19, WHITE);
    display.drawPixel(x+i+32, y+18, WHITE);
    display.drawPixel(x+i+32, y+17, WHITE);
    display.drawPixel(x+i+32, y+16, WHITE);
    display.drawPixel(x+i+32, y+15, WHITE);
   }
  }
  
  if(abs(data)<=67)
   {
   for(int i = 0;i<8;i++)
   {
    display.drawPixel(x+i+48, y+20, WHITE);
    display.drawPixel(x+i+48, y+19, WHITE);
    display.drawPixel(x+i+48, y+18, WHITE);
    display.drawPixel(x+i+48, y+17, WHITE);
    display.drawPixel(x+i+48, y+16, WHITE);
    display.drawPixel(x+i+48, y+15, WHITE);
    display.drawPixel(x+i+48, y+14, WHITE);
    display.drawPixel(x+i+48, y+13, WHITE);
    }
   }
  if(abs(data) <=30)
   {
     for(int i = 0;i<8;i++)
     {
       display.drawPixel(x+i+64, y+20, WHITE);
       display.drawPixel(x+i+64, y+19, WHITE);
      display.drawPixel(x+i+64, y+18, WHITE);
      display.drawPixel(x+i+64, y+17, WHITE);
      display.drawPixel(x+i+64, y+16, WHITE);
      display.drawPixel(x+i+64, y+15, WHITE);
      display.drawPixel(x+i+64, y+14, WHITE);
      display.drawPixel(x+i+64, y+13, WHITE);
      display.drawPixel(x+i+64, y+12, WHITE);
      display.drawPixel(x+i+64, y+11, WHITE);
       }
    }
}

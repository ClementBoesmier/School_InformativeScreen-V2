#include <SPI.h>
#include <Adafruit_GFX.h>
#include <DS1307.h>
#include <RGBmatrixPanel.h>
#include <Wire.h>

#define OE 9
#define LAT 10
#define CLK 11
#define A A0
#define B A1
#define C A2
#define D A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

DS1307 rtc;

uint8_t sec, min, hour, day, month;
uint16_t year;


String bufferTrame("");
int minEx=0;
int switchCase = 6;
int timeColour[99][5];
String color = "";
int set = 0;
int saveTimeT[1];
String info = "";
int type = 0;


void setup() {
  Serial.begin(9600);
  rtc.start();
  matrix.begin();
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  minEx = min;
  //rtc.set(0, 0, 10, 24, 12, 2014);
}

void loop() {
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  RTCprint();
  lectureTrame();
  decodeTrameType();
  decodeTrameColor();
  decodeTrameAnimate();
  decodeTrameSet();
  decodeTrameSetInfo();

  bufferTrame = "";
  switchCase = 6;
}

#include <Adafruit_NeoPixel.h>
#define PIN 6 // номер порта к которому подключен модуль
#define count_led 64// количество светодиодов 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(count_led, PIN, NEO_GRB + NEO_KHZ800); //first number change does distance between colors

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

int mas[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
};


void loop() {
  int arr[64];

  for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
          arr[8 * i + j] = mas[i][j];
      }
  }
  
  for (int i = 0; i < 64; i++) {
      if (arr[i] == 1) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      }
  }
  pixels.show();
  delay(1000);
}
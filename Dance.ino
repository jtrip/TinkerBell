#include <Adafruit_NeoPixel.h>

// Using three separate data pins to create three distinct objects
#define PIN1 6
#define PIN2 9
#define PIN3 10

// Could probably do the same thing using one but I found it easier to expirament this way
Adafruit_NeoPixel LED1 = Adafruit_NeoPixel(1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LED2 = Adafruit_NeoPixel(1, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel LED3 = Adafruit_NeoPixel(1, PIN3, NEO_GRB + NEO_KHZ800);

// Setup sets the LEDs to Off with begin() and makes that what they show()
void setup() {
  LED1.begin();
  LED1.show();
  LED2.begin();
  LED2.show(); 
  LED3.begin();
  LED3.show(); 

}

// In typical easy Arduino fashion loop() is the main body, all other functions are called within here 
void loop() {
  LED2.setPixelColor(0,LED2.Color(255,215,0));
  LED2.show();
  while (true) {
    
    basicFlutter();
    
    LED1.setPixelColor(0,LED2.Color(255,215,0));
    LED3.setPixelColor(0,LED2.Color(255,215,0));
    LED1.show();
    LED3.show();
    
    delay(1000);
    
    fadeLED2();
    breathLED2();
    breathLED2();
    breathLED2();
  
    LED2.setPixelColor(0,LED2.Color(255,215,0));
    LED2.show();
    LED1.setPixelColor(0,0,0,0);
    LED3.setPixelColor(0,0,0,0);
    LED1.show();
    LED3.show();
    
    breathLED2solo();
    breathLED2solo();
    breathLED2solo();
    rampLED2();
    
    delay(3000);
  
    breathLED3();
    breathLED1();
    breathLED3();
    breathLED1();
    delay(3000);
    breathBoth();
    breathBoth();
    breathBoth();
    delay(3000);
    fadeLED1();
    fadeLED3();
    fadeLED1();
    fadeLED3();
  }
}

void basicFlutter() {
  for (int i=1; i < 80; i++) {
    LED1.setPixelColor(0,LED1.Color(155,115,0));
    LED1.show();
    LED3.setPixelColor(0,LED3.Color(155,115,0));
    LED3.show();
    delay(43);
    LED1.setPixelColor(0,0,0,0);
    LED1.show();
    delay(27);
    LED3.setPixelColor(0,0,0,0);
    LED3.show();
    delay(23);
  }
}

void fadeLED1() {
  for (int i = 255; i > 0; i=i-2) {
    LED1.setPixelColor(0, LED1.Color(i,i,i));
    LED1.show();
    delay(10);
  }
}

void fadeLED2() {
  for (int i = 255; i > 0; i--) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
}

void fadeLED3() {
  for (int i = 255; i > 0; i=i-2) {
    LED3.setPixelColor(0, LED3.Color(i,i,i));
    LED3.show();
    delay(10);
  }
}

void rampLED2() {
  for (int i = 0; i < 255; i++) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
}



void breathLED3() {
 for (int i = 0; i < 255 ; i++) {
    LED3.setPixelColor(0, LED3.Color(i,i,0));
    LED3.show();
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    LED3.setPixelColor(0, LED3.Color(i,i,0));
    LED3.show();
    delay(10);
  }
}

void breathLED1() {
 for (int i; i < 255 ; i++) {
    LED1.setPixelColor(0, LED1.Color(i,i,0));
    LED1.show();
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    LED1.setPixelColor(0, LED1.Color(i,i,0));
    LED1.show();
    delay(10);
  }
}

void breathBoth() {
  for (int i; i < 225 ; i++) {
    LED1.setPixelColor(0, LED1.Color(i+15,i,0));
    LED3.setPixelColor(0, LED1.Color(i+15,i,0));
    LED1.show();
    LED3.show();
    delay(10);
  }
  for (int i = 225; i > 0; i--) {
    LED1.setPixelColor(0, LED1.Color(i+15,i,0));
    LED3.setPixelColor(0, LED1.Color(i+15,i,0));
    LED1.show();
    LED3.show();
    delay(10);
  }
}

void breathLED2() {
  LED1.setPixelColor(0,LED1.Color(255,215,0));
  LED3.setPixelColor(0,LED3.Color(255,215,0));
  LED1.show();
  LED3.show();
  for (int i; i < 255 ; i++) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
}
    
void breathLED2solo() {
  for (int i; i < 255 ; i++) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
  for (int i = 255; i > 0; i--) {
    LED2.setPixelColor(0, LED2.Color(i,i,0));
    LED2.show();
    delay(10);
  }
}
    

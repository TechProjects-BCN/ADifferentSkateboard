#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        6
#define NUMPIXELS 15
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
bool flag = false;
int dist(0);
int  R(0);
int  G(0);
int  B(0);
int i = 0;
int FACTOR = 3;
#include <afstandssensor.h>

// Distance Sensor(triggerPin, echoPin);
AfstandsSensor afstandssensor(13, 12);  // Starter distance detector in pins 13 and 12.

void setup() {
  Serial.begin(9600);
  pixels.begin();   
}
void loop() {
  //pixels.clear(); // Set all pixel colors to 'off'
  dist = afstandssensor.afstandCM();
  Serial.println(dist);

  if ((dist <= 500 and dist > 400)){ //12
      R = 0;
      G = 0; 
      B = 255;
      }

  else if ((dist > 330 && dist <= 400 )){ //2 verd
      R = 0;
      G = 255; 
      B = 0;

      }
  else if ((dist <= 330 and dist > 300)){ //3 yellow
      R = 255;
      G = 255; 
      B = 0;

      }
  else if ((dist <= 300 and dist > 270)){ //4 light green
      R = 128;
      G = 255; 
      B = 0;

      }
  else if ((dist <= 270 and dist > 240)){ //5 green
      R = 0;
      G = 255; 
      B = 0;

      }
  else if ((dist <= 240 and dist > 210)){ //6 turquoise
      R = 0;
      G = 255; 
      B = 128;
  }

 else if ((dist <= 210 and dist > 180)){ //7
      R = 0;
      G = 255; 
      B = 255;
      }

 else if ((dist <= 180 and dist > 150)){ //8
      R = 0;
      G = 128; 
      B = 255;
      }     

 else if ((dist <= 150 and dist > 120)){ //9
      R = 0;
      G = 0; 
      B = 255;
      }

 else if ((dist <= 120 and dist > 90)){ //10
      R = 127;
      G = 0; 
      B = 255;
      }

 else if ((dist <= 90 and dist > 60)){ //11
      R = 255;
      G = 0; 
      B = 255;
      }

 else if ((dist <= 60 and dist > 30)){ //12
      R = 255;
      G = 0; 
      B = 127;
      }

  else if ((dist <= 30 and dist> 15)){ //1 red
      R = 127;
      G = 127; 
      B = 127;
  }
 else { //13
      R = 255;
      G = 0; 
      B = 0;
      }

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(R/FACTOR, G/FACTOR, B/FACTOR));

    pixels.show();   // Send the updated pixel colors to the hardware.

  }
  delay (DELAYVAL);
}
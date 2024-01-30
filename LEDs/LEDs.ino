#include <Adafruit_NeoPixel.h>
#define PIN        6
#define NUMPIXELS 15
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int vel(0);
int  R(0);
int  G(0);
int  B(0);
int i = 0;
int FACTOR = 3;

void setup() {
  Serial.begin(9600);
  pixels.begin();   
}
void loop() {
  if ((vel <= 500 and vel > 400)){ //12
      R = 0;
      G = 0; 
      B = 255;
      }

  else if ((vel > 330 && vel <= 400 )){ //2 verd
      R = 0;
      G = 255; 
      B = 0;

      }
  else if ((vel <= 330 and vel > 300)){ //3 yellow
      R = 255;
      G = 255; 
      B = 0;

      }
  else if ((vel <= 300 and vel > 270)){ //4 light green
      R = 128;
      G = 255; 
      B = 0;

      }
  else if ((vel <= 270 and vel > 240)){ //5 green
      R = 0;
      G = 255; 
      B = 0;

      }
  else if ((vel <= 240 and vel > 210)){ //6 turquoise
      R = 0;
      G = 255; 
      B = 128;
  }

 else if ((vel <= 210 and vel > 180)){ //7
      R = 0;
      G = 255; 
      B = 255;
      }

 else if ((vel <= 180 and vel > 150)){ //8
      R = 0;
      G = 128; 
      B = 255;
      }     

 else if ((vel <= 150 and vel > 120)){ //9
      R = 0;
      G = 0; 
      B = 255;
      }

 else if ((vel <= 120 and vel > 90)){ //10
      R = 127;
      G = 0; 
      B = 255;
      }

 else if ((vel <= 90 and vel > 60)){ //11
      R = 255;
      G = 0; 
      B = 255;
      }

 else if ((vel <= 60 and vel > 30)){ //12
      R = 255;
      G = 0; 
      B = 127;
      }

  else if ((vel <= 30 and vel> 15)){ //1 red
      R = 127;
      G = 127; 
      B = 127;
  }
 else { //13
      R = 255;
      G = 0; 
      B = 0;
      }

  for(int i=0; i<NUMPIXELS; i++) {// For each pixel...
    pixels.setPixelColor(i, pixels.Color(R/FACTOR, G/FACTOR, B/FACTOR)); 
    pixels.show();
  }
  delay (DELAYVAL);

}
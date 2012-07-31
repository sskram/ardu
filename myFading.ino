/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 mod keerthi july 2012

 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */


const int fadePin = 9,    // LED connected to digital pin 9
  blinkPin = 13;
  
int dt = 30,
  dv = 5;

const int minV = 1,
  maxV = 255;

int nextval() {
  static int lastVal = 120;

  if(lastVal>=maxV || lastVal<=minV) {
    dv*=-1; // change direction
    digitalWrite(blinkPin, toggle());
  }
  lastVal += dv;
  return lastVal;
}

int toggle() {
  static int blinkState = LOW;
  blinkState = blinkState==LOW? HIGH: LOW;
  return blinkState;
}

void setup()  { 
  pinMode(blinkPin, OUTPUT);
  pinMode(fadePin, OUTPUT); 
} 

void loop()  {
  static unsigned long lastTick = 0; 
  
  unsigned long now = millis();
  if(now > lastTick + dt) {
    analogWrite(fadePin, nextval());
    lastTick = now;
  } 
}



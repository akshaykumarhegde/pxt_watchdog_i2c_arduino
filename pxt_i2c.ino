// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

const int ledPin =  LED_BUILTIN;
unsigned long previousMillis = 0;        // 
// constants won't change:
const long interval = 100000; // interval at which to blink (milliseconds)
 int x =0;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600); // start serial for output
    pinMode(ledPin, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
    unsigned long currentMillis = millis();
if(x == 10){    
  previousMillis = currentMillis;
  Wire.flush();
  Serial.println(x);
   Wire.flush();
   x=0;
  return;} //check for gpio reset timer if detected

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    x=0;
    Wire.flush();
        digitalWrite(ledPin,HIGH);
         delay(3000);
          digitalWrite(ledPin,LOW);
    }
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    //Serial.print(c);         // print the character
  }
  x = Wire.read();    // receive byte as an integer
  //Serial.println(x);         // print the integer
}

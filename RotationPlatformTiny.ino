
/*
 * Stepper Motor Controller using ATTiny85
 *  
 * This sketch commands a stepper motor (28BYJ-48 + ULN2003 Driver) in Full-Step mode using only 2 wires to do it 
 * 
 */


  
#include "StepperController.hpp"

byte motorPin1 = 0;  //Stepper motor pin 1
byte motorPin2 = 1; //Stepper motor pin 2
int w1, w2; //variables to command motor windings
byte butPin = 2;  //Tiny A2
short int clickDir = 0;  //variable to read A2 input
byte spdPot = 3;  //Tiny A3
unsigned long clickSpd = 0; //variable to read A3 input
StepperController sc;

void setup() {
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
}

void loop() {

  clickSpd = analogRead(spdPot);     // read the value from direction button 
  clickDir = analogRead(butPin);     // read the value from the potentiometer
  
  sc.move((clickSpd*255/1023),(int)(1.0/511.0*clickDir+0.5)-1 ,millis());  // Set speed using the value from the potenciometer, direction from Dir Button and time using current time
  sc.getState(&w1, &w2); // Get the step sequence to the stepper motor

  // Sends the step to stepper motor pins
  digitalWrite(motorPin1, w1);
  digitalWrite(motorPin2, w2);

}

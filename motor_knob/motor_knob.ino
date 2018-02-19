/*
Adafruit Arduino - Lesson 14. Knob
*/
//This code is once you add a pot so that you can control the position of the servo by turning the knob
#include <Servo.h> 

int potPin = 0;  
int servoPin = 9;
Servo servo; 
 
void setup() 
{ 
  servo.attach(servoPin);  
} 
 
void loop() 
{ 
  int reading = analogRead(potPin);     // 0 to 1023
  int angle = reading / 6;              // 0 to 180-ish
  servo.write(angle);  
 
} 

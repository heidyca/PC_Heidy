/*
Adafruit Arduino - Lesson 14. Sweep
*/
//THIS CODE MAKES THE SERVO TURN IN ONE DIRECTION AND THEN BACK THE OTHER WAY
#include <Servo.h2> 

int servoPin = 9;
 
Servo servo;  
 
int angle = 0;   // servo position in degrees 
//for it to connect to processing?
int sensorPin = 0;
int val = 0;
 
void setup() 
{ 
  servo.attach(servoPin); //"servo" variable links to the pin that controls the servo based on this command?
Serial.begin(9600);
} 
 
 
void loop() 
{ 
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle);// the 'angle' variable is used to contain the degrees of the angle of the servo.
    //there are 2 for loop to increase the angle one way and then back the other way once it reaches 180 degrees.         
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
  
val = analogRead(sensorPin);
delay(100);
Serial.write(val);
  
} 

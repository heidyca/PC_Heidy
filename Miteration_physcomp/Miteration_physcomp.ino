//code referenced: KNOB, motor Sweep, and the serial write example from class, code from class github arduino sends char 
 
#include <Servo.h>

Servo servo; // create servo object to control a servo
Servo servo2;
Servo servo3;  

int knob = 0;  // analog pin used to connect the potentiometer
int val = 0;   // variable to read the value from the analog pin
int angle = 0; //referencing angle of knob

void setup() {
 Serial.begin(9600); // Start serial communication at 9600 bps
servo.attach(9);  // attaches the servo on pin 9 to the servo object
servo2.attach(10);
servo3.attach(11);
}

void loop() {
  val = analogRead(knob);            // reads the value of the potentiometer (value between 0 and 1023)
  angle = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
   if (angle > 150 ) {
    Serial.write('m'); // move motors, send m
   for (angle = 0; angle < 180; angle++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(angle);
    servo2.write(angle);
    servo3.write(angle);
    delay(10);                       // waits 20ms for the servo to reach the position
  }
for (angle = 180; angle > 0; angle--) { // goes from 180 degrees to 0 degrees
    servo.write(angle);              //
    servo2.write(angle);  
    servo3.write(angle);  
    delay(10);      
}
  servo.write(angle);                  // sets the servo position according to the scaled value
  servo2.write(angle);
  servo3.write(angle);
  delay(10);                           // waits for the servo to get there


  Serial.write(val); //write is to send to processing 
}
delay(10);    // Wait 100 milliseconds
}


//if the angle is less than 100 then have the motors go faster or 







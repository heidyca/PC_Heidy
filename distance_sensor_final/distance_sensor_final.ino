//http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
//ex from Blake's demo (Arduino to Touch)


int trigPin = 13; //distance sensor TRIG is connected to 13
int echoPin = 12; //distance sensor ECHO is connected to 12

int led1 = 11; //led 

void setup() {
  Serial.begin (9600); //match to TouchDesigner Serial in DAT 
  pinMode(trigPin, OUTPUT); //info leaving sensor
  pinMode(echoPin, INPUT); // info coming to sensor
  pinMode(led1, OUTPUT); // on/off

}

void loop() {
  //this code is from the above website
  long duration, distance;
  digitalWrite(trigPin, LOW);  
 delayMicroseconds(2); // from above website
  digitalWrite(trigPin, HIGH);
     
  delay(100); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // reads pulse (HIGH OR LOW) from 10 micro s. to 3 mins
  distance = (duration/2) / 29.1; // divide for smaller values
  if (distance < 100) {  // This is where the LED On/Off happens
  digitalWrite(led1,HIGH); // turn led on if the distance is less than 100 cm
//
}
  else {
    digitalWrite(led1,LOW);
    
  }
  if (distance >= 150 || distance <= 0){ //or
    Serial.println("200"); //printing 200 for the 1st face. over 150 = out of range = 200
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(300);
}

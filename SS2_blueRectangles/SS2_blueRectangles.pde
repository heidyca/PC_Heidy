/*
Reads values from serial port, written to the port by Arduino.
The size of an ellipse changes according to the serial values.
Must assign the correct port, see instructions below.
*/

import processing.serial.*; //imports Serial library from Processing
int i;

Serial myPort; // creates object from Serial class
int val; // creates variable for data coming from serial port


void setup() {
size(1500, 500);
background (0);
/*
We must tell Processing which port to read from.
Run the sketch and check your console to see the results of printArray(Serial.list());
and that is how you know the port to use.
On my Mac, it is port 2 and so I open Serial.list()[2].
*/

printArray(Serial.list()); // this line prints the port list to the console
String portName = Serial.list()[1]; // [] POST NUMBER 1 FOR HEIDYS MAC
myPort = new Serial(this, portName, 9600);
}

void draw(){
if ( myPort.available() > 0) { // If data is available,
val = myPort.read(); // read it and store it in val
}

//changes the color and size of rect based on how hard/soft you press on sensor
pushMatrix();
fill (10,val,val);
noStroke();
rectMode(CENTER);

 // use if statement to get the rectangle to start from the beginning again!
i++;
rect (i, height/2,100, val*2.5); 
if (i> 1499) { //once i reaches 1498 then it goes back to 0, so the rect starts from the beginning 
  i=0;
  
}
println (val); //prints to Processing console
popMatrix();

}
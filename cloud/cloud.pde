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
size(1500, 800);

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
if ( myPort.available() > 0) {
  val = myPort.read();
}
  
background (0,0,250);

rect(200, val*8, 600, 400); // val determines y, color
  fill(val);
rect(120, val*2, val, 100); // val determines y , color
  fill(0,250,val*3);
rect(500, val*0.5, val, 200); // val determines y, color 
  fill(0,0, val*4);
rect(800, val*0.5, 400, 200); // val determines y, color 
  fill(250,0, val*0.5);
rect(val*2, val*8, 600, 400); // val determines y and x and color
  fill(val);
rect(120, val*2, val*20, 100); // val determines y, and size (width), color
  fill(0,250,val*3);
rect(val*8, val*0.5, val, 200); // val determines y, x, color
  fill(0,0, val*4);
rect(800, val*0.5, 300, 700); // val determines y, color
  fill(110,0, val);
rect(900, val*0.3, 700, 700); // val determines y , color
  fill(0,250, val);


println (val); //prints to Processing console

}
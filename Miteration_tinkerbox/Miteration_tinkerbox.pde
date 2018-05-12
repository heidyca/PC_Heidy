//I referenced code from a minim example we did in Coding-Fall 2017, processing forum, and the arduino to processing code from class



import ddf.minim.*;  //sound library
import processing.serial.*; //serial library from processing 

//sound
Minim minim;
AudioPlayer music;
AudioOutput out;

//arduino
Serial myPort; // makes object from serial class 
char val; // makes variable for the data comiing from serial port (arduino)

void setup()
{
  size(400,400);
  
//serial communication arduino
 printArray(Serial.list());// this line prints the port list to the console
 String portName = Serial.list() [1];// The number in the [] is 1 FOR HEIDYS MAC
 myPort = new Serial(this, portName, 9600);  // arduino gotta be 9600 too 
  
  
  //load the song
   minim = new Minim(this); // load files from data
   music = minim.loadFile( "boxsound2.mp3");  //name of song- (minim only takes mp3 and wav)

   
}

void draw() {
  
  if ( myPort.available() > 0) {   //reading info from arduino
    val = myPort.readChar();  //instead of reading value, processing is going to read the letter m
  }
  
  if (val == 'm'){ // greater than or equal to 50 and nothing is playing, thewn load the song
    music.play();
  }
  println(val);
}

void stop () {
  music.close(); //stop 
}
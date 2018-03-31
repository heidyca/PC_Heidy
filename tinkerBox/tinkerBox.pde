//I referenced code from a minim example we did in Coding-Fall 2017, processing forum, the arduino to processing code from class, A.Berkoy processing code "processing_receives_char.pde" on the physical computing spring 18 github

import ddf.minim.*; //sound library 
import processing.serial.*; //serial library from processing 

//sound
Minim minim;
AudioPlayer player;
AudioOutput out;

//arduino
Serial myPort; // makes object from serial class 
int val; // makes variable for the data comiing from serial port (arduino)

boolean playing = false;  //boolean [true or false]
String tinkersong = "boxsound2.mp3";  //name of song- (minim only takes mp3 and wav)

void setup()
{
  size(400,400);
  
//arduino
 printArray(Serial.list());// this line prints the port list to the console
 String portName = Serial.list() [1];// The number in the [] is 1 FOR HEIDYS MAC
 myPort = new Serial(this, portName, 9600); // arduino gotta be 9600 too 
  
   minim = new Minim(this); // load files from data
   //audio output
   out = minim.getLineOut();
   
}

void draw() {
  
  if ( myPort.available() > 0) {   //reading info from arduino
    val = myPort.read();
  }
  
  if (val == 'm' && playing==false){ // equal to 'm' and nothing is playing, then load the song
    player = minim.loadFile(tinkersong); //loading song from string 
   player.play(); //plays song 
   playing = true;
   
  } else if ( val != 'm'  && playing ==true) { //!= symbol for false // when knob val is less than 400 and the song is still playing 
    playing = false;   //then STOP playing 
  }
   
  println(val);
}

void stop () {
  player.close();
}
//Heidy, this sketch is for lighting LEDS in a sequential pattern when button is pressed
const int LIGHT1 = 13; // names of the leds
const int LIGHT2 = 12; //
const int LIGHT3 = 11; //
const int LIGHT4 = 10; //
const int buttonPin = 7;     // the number of the pushbutton pin

int buttonState = 0; // VARIABLE FOR THE BUTTON'S STATE


void setup() {
  // put your setup code here, to run once:
pinMode(LIGHT1, OUTPUT); // the led pins are being set as the outputs
pinMode(LIGHT2, OUTPUT);
pinMode(LIGHT3, OUTPUT); 
pinMode(LIGHT4, OUTPUT);

pinMode(buttonPin, INPUT); // the button is being recognized as the input 


}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState = digitalRead(buttonPin);

   if (buttonState ==HIGH) { //TURN LED ON WITH BLINKING 
digitalWrite(LIGHT1, HIGH);
delay(300);
digitalWrite(LIGHT2, HIGH);
delay(400);
digitalWrite(LIGHT3, HIGH);
delay(300);
digitalWrite(LIGHT4, HIGH);
delay(400);
   }

else { //LEDS ARENT ON BECAUSE BUTTON IS OFF 
digitalWrite(LIGHT1, LOW);

digitalWrite(LIGHT2, LOW);

digitalWrite(LIGHT3, LOW);

digitalWrite(LIGHT4, LOW);

}

}

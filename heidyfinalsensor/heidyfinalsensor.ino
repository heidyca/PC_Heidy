//http://www.devacron.com/how-to-connect-a-distance-sensor-sharp-2y0a710f-to-arduino/
//blake ex from class

void setup() {
Serial.begin(9600); //match to TouchDesigner Serial in DAT 

}
int sensor;
void loop() {
  
 sensor = analogRead(0);   
  Serial.print(sensor);
  Serial.print("\n"); // use this instead of println to output only one delimiter
                      // println outputs \r\n
  
  delay(300);                  
}

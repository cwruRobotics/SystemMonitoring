/* Analog Read to LED
 * ------------------ 
 *
 *reads data from the linear portentiometer
 *data sheet 
 *http://www.spectrasymbol.com/potentiometer/magnetopots/magnetopot-diagrams-and-schematics
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int potPin = 2;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println(val/50);
 // digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
 // digitalWrite(ledPin, LOW);   // turn the ledPin off
  //delay(val);                  // stop the program for some time
}


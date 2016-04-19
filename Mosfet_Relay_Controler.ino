//Link to setup page from instructables: Arduino Reed Switch
// http://www.instructables.com/id/Arduino-Reed-Switch/?ALLSTEPS 


const int pinSwitch = 12; //Pin Reed

const int mosfet = 5; //Pin LED

int pinVal = 0;

void setup()

{

pinMode(mosfet, OUTPUT); //Imposto i PIN
//Serial.begin(9600);
pinMode(pinSwitch, INPUT);

}

void loop()

{

//pinVal = analogRead(pinSwitch); //Leggo il valore del Reed
digitalWrite(pinSwitch, HIGH);
pinVal = digitalRead(pinSwitch);
if (pinVal == HIGH){
  digitalWrite(mosfet, HIGH);
}
//Serial.print(pinVal);


}

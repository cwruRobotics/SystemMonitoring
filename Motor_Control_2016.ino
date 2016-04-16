//Link to setup page from instructables: Arduino Reed Switch
// http://www.instructables.com/id/Arduino-Reed-Switch/?ALLSTEPS 


const int pinSwitch = 12; //Pin Reed

const int pinLed = 13; //Pin LED

int StatoSwitch = 0;

void setup()

{

pinMode(pinLed, OUTPUT); //Imposto i PIN

pinMode(pinSwitch, INPUT);

}

void loop()

{

StatoSwitch = digitalRead(pinSwitch); //Leggo il valore del Reed

if (StatoSwitch == HIGH)

{

digitalWrite(pinLed, HIGH);

}

else

{

digitalWrite(pinLed, LOW);

}

}

/**
 * Battery Sensor Functions
 *
 *  This document will provide a list of basic functions that can be run on a voltage sensor and a current sensor. Topics will include:
 *    -Reading 
 *
 */
#include <SD.h>
const int chipSelect = 4;
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  // Check to see if the SD card is present, otherwise display error message
  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}
//begin taking data
const int csensor1 = A0;
const int vsensor1 = A1;
const int voltage_1_Zero = 0;
const int voltage_1_Maximum = 1023;
const double voltage_conversion = 0.004888;//maximum real voltage divided by maximum output of the sensor ex: 5/1023
const int current_1_Zero = 102;
const int current_1_Maxium = 783;
const double current_conversion = 0.03193;//maxium real current divided by maximum output of the sensor ex: 30 / 550
const int power_Zero = 5000;//5000 mAh 
const double current_to_power_conversion = 0.027778;// 0.1s/36000 -> h 1000/1A -> mA
double power_left;
double previous_current;
double previous_voltage;
const double r1 = 9889; // 9889 ohms
const double r2 = 5333; // 5333 ohms
double a1_Maximum_Voltage_14V; // the voltage output for A1 at 14V which is 1003 for 4.9049V and 1023 for maximum 5V


void setup() {

  Serial.begin(9600);
  
  pinMode(csensor1,INPUT);

  power_left = 5000;

  previous_current = 0;

  a1_Maximum_Voltage_14V = maximumVoltageA1(r1, r2);

}

void loop() {

  Serial.println(analogRead(csensor1));
  Serial.println(analogRead(vsensor1));
  double currentVoltage = vA1ToVoltageCensor(analogRead(vsensor1));//current voltage 
  double currentCurrent = convertToCurrents(analogRead(csensor1));//current current
  Serial.print("Voltage: ");
  Serial.println(currentVoltage);//print current voltage
  Serial.print("Current: ");
  Serial.println(currentCurrent); //print current current
  double powerConsumed = (currentCurrent + previous_current) * current_to_power_conversion;//power consumed at 0.1s, mAh
  power_left = power_left - powerConsumed;//power left in the battery, mAh
  Serial.print("Power left: ");
  Serial.print(power_left);//print power left
  Serial.println("mAh");
  double percentsLeft = power_left / power_Zero;//power left percentage
  previous_current = currentCurrent;//set previous current to current current
  previous_voltage = currentVoltage;//set previous voltage to current voltage
  Serial.print("Power percentage left: ");
  Serial.print(percentsLeft * 100);//print power percentage left
  Serial.println("%");
  
  //Hard-coded values that need to be changed to the data that will be coming in
  byte volt = currentVoltage;
  byte cur = currentCurrent;
  
 File dataFile = SD.open("datalog.txt", FILE_WRITE);// Opening a file on the SD card to store the values 
 
    // printing the data to the SD card 
    if (dataFile) {
    dataFile.print(dataString1);
    dataFile.println(volt);
    dataFile.print(dataString2);
    dataFile.println(cur);
    dataFile.close();
  }
  
  else {
    Serial.println("error opening datalog.txt"); //print an error message if no data file can be opened 
  }
  
  delay(1000);
  
}

double vA1ToVoltageCensor(int x){

  return 14 * (x / a1_Maximum_Voltage_14V);//convert data of A1 to voltage
}

double convertToCurrents(int x){

  return (x - current_1_Zero) * current_conversion;//convert data of A0 to current
}

double maximumVoltageA1 (double r1, double r2){
  return ((14 - (r1 / (r1 +r2)) * 14) / 5.0) * voltage_1_Maximum;//calculate the maximum voltage of the battery based on r1 and r2
  

}


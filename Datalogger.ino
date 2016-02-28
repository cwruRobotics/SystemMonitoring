

#include <SPI.h>
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

// Main loop
void loop()
{
  //Hard-coded values that need to be changed to the data that will be coming in
  byte volt = 5;
  byte cur = 3;
  // Printing V and C to the serial monitor 
  String dataString1 = "V: ";
  String dataString2 = "C: ";
    
 File dataFile = SD.open("datalog.txt", FILE_WRITE);// Opening a file on the SD card to store the values 
 
    // printing the data to the SD card 
    if (dataFile) {
    dataFile.print(dataString1);
    dataFile.println(volt);
    dataFile.print(dataString2);
    dataFile.println(cur);
    dataFile.close();
    
    // printing the data to the serial monitor 
    Serial.print(dataString1);
    Serial.println(volt);
    Serial.print(dataString2);
    Serial.println(cur); 
    
  }
  
  else {
    Serial.println("error opening datalog.txt"); //print an error message if no data file can be opened 
  }
}










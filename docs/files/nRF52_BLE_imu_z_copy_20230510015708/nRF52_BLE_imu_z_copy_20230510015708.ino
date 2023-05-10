#include "LSM6DS3.h"
#include "Wire.h"

//Create an instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    while (!Serial);
    //Call .begin() to configure the IMUs
    if (myIMU.begin() != 0) {
        Serial.println("Device error");
    } else {
        Serial.println("Device OK!");
    }
}

void loop() {
  

    //Gyroscope
  
    
    Serial.print(myIMU.readFloatGyroX());
    Serial.print(";");
    Serial.print(myIMU.readFloatGyroY());
    Serial.print(";");
    Serial.print(myIMU.readFloatGyroZ());
    Serial.println(" ");

    delay(1000);
}
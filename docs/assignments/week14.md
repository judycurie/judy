# **Week14.** Interface and Application Programming

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |    compare as many tool options as possible |
| *individual*      |     write an application that interfaces a user with an  input &/or output device that you made|


## Photo of the week

![](../images/week14/photo-of-the-week14.png)


## Lecture Notes

![](../images/week14/week13.png)
![](../images/week14/week132.png)
![](../images/week14/week133.png)



## Idea
1. 2 nRF5240 (one Sense) communicating via BLE
2. One remote with recharable battery reads the accolometer data and sends to the second connected to the computer.
3. The data is visualize as geometry (Grasshopper, Thinker)
4. Trying Tensor Flow and Tiny ML

some intresting links:

- https://www.google.com/search?q=conda+python&oq=conda+python&aqs=chrome..69i57.5699j0j4&sourceid=chrome&ie=UTF-8
- http://fab.cba.mit.edu/classes/863.18/Harvard/people/lara/week11.html
- https://learn.adafruit.com/circuitpython-libraries-on-any-computer-with-mcp2221/uart

## Reading the IMU data

1. Download a library called Arduino BLE.  [Github LSM6DS3 Library](https://github.com/Seeed-Studio/Seeed_Arduino_LSM6DS3).From this GitHub repository - Code-> download ZIP

3. Add the Arduino BLE library to the Arduino Library folder using add zip option: Sketch->Inlude Librry->Add .ZIP library -> select the downloaded .zip file "ArduinoBLE-master.zip"

4. Upload the following:
```
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
    //Accelerometer
    Serial.print("\nAccelerometer:\n");
    Serial.print(" X1 = ");
    Serial.println(myIMU.readFloatAccelX(), 4);
    Serial.print(" Y1 = ");
    Serial.println(myIMU.readFloatAccelY(), 4);
    Serial.print(" Z1 = ");
    Serial.println(myIMU.readFloatAccelZ(), 4);

    //Gyroscope
    Serial.print("\nGyroscope:\n");
    Serial.print(" X1 = ");
    Serial.println(myIMU.readFloatGyroX(), 4);
    Serial.print(" Y1 = ");
    Serial.println(myIMU.readFloatGyroY(), 4);
    Serial.print(" Z1 = ");
    Serial.println(myIMU.readFloatGyroZ(), 4);

    //Thermometer
    Serial.print("\nThermometer:\n");
    Serial.print(" Degrees C1 = ");
    Serial.println(myIMU.readTempC(), 4);
    Serial.print(" Degrees F1 = ");
    Serial.println(myIMU.readTempF(), 4);

    delay(1000);
}
```
![](../images/week14/week1310.png)
**Fig.** nRF52840 reading the Accelerometer.



## Connecting 2 XIAO nRF52840

https://wiki.seeedstudio.com/XIAO-BLE-Sense-Bluetooth-Usage/

1. Intsall library [u8g2](https://github.com/olikraus/u8g2) -> Tools -> Manage Libraries -> U8g2


## Final Video
<video width="960"  controls>
  <source src="../../images/week14/WhatsApp Video 2023-05-02 at 19.45.38.mp4" type="video/mp4">
</video>

## Problems

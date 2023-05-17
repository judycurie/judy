# **Week14.-fails** Interface and Application Programming

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
 - one way is to have the data on the XIAO host and read them from ->https://github.com/MarlinFirmware/MarlinDocumentation/edit/master/_hardware/boards.md (Adding a new board
The easiest way to add a new board to Marlin is to start with one of the existing pins files that has pin mappings similar to the new board, make a copy, and modify the pins that differ. Once your pins file is ready, simply add a new define to the boards.h file and a conditional include to pins.h. And you're done! Submit a PR to share it with the world.)
 - second way is to get the wirelessly from XIAO slave
4. Trying Tensor Flow and Tiny ML (https://wiki.seeedstudio.com/XIAO-BLE-Sense-TFLite-Mic)

some intresting links:

- https://www.google.com/search?q=conda+python&oq=conda+python&aqs=chrome..69i57.5699j0j4&sourceid=chrome&ie=UTF-8
- http://fab.cba.mit.edu/classes/863.18/Harvard/people/lara/week11.html
- https://learn.adafruit.com/circuitpython-libraries-on-any-computer-with-mcp2221/uart

## Software
python -m pip install pyserial

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

## Reading the IMU data with Grasshoper and Firefly
The run Firefly the File "Firefly Firmata" needs to be upload to the (Arduino) Board. You can find it after installing Firefly in Arduino IDE -> File -> Skechbook_> Firefly Firmata. As we are using XIAO, not the

I tried to modify the code to make it compile and upload to XIAO board.  Below the result. **The file compiles and uploads to the XIAO board, but still in Grasshopper the serial port can not be read.**
Another problem to explore is to mannually finde the location of the arduino.exe file while opening the Grasshopper (maybe this is the reason of not reading Genreal Serial Port.

```
/*
 Created by Judy Curie
 based on the original code from March 25th, 2015 by Andrew Payne and Jason Kelly Johnson
 Latest Update 3rd May 2023
 Copyright 2023 | All Rights Reserved

 This Firmata allows you to control an Seed Xiao boards from Rhino/Grasshopper/Firefly.
 Updates, Questions, Suggestions visit:

 1. Plug Arduino boards into your USB port; confirm that your Arduino's green power LED in on
 2. Select your specific Arduino Board and Serial Port (Tools > Board; Tools > Serial Port) *Take note of your Serial Port COM #
 3. Verify (play button) and Upload (upload button) this program to your Arduino, close the Arduino program
 4. then open ... Rhino/Grasshopper/Firefly

 Note: The Firefly Firmata sets the following pins to perform these functions:

  *****ON STANDARD XIAO (ie. RP2040, ESP32C3, etc.)*****
 ANALOG-DIGITAL IN/OUT - AD0 -AD3 - can be used to digitalWrite, analogWrite, or Servo.write depending on the input status of that Firefly pin
 DIGITAL IN/OUT - D4-D10 -will return 0's or 1's; for 3 potential digital sensors (buttons, switches, on/off, true/false, etc.)

RP2040: (D0- 26, D1 -27, D2 - 28, D3- pin 29, D4- pin 6, D5- pin 7, D6 - pin 0, D7 - pin1, D8 - pin 2, D9- pin 4, D10 -pin 3)
ESP323C: ( to be added)

 *****ON STANDARD XIAO (ie. nRFN52840, nRFN52840 (sense),etc.)*****
 ANALOG-DIGITAL IN/OUT - AD0 -AD5 - can be used to digitalWrite, analogWrite, or Servo.write depending on the input status of that Firefly pin
 DIGITAL IN/OUT - D6-D10 -will return 0's or 1's; for 3 potential digital sensors (buttons, switches, on/off, true/false, etc.)
nRFN52840: (D0- pin 0.02, ...)


 */

#include <Servo.h>            // attach Servo library (http://www.arduino.cc/playground/ComponentLib/Servo)
#include <pins_arduino.h>     // attach arduino pins header file to determine which board type is being used

#define BAUDRATE 115200       // Set the Baud Rate to an appropriate speed
#define BUFFSIZE 512          // buffer one command at a time

/*==============================================================================
 * GLOBAL VARIABLES
 *============================================================================*/

char buffer[BUFFSIZE];        // declare buffer
uint8_t bufferidx = 0;        // a type of unsigned integer of length 8 bits
char *parseptr;
char buffidx;

int counter = 0;
int numcycles = 1000;

#if defined(_UART_USB_)                 // declare variables for DUE boards
  Servo FDAC0, FDAC1, Servo2, Servo3, Servo4, Servo5, Servo6, Servo7, Servo8, Servo9, Servo10, Servo11, Servo12, Servo13, Servo32, Servo33, Servo34, Servo35, Servo36, Servo37, Servo38, Servo39, Servo40, Servo41, Servo42, Servo43, Servo44, Servo45, Servo46, Servo47, Servo48, Servo49, Servo50, Servo51, Servo52, Servo53;  
  Servo SERVO_CONFIG[] = {FDAC0, FDAC1, Servo2, Servo3, Servo4, Servo5, Servo6, Servo7, Servo8, Servo9, Servo10, Servo11, Servo12, Servo13, Servo32, Servo33, Servo34, Servo35, Servo36, Servo37, Servo38, Servo39, Servo40, Servo41, Servo42, Servo43, Servo44, Servo45, Servo46, Servo47, Servo48, Servo49, Servo50, Servo51, Servo52, Servo53};  // declare array of Servo objects
  int WRITE_PIN_CONFIG[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53}; //Note: first two values correspond to the DAC pins
  int READ_APIN_CONFIG[] = {2,3,4,5,28,29};
  int READ_DPIN_CONFIG[] = {2,3,4,5,28,29,11,12,13,14,15};
#endif



/*==============================================================================
 * SETUP() This code runs once
 *============================================================================*/
void setup()
{
  Init();                       //set initial pinmodes
  Serial.begin(BAUDRATE);       // Start Serial communication
  #if defined(_UART_USB_)      //if the connected board is an Arduino DUE
    analogReadResolution(12);   //Set the analog read resolution to 12 bits (acceptable values between 1-32 bits).  This is only for DUE boards
    analogWriteResolution(12);  // Set the analog write resolution to 12 bits (acceptable values between 1-32 bits).  This is only for DUE boards
  #endif
}

/*==============================================================================
 * LOOP() This code loops
 *============================================================================*/
void loop()
{
  if(Serial){
    ReadSerial();                       // read and parse string from serial port and write to pins
    if (counter >= numcycles){          // Wait every nth loop
      ReadInputs();                     // get input data and print data to the serial port
      counter = 0;                      // reset the counter
    }
    counter ++;                         // increment the writecounter
  }
}

/*==============================================================================
 * FUNCTIONS()
 *============================================================================*/

/*
* Initializes the digital pins which will be used as inputs
*/
void Init(){
  int READ_DPIN_CONFIG[] = {2,3,4,5,28,29,11,12,13,14,15};
  int len = sizeof(READ_DPIN_CONFIG)/sizeof(READ_DPIN_CONFIG[0]); //get the size of the array
  for(int i = 0; i < len; i++){
    pinMode(READ_DPIN_CONFIG[i], INPUT);
  }
}

/*
* Reads the incoming ADC or digital values from the corresponding analog and digital input  
* pins and prints the value to the serial port as a formatted commma separated string
*/
void ReadInputs(){
  int READ_APIN_CONFIG[] = {2,3,4,5,28,29};
  int READ_DPIN_CONFIG[] = {2,3,4,5,28,29,11,12,13,14,15};
  int len = sizeof(READ_APIN_CONFIG)/sizeof(READ_APIN_CONFIG[0]); //get the size of the array
  for(int i = 0; i < len; i++){
    int val = analogRead(READ_APIN_CONFIG[i]);  //read value from analog pins
    Serial.print(val); Serial.print(",");   
  }
  len = sizeof(READ_DPIN_CONFIG)/sizeof(READ_DPIN_CONFIG[0]); //get the size of the array
  for(int i = 0; i < len; i++){
    int val = digitalRead(READ_DPIN_CONFIG[i]); //read value from digital pins
    Serial.print(val); Serial.print(",");   
  }
  Serial.println("eol");  //end of line marker
}

/*
* Retrieve the latest incoming serial value and split the string at the comma delimeter.
* When a comma is found, the value is offloaded to a temporary variable and written
* to the corresponding digital pin.
*/
void ReadSerial(){
  int WRITE_PIN_CONFIG[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
  Servo FDAC0, FDAC1, Servo2, Servo3, Servo4, Servo5, Servo6, Servo7, Servo8, Servo9, Servo10, Servo11, Servo12, Servo13, Servo32, Servo33, Servo34, Servo35, Servo36, Servo37, Servo38, Servo39, Servo40, Servo41, Servo42, Servo43, Servo44, Servo45, Servo46, Servo47, Servo48, Servo49, Servo50, Servo51, Servo52, Servo53;  
  Servo SERVO_CONFIG[] = {FDAC0, FDAC1, Servo2, Servo3, Servo4, Servo5, Servo6, Servo7, Servo8, Servo9, Servo10, Servo11, Servo12, Servo13, Servo32, Servo33, Servo34, Servo35, Servo36, Servo37, Servo38, Servo39, Servo40, Servo41, Servo42, Servo43, Servo44, Servo45, Servo46, Servo47, Servo48, Servo49, Servo50, Servo51, Servo52, Servo53};
  char c;    // holds one character from the serial port
  if (Serial.available()) {
    c = Serial.read();         // read one character
    buffer[bufferidx] = c;     // add to buffer
    if (c == '\n') {  
      buffer[bufferidx+1] = 0; // terminate it
      parseptr = buffer;       // offload the buffer into temp variable
      int len = sizeof(WRITE_PIN_CONFIG)/sizeof(WRITE_PIN_CONFIG[0]); //get the size of the array
      for(int i = 0; i < len; i++){
        //parse all incoming values and assign them to the appropriate variable
        int val = parsedecimal(parseptr);       // parse the incoming number
        if(i != len - 1) parseptr = strchr(parseptr, ',')+1;   // move past the ","
        WriteToPin(WRITE_PIN_CONFIG[i], val, SERVO_CONFIG[i]);         //send value out to pin on arduino board
      }    
      bufferidx = 0;                             // reset the buffer for the next read
      return;                                    // return so that we don't trigger the index increment below
    }                                            // didn't get newline, need to read more from the buffer
    bufferidx++;                                 // increment the index for the next character
    if (bufferidx == BUFFSIZE-1) bufferidx = 0;  // if we get to the end of the buffer reset for safety
  }
}

/*
* Send the incoming value to the appropriate pin using pre-defined logic (ie. digital, analog, or servo)
*/
void WriteToPin(int _pin, int _value, Servo _servo){
  if (_value >= 10000 && _value < 20000)            // check if value should be used for Digital Write (HIGH/LOW)
  {      
    if (_servo.attached()) _servo.detach();         // detach servo is one is attached to pin
    pinMode(_pin, OUTPUT);                       
    _value -= 10000;                                // subtract 10,000 from the value sent from Grasshopper
    if (_value == 1) digitalWrite(_pin, HIGH);     
    else digitalWrite(_pin, LOW);   
  }   
  else if (_value >= 20000 && _value < 30000)       // check if value should be used for Analog Write (0-255)
  {
    if (_servo.attached()) _servo.detach();         // detach servo is one is attached to pin
    pinMode(_pin, OUTPUT);               
    _value -= 20000;                                // subtract 20,000 from the value sent from Grasshopper
    analogWrite(_pin, _value);                     
  }
  else if (_value >= 30000 && _value < 40000)       // check if value should be used for Servo Write (0-180)
  {
    _value -= 30000;                                // subtract 30,000 from the value sent from Grasshopper
    if (!_servo.attached())_servo.attach(_pin);     // attaches a Servo to the PWM pin (180 degree standard servos)                                    
    _servo.write(_value);                          
  }
  else if (_value >= 40000 && _value < 50000)       // check if value should be used for Analog Write (0-4096) for DACs
  {
    if (_servo.attached()) _servo.detach();         // detach servo is one is attached to pin
    pinMode(_pin, OUTPUT);               
    _value -= 40000;                                // subtract 40,000 from the value sent from Grasshopper
    WriteToPin(_pin, _value, _servo);                     
  }
}

/*
* Parse a string value as a decimal
*/
uint32_t parsedecimal(char *str){
  uint32_t d = 0;
  while (str[0] != 0) {
    if ((str[0] > '50') || (str[0] < '0'))
      return d;
    d *= 10;
    d += str[0] - '0';
    str++;
  }
  return d;
}

/*
* Send the incoming value to the appropriate DAC for DUE boards.
* Note: analogWrite resolution (default is 12 bits) is defined in the Setup function.
*/
/*
 #if defined(__SAM3X8E__)
  void WriteToDAC(int _pin, int _value){
    if(_pin == 0) analogWrite(DAC0, _value);
    else if (_pin == 1) analogWrite(DAC1, _value);
  }
#endif

*/
```

Another code that requires editing the Board.h (adding the XIAO)



```
#include <Firmata.h>
#include <Servo.h>

#define SERVO_PIN 0  // PWM pin for servo
#define LED_PIN 13   // built-in LED pin

void analogWriteCallback(byte pin, int value);
void digitalWriteCallback(byte pin, int value);
void servoWriteCallback(byte pin, int value);

Servo myservo;

void setup() {
  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
  Firmata.attach(DIGITAL_MESSAGE, digitalWriteCallback);
  Firmata.attach(SERVO_MESSAGE, servoWriteCallback);

  myservo.attach(SERVO_PIN);  // attach servo to PWM pin
  pinMode(LED_PIN, OUTPUT);  // set built-in LED pin as output

  Firmata.begin(57600);  // start Firmata communication
}

void loop() {
  Firmata.processInput();
}

void analogWriteCallback(byte pin, int value) {
  if (pin >= 0 && pin <= 5) {  // check if the pin is valid for analog output
    analogWrite(pin, value);  // write analog output value to the pin
  }
}

void digitalWriteCallback(byte pin, int value) {
  if (pin >= 6 && pin <= 10) {  // check if the pin is valid for digital output
    digitalWrite(pin, value);  // write digital output value to the pin
    if (pin == LED_PIN) {  // if the built-in LED pin is written to, turn on/off the LED accordingly
      digitalWrite(LED_PIN, value);
    }
  }
}

void servoWriteCallback(byte pin, int value) {
  if (pin == SERVO_PIN) {  // check if the servo pin is valid
    myservo.write(value);  // set servo position based on the input value
  }
}

```


## Connecting 2 XIAO nRF52840

https://wiki.seeedstudio.com/XIAO-BLE-Sense-Bluetooth-Usage/

1. Intsall library [u8g2](https://github.com/olikraus/u8g2) -> Tools -> Manage Libraries -> U8g2


## Final Video
<video width="960"  controls>
  <source src="../../images/week14/WhatsApp Video 2023-05-02 at 19.45.38.mp4" type="video/mp4">
</video>

## Problems

#include "LSM6DS3.h"
#include "Wire.h"
#include <SPI.h>

//Create an instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

// Set initial values for position, velocity, and time
float position[3] = {0, 0, 0};
float velocity[3] = {0, 0, 0};
unsigned long timestamp;
const float accelerationThreshold = 2.5; // threshold of significant in G's

// Define constants for integration
const float SAMPLING_INTERVAL = 0.01; // in seconds
const float GRAVITY = 9.81; // in m/s^2

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

  // Set the range of the accelerometer to +/- 16g
  //myIMU.A_SCALE_16G;

  // Set the output data rate of the accelerometer to 104 Hz
  //myIMU.setAccelDataRate(LSM6DS_RATE_104_HZ);

  // Set initial timestamp
  timestamp = millis();
}

void loop() {
  // Read the acceleration data from the LSM6DS3 sensor
  
  float x = myIMU.readFloatAccelX();
  float y = myIMU.readFloatAccelY();
  float z = myIMU.readFloatAccelZ();

  float aSum = fabs(x) + fabs(y) + fabs(z);
  if (aSum >= accelerationThreshold) {
  //Serial.print(x);
  //Serial.print("   ");
  // Calculate the elapsed time since the last iteration
    unsigned long current_time = millis();
    float elapsed_time = (current_time - timestamp) / 1000.0;
 
  // Calculate the change in velocity due to acceleration
    float delta_vx = x * GRAVITY * elapsed_time;
    float delta_vy = y * GRAVITY * elapsed_time;
    float delta_vz = z * GRAVITY * elapsed_time;
  //Serial.print(delta_vx);
  //Serial.print("   ");
  // Update the velocity
    velocity[0] += delta_vx;
    velocity[1] += delta_vy;
    velocity[2] += delta_vz;

  // Calculate the change in position due to velocity
    float delta_px = velocity[0] * elapsed_time;
    float delta_py = velocity[1]* elapsed_time;
    float delta_pz = velocity[2]* elapsed_time;
  //Serial.print(delta_px);
  //Serial.print("   ");
  // Update the position
    position[0] += delta_px;
    position[1] += delta_py;
    position[2] += delta_pz;

  // Update the timestamp
    timestamp = current_time;
    
  }

  // Output the position data
  //Serial.print("Position (x, y, z): ");
  Serial.print(position[0]);
  Serial.print(", ");
  Serial.print(position[1]);
  Serial.print(", ");
  Serial.println(position[2]);

  // Wait for the next iteration
  delay(SAMPLING_INTERVAL * 1000);

}

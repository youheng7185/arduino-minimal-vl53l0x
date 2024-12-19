#include "sensor.h"
#include <Wire.h>
#include "convert.h"

#define FIFO_SIZE 5

uint16_t fifoBuffer[FIFO_SIZE] = {0};  // Buffer to store the readings (using uint16_t)
uint8_t fifoIndex = 0;  // Index to track position in the buffer

// Function to calculate the average of the FIFO buffer
uint16_t calculateAverage() {
  uint32_t sum = 0;  // Use uint32_t for the sum to prevent overflow
  for (uint8_t i = 0; i < FIFO_SIZE; i++) {
    sum += fifoBuffer[i];
  }
  return sum / FIFO_SIZE;  // Return average as uint16_t
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println("started");
  //Wire.begin(5, 4);
  Wire.setClock(100000);
  Serial.println("done begin i2c");
  
  // Initialize the FIFO buffer with 0 (optional, since it's already initialized)
  for (uint8_t i = 0; i < FIFO_SIZE; i++) {
    fifoBuffer[i] = 0;
  }

  if(!vl53l0x_init()){
    Serial.println("fail init multiple sensor");
    while(1);
  } else {
    Serial.println("success init multiple sensor");
  }
}
unsigned long startTime;
unsigned long endTime;
unsigned long executionTime;

void loop() {
  double rangeVal = 0;              // Variable to hold the distance reading
  unsigned long startTime = millis(); // Record the start time of the loop
  uint16_t range = 0;

  vl53l0x_read_range_single(VL53L0X_IDX_FIRST, range);
  // Read and print range for the first sensor
  //convertValue(VL53L0X_IDX_FIRST, rangeVal);
  Serial.print("Sensor 1: ");
  Serial.println(range);
/*
  // Read and print range for the second sensor
  convertValue(VL53L0X_IDX_SECOND, rangeVal);
  Serial.print("Sensor 2: ");
  Serial.println(rangeVal);

  // Read and print range for the second sensor
  convertValue(VL53L0X_IDX_THIRD, rangeVal);
  Serial.print("Sensor 3: "); // not accurate
  Serial.println(rangeVal);

  // Read and print range for the second sensor
  convertValue(VL53L0X_IDX_FOURTH, rangeVal);
  Serial.print("Sensor 4: "); 
  Serial.println(rangeVal + 1.0);

  // Read and print range for the second sensor
  convertValue(VL53L0X_IDX_FIFTH, rangeVal);
  Serial.print("Sensor 5: "); //+3
  Serial.println(rangeVal + 2.0);

  // Read and print range for the second sensor
  convertValue(VL53L0X_IDX_SIXTH, rangeVal);
  Serial.print("Sensor 6: "); // + 1
  Serial.println(rangeVal + 1.0);
*/
  unsigned long endTime = millis(); // Record the end time of the loop
  unsigned long executionTime = endTime - startTime; // Calculate execution time

  Serial.print("Loop Execution Time: ");
  Serial.print(executionTime);
  Serial.println(" ms");

  delay(500); // Delay to avoid flooding serial output
}


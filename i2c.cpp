#include <Arduino.h>
#include <Wire.h>

#define DEFAULT_ADD (0x29)
uint8_t current_address = DEFAULT_ADD; // Global variable to hold the current I2C slave address

void i2c_set_slave_address(uint8_t addr) {
  current_address = addr; // Update the global address
}

bool i2c_write_addr8_data8(uint8_t address, uint8_t data) {
  Wire.beginTransmission(current_address); // Use the current address
  Wire.write(address);
  Wire.write(data);
  if (Wire.endTransmission() != 0) {
    return false;
  }
  return true;
}

bool i2c_read_addr8_data8(uint8_t address, uint8_t &data) {
  Wire.beginTransmission(current_address); // Use the current address
  Wire.write(address);
  if (Wire.endTransmission(false) != 0) { // Send repeated start
    return false; // Transmission failed
  }

  Wire.requestFrom(current_address, 1); // Request 1 byte of data
  if (Wire.available()) {
    data = Wire.read(); // Read and return the 8-bit data
    return true;
  }

  return false;
}

bool i2c_read_addr8_data16(uint8_t address, uint16_t &data) {
  Wire.beginTransmission(current_address); // Use the current address
  Wire.write(address);
  if (Wire.endTransmission(false) != 0) { // Send repeated start
    return false; // Transmission failed
  }

  Wire.requestFrom(current_address, 2); // Request 2 bytes of data
  if (Wire.available() == 2) {
    // Read two bytes and combine them into a 16-bit value
    data = Wire.read();         // First byte (low byte)
    data |= (Wire.read() << 8); // Second byte (high byte)
    return true;
  }

  return false;
}

#ifndef I2C_H
#define I2C_H

bool i2c_write_addr8_data8(uint8_t address, uint8_t data);
bool i2c_read_addr8_data8(uint8_t address, uint8_t &data);
bool i2c_read_addr8_data16(uint8_t address, uint16_t &data);
void i2c_set_slave_address(uint8_t addr);

/*
void i2c_init(void);
void i2c_set_slave_address(uint8_t addr);

bool i2c_read_addr8_data8(uint8_t addr, uint8_t *data);
bool i2c_read_addr8_data16(uint8_t addr, uint16_t *data);
bool i2c_read_addr16_data8(uint16_t addr, uint8_t *data);
bool i2c_read_addr16_data16(uint16_t addr, uint16_t *data);
bool i2c_read_addr8_data32(uint16_t addr, uint32_t *data);
bool i2c_read_addr16_data32(uint16_t addr, uint32_t *data);

bool i2c_read_addr8_bytes(uint8_t start_addr, uint8_t *bytes, uint16_t byte_count);

bool i2c_write_addr8_data8(uint8_t addr, uint8_t data);
bool i2c_write_addr8_data16(uint8_t addr, uint16_t data);
bool i2c_write_addr16_data8(uint16_t addr, uint8_t data);
bool i2c_write_addr16_data16(uint16_t addr, uint16_t data);


bool i2c_write_addr8_bytes(uint8_t start_addr, uint8_t *bytes, uint16_t byte_count);
*/

#endif /* I2C_H */

#ifndef _SENSOR_H
#define _SENSOR_H

#define VL53L0X_OUT_OF_RANGE (8190)

// single sensor
bool setupSensor();
//bool vl53l0x_read_range_single(uint16_t &range);

bool vl53l0x_init();

// multiple sensor
// add sensor at init address function,


typedef enum
{
    VL53L0X_IDX_FIRST,
    VL53L0X_IDX_SECOND,
    VL53L0X_IDX_THIRD,
} vl53l0x_idx_t;

bool vl53l0x_read_range_single(vl53l0x_idx_t idx, uint16_t &range);

#endif
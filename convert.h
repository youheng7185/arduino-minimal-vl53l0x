#ifndef CONVERT_H
#define CONVERT_H

#include "Wire.h"
#include "sensor.h"
bool convertValue(vl53l0x_idx_t idx, double &rangeConverted);

#endif
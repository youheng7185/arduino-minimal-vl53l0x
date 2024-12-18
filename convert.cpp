#include "convert.h"
#include "sensor.h"
#include "Wire.h"

bool convertValue(vl53l0x_idx_t idx, double &rangeConverted){
  uint16_t range;
  vl53l0x_read_range_single(idx, range);
  if (range > 30000) {
    rangeConverted = range * 0.0003559 - 5.17;
  } else {
    rangeConverted = range * 0.0003411 + 18.60;
  }
  return true;
}
#include "byte_utils.h"
#include <string.h> 

uint32_t bytes_to_uint32(const uint8_t bytes[4]) {
  return ((uint32_t)bytes[0] << 24) |
         ((uint32_t)bytes[1] << 16) |
         ((uint32_t)bytes[2] << 8)  |
         ((uint32_t)bytes[3]);
}

uint16_t bytes_to_uint16(const uint8_t bytes[2]) {
  return ((uint16_t)bytes[0] << 8) |
         ((uint16_t)bytes[1]);
}

void uint32_to_bytes(uint32_t value, uint8_t bytes[4]) {
  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8)  & 0xFF;
  bytes[3] = value & 0xFF;
}

void uint16_to_bytes(uint16_t value, uint8_t bytes[2]) {
  bytes[0] = (value >> 8) & 0xFF;
  bytes[1] = value & 0xFF;
}

int32_t bytes_to_int32(const uint8_t bytes[4]) {
  return ((int32_t)bytes[0] << 24) |
         ((int32_t)bytes[1] << 16) |
         ((int32_t)bytes[2] << 8)  |
         ((int32_t)bytes[3]);
}

void int32_to_bytes(int32_t value, uint8_t bytes[4]) {
  bytes[0] = (value >> 24) & 0xFF;
  bytes[1] = (value >> 16) & 0xFF;
  bytes[2] = (value >> 8)  & 0xFF;
  bytes[3] = value & 0xFF;
}

float bytes_to_float(const uint8_t bytes[4]) {
  float value;
  memcpy(&value, bytes, sizeof(float));
  return value;
}

void float_to_bytes(float value, uint8_t bytes[4]) {
  memcpy(bytes, &value, sizeof(float));
}

double bytes_to_double(const uint8_t bytes[8]) {
  double value;
  memcpy(&value, bytes, sizeof(double));
  return value;
}

void double_to_bytes(double value, uint8_t bytes[8]) {
    memcpy(bytes, &value, sizeof(double));
}

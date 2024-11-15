/**
 * @file byte_utils.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-15-10-20
 * @author Nemausa
 *
 */
#ifndef BYTE_UTILS_H_
#define BYTE_UTILS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t bytes_to_uint32(const uint8_t bytes[4]);
int32_t  bytes_to_int32(const uint8_t bytes[4]);
uint16_t bytes_to_uint16(const uint8_t bytes[2]);
float    bytes_to_float(const uint8_t bytes[4]);
double   bytes_to_double(const uint8_t bytes[8]);
void     uint32_to_bytes(uint32_t value, uint8_t bytes[4]);
void     int32_to_bytes(int32_t value, uint8_t bytes[4]);
void     uint16_to_bytes(uint16_t value, uint8_t bytes[2]);
void     float_to_bytes(float value, uint8_t bytes[4]);
void     double_to_bytes(double value, uint8_t bytes[8]);

#ifdef __cplusplus
}
#endif

#endif  // BYTE_UTILS_H_

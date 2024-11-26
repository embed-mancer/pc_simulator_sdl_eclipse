/**
 * @file byte_utils.h
 *
 * @brief Utility functions for converting between byte arrays and basic data
 * types.
 *
 * This file provides functions to convert between byte arrays and standard data
 * types such as uint32_t, int32_t, float, and double. These functions are
 * useful for serialization and deserialization of data in communication
 * protocols.
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date 2024-11-15
 * @author Nemausa
 */
#ifndef BYTE_UTILS_H_
#define BYTE_UTILS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Converts an array of 4 bytes to a uint32_t value.
 *
 * @param[in] bytes An array of 4 bytes representing the uint32_t value.
 * @return The converted uint32_t value.
 */
uint32_t bytes_to_uint32(const uint8_t bytes[4]);

/**
 * @brief Converts an array of 4 bytes to an int32_t value.
 *
 * @param[in] bytes An array of 4 bytes representing the int32_t value.
 * @return The converted int32_t value.
 */
int32_t bytes_to_int32(const uint8_t bytes[4]);

/**
 * @brief Converts an array of 2 bytes to a uint16_t value.
 *
 * @param[in] bytes An array of 2 bytes representing the uint16_t value.
 * @return The converted uint16_t value.
 */
uint16_t bytes_to_uint16(const uint8_t bytes[2]);

/**
 * @brief Converts an array of 4 bytes to a float value.
 *
 * @param[in] bytes An array of 4 bytes representing the float value.
 * @return The converted float value.
 */
float bytes_to_float(const uint8_t bytes[4]);

/**
 * @brief Converts an array of 8 bytes to a double value.
 *
 * @param[in] bytes An array of 8 bytes representing the double value.
 * @return The converted double value.
 */
double bytes_to_double(const uint8_t bytes[8]);

/**
 * @brief Converts a uint32_t value to an array of 4 bytes.
 *
 * @param[in] value The uint32_t value to convert.
 * @param[out] bytes An array of 4 bytes to store the converted value.
 */
void uint32_to_bytes(uint32_t value, uint8_t bytes[4]);

/**
 * @brief Converts an int32_t value to an array of 4 bytes.
 *
 * @param[in] value The int32_t value to convert.
 * @param[out] bytes An array of 4 bytes to store the converted value.
 */
void int32_to_bytes(int32_t value, uint8_t bytes[4]);

/**
 * @brief Converts a uint16_t value to an array of 2 bytes.
 *
 * @param[in] value The uint16_t value to convert.
 * @param[out] bytes An array of 2 bytes to store the converted value.
 */
void uint16_to_bytes(uint16_t value, uint8_t bytes[2]);

/**
 * @brief Converts a float value to an array of 4 bytes.
 *
 * @param[in] value The float value to convert.
 * @param[out] bytes An array of 4 bytes to store the converted value.
 */
void float_to_bytes(float value, uint8_t bytes[4]);

/**
 * @brief Converts a double value to an array of 8 bytes.
 *
 * @param[in] value The double value to convert.
 * @param[out] bytes An array of 8 bytes to store the converted value.
 */
void double_to_bytes(double value, uint8_t bytes[8]);

#ifdef __cplusplus
}
#endif

#endif  // BYTE_UTILS_H_

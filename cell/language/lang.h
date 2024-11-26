/**
 * @file lang.h
 *
 * @brief Language management for text IDs.
 *
 * This header file provides an enumeration for various text IDs used in the
 * system, and declares a function for retrieving the corresponding language
 * string.
 *
 * @ingroup LangModule
 * @defgroup LangModule Language Functions
 * @brief Module for managing language text retrieval.
 *
 * @date 2024-11-10-17-59
 *
 * @author Nemausa
 */
#ifndef LANG_H_
#define LANG_H_

#include "../tool/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumeration of text IDs.
 *
 * This enumeration defines various text identifiers that correspond to
 * different text elements in the user interface, such as basic information,
 * settings, and phone-related options.
 */
typedef enum {
  TEXT_ID_DISPLAY,
  TEXT_ID_BACKLIGHT,
  TEXT_ID_BLUETOOTH,
  TEXT_ID_CLOCK,
  TEXT_ID_UNIT,
  TEXT_ID_LANGUAGE,
  TEXT_ID_VEHICLE,
  TEXT_ID_FAULT,
  TEXT_ID_MOBILE,
  TEXT_ID_BASIC,
  TEXT_ID_ODO,
  TEXT_ID_TRIP,
  TEXT_ID_FAULT_INFO,
  TEXT_ID_MAINTAIN,
  TEXT_ID_VOLTAGE,
  TEXT_ID_RANGE,
  TEXT_ID_TEMPERATURE,
  TEXT_ID_OPEN,
  TEXT_ID_CLOSE,
  TEXT_ID_DAY,
  TEXT_ID_NIGHT,
  TEXT_ID_AUTO,
  TEXT_ID_METRIC,
  TEXT_ID_IMPERIAL,
  TEXT_ID_BT_NAME,
  TEXT_ID_BT_CONNECT,
  TEXT_ID_BT_SYNC,
  TEXT_ID_BT_OPEN,
  TEXT_ID_BT_CLOSE,

  TEXT_ID_FAULT_CURRENT,
  TEXT_ID_FAULT_HISTORY,
  TEXT_ID_FAULT_OS,
  TEXT_ID_FAULT_MCU,

  TEXT_ID_MAIN_TRIP,
  TEXT_ID_MAIN_AVG_SPEED,
  TEXT_ID_MAIN_RIDE_TIME,
  TEXT_ID_MAIN_BATTERY,

  TEXT_ID_SETTINGS,
  TEXT_ID_COUNT /**< Total count of text IDs. */
} text_id_t;

/**
 * @brief Retrieves the language text corresponding to a given text ID.
 *
 * @param[in] id The text ID for which to retrieve the corresponding language
 * string.
 * @return A pointer to the language string corresponding to the provided text
 * ID.
 */
const char* lang_text(text_id_t id);
void lang_set(language_e e);

#ifdef __cplusplus
}
#endif

#endif  // LANG_H_

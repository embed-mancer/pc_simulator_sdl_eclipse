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
  TEXT_ID_BASIC_INFO,        /**< Basic vehicle information. */
  TEXT_ID_ODO,               /**< Odometer information. */
  TEXT_ID_TRIP,              /**< Trip information. */
  TEXT_ID_FAULT_INFO,        /**< Fault information. */
  TEXT_ID_MAINTAIN_MILEAGE,  /**< Maintenance mileage information. */
  TEXT_ID_VEHICLE_SETTINGS,  /**< Vehicle settings. */
  TEXT_ID_VEHICLE_INFO,      /**< Vehicle information. */
  TEXT_ID_QUICK_SHIFT,       /**< Quick shift option. */
  TEXT_ID_UPSHIFT,           /**< Upshift information. */
  TEXT_ID_PHONE,             /**< Phone-related options. */
  TEXT_ID_MUSIC,             /**< Music-related options. */
  TEXT_ID_SETTINGS,          /**< General settings. */
  TEXT_ID_OPEN,              /**< Open option. */
  TEXT_ID_CLOSE,             /**< Close option. */
  TEXT_ID_CONTACTS,          /**< Phone contacts. */
  TEXT_ID_RECENT_CALLS,      /**< Recent calls information. */
  TEXT_ID_DEVICE_CONNECTION, /**< Device connection status. */
  TEXT_ID_OPTIONAL_INFO_1,   /**< Optional information 1. */
  TEXT_ID_OPTIONAL_INFO_2,   /**< Optional information 2. */
  TEXT_ID_AUTO_BRIGHTNESS,   /**< Auto brightness setting. */
  TEXT_ID_UNIT_SETTINGS,     /**< Unit settings. */
  TEXT_ID_TIME_SETTINGS,     /**< Time settings. */
  TEXT_ID_LANGUAGE_SETTINGS, /**< Language settings. */
  TEXT_ID_COUNT              /**< Total count of text IDs. */
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

#ifdef __cplusplus
}
#endif

#endif  // LANG_H_

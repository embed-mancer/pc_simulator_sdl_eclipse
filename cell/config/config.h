/**
 * @file config.h
 *
 * @brief This header file defines configuration parameters and functions for
 * managing system settings.
 *
 * @ingroup ConfigurationModule
 *
 * @date 2024-11-18
 *
 * @details This file contains enumerations for various configuration
 * parameters, including UI, day/night settings, heating, display, Bluetooth,
 * maintenance, and TPMS settings. It also declares functions for setting,
 * retrieving, saving, and loading these configurations.
 *
 * @author Nemausa
 *
 */
#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  // Vehicle UI settings (CONFIG_UI_)
  CONFIG_UI_THEME,
  CONFIG_UI_DISTANCE_UNIT,
  CONFIG_UI_LED_LEVEL,
  CONFIG_UI_LANGUAGE,

  // Day and night settings (CONFIG_DAYNIGHT_)
  CONFIG_DAYNIGHT_SETTING,
  CONFIG_DAYNIGHT_DISPLAY,

  // Heating system settings (CONFIG_HEAT_)
  CONFIG_HEAT_SEAT_SWITCH,
  CONFIG_HEAT_HANDLE_STATUS,

  // Display settings (CONFIG_DISPLAY_)
  CONFIG_DISPLAY_SUB_MILEAGE,
  CONFIG_DISPLAY_AVE_SPEED,
  CONFIG_DISPLAY_AVE_FUEL_CONSUMPTION,
  CONFIG_DISPLAY_TRIP_TIME,
  CONFIG_DISPLAY_INSTANT_FUEL_CONSUMPTION,
  CONFIG_DISPLAY_BATTERY_VOLTAGE,
  CONFIG_DISPLAY_FRONT_REAR_TIRE_PRESSURE,
  CONFIG_DISPLAY_FRONT_REAR_TIRE_TEMP,
  CONFIG_DISPLAY_MAX_ANGLE,
  CONFIG_DISPLAY_MAX_SPEED,

  // Time settings (CONFIG_TIME_)
  CONFIG_TIME_DISPLAY_FORMAT,
  CONFIG_TIME_SET_MODE,

  // Bluetooth and trip settings (CONFIG_BT_ & CONFIG_TRIP_)
  CONFIG_TRIP_LAST_TIME_A,
  CONFIG_TRIP_LAST_TIME_B,
  CONFIG_BT_CONNECTABILITY,
  CONFIG_HEADLIGHT_AUTO_STATUS,
  CONFIG_HEADLIGHT_MANUAL_STATUS,

  // Maintenance settings (CONFIG_MAINTENANCE_)
  CONFIG_MAINTENANCE_IS_SET,
  CONFIG_MAINTENANCE_COUNT,
  CONFIG_MAINTENANCE_SINGLE_MILEAGE,
  CONFIG_MAINTENANCE_SINGLE_TIME,
  CONFIG_MAINTENANCE_LAST_MILEAGE,
  CONFIG_MAINTENANCE_LAST_TIME,

  // Tire Pressure Monitoring System (TPMS) settings (CONFIG_TPMS_)
  CONFIG_TPMS_PRESSURE_UNIT,
  CONFIG_TPMS_DETECT_SWITCH,
  CONFIG_TPMS_FRONT_MAX_PRESSURE,
  CONFIG_TPMS_FRONT_MIN_PRESSURE,
  CONFIG_TPMS_FRONT_MAX_TEMP,
  CONFIG_TPMS_REAR_MAX_PRESSURE,
  CONFIG_TPMS_REAR_MIN_PRESSURE,
  CONFIG_TPMS_REAR_MAX_TEMP,
  CONFIG_TPMS_TEMP_UNIT,

  // Maximum speed settings (CONFIG_SPEED_)
  CONFIG_SPEED_MAX_A,
  CONFIG_SPEED_MAX_B,

  // Fault code and Bluetooth TPMS information (CONFIG_FAULT_ & CONFIG_BT_TPMS_)
  CONFIG_FAULT_HISTORY_CODE,
  CONFIG_BT_TPMS_FRONT_PRESSURE,
  CONFIG_BT_TPMS_REAR_PRESSURE,
  CONFIG_BT_TPMS_FRONT_MAC_ADDR,
  CONFIG_BT_TPMS_REAR_MAC_ADDR,

  // Module check settings (CONFIG_MODULE_)
  CONFIG_MODULE_IS_CHECK,

  // Only show

  CONFIG_END,
} config_param_e;

void config_initialize(void);
void config_set_data(config_param_e index, uint32_t in_value);
uint32_t config_get_data(config_param_e index);

void config_read();
void config_save();
void config_validate_and_correct(void);

#ifdef __cplusplus
}
#endif

#endif  // CONFIG_H_

#ifndef VEH_DATA_H
#define VEH_DATA_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  // Battery and Fuel Data
  VEH_VOLTAGE_BATTERY = 0x00,    // Battery voltage, precision 0.1
  VEH_FUEL_CONSUMPTION_A,        // Fuel consumption A, precision 0.1
  VEH_FUEL_CONSUMPTION_B,        // Fuel consumption B, precision 0.1
  VEH_FUEL_CONSUMPTION_INSTANT,  // Instant fuel consumption, precision 0.001

  // Speed Data
  VEH_SPEED_AVG_A,    // Average speed A (km/h), precision 0.1
  VEH_SPEED_AVG_B,    // Average speed B (km/h), precision 0.1
  VEH_SPEED_CURRENT,  // Current vehicle speed (km/h)
  VEH_SPEED_ENGINE,   // Engine speed

  // Mileage Data
  VEH_MILEAGE_ENDURANCE,  // Endurance mileage, precision 0.1
  VEH_MILEAGE_TOTAL,      // Total mileage (km), precision 0.1
  VEH_MILEAGE_SUB_A,      // Subtotal mileage A (km), precision 0.1
  VEH_MILEAGE_SUB_B,      // Subtotal mileage B (km), precision 0.1

  // Temperature Data
  VEH_TEMP_WATER,        // Water temperature (℃ ), precision 0.1
  VEH_TEMP_WATER_LEVEL,  // Coolant temperature level, 0-9 levels

  // Light and Indicator Status
  VEH_LIGHT_HIGH_BEAM,        // High beam, 0: off, 1: on
  VEH_INDICATOR_TURN_LEFT,    // Left turn signal, 0: off, 1: on
  VEH_INDICATOR_TURN_RIGHT,   // Right turn signal, 0: off, 1: on
  VEH_LIGHT_LOCATION,         // Location LED status, 0: off, 1: on
  VEH_LIGHT_OIL_PRESSURE,     // Oil pressure lamp, 0: off, 1: on
  VEH_LIGHT_ENGINE_FAULT,     // Engine fault light, 0: off, 1: on
  VEH_LIGHT_TIRE,             // Tire alarm 0: off, 1: on
  VEH_LIGHT_AUTO_START_STOP,  // 0: off, 1: on
  VEH_LIGHT_ABS,              // 0: off, 1: on
  VEH_LIGHT_WIFI,             // 0: off, 1: on

  // Gear and Oil Data
  VEH_GEAR_POSITION,  // Gear position, 0x01-0x06: 1-6 gears, 0: neutral
  VEH_OIL_LEVEL,      // Oil level, scale value: 0-6

  // Ignition and Side Stand Status
  VEH_IGNITION_SIGNAL,  // Ignition electric signal, 0: OFF, 1: ON
  VEH_IGNITION_STATUS,  // Ignition status, 0: OFF, 1: ON
  VEH_SIDE_STAND,       // Side stand status, 0: not deployed, 1: deployed

  // Maintenance Reminder
  VEH_MAINT_REMINDER,  // Maintenance reminder, 0: hidden, 1: required

  // WIFI

  // Bluetooth and Phone Status
  VEH_BT_DEV_STATE,      // Bluetooth device state, >=1: powered on and working
  VEH_BT_SWITCH_STATUS,  // Bluetooth switch status, 0: off, 1: on
  VEH_BT_CONNECTED_STATUS,  // Bluetooth connection status, 0: disconnected, 1:
                            // connected
  VEH_BT_PHONEBOOK_STATE,   // Phonebook state, 0: not downloaded, 1:
                            // downloading, 2: completed
  VEH_BT_PHONEBOOK_COUNT,   // Phonebook contact count
  VEH_BT_CALLLOG_STATE,  // Call log state, 0: not downloaded, 1: downloading,
                         // 2: completed
  VEH_BT_CALLLOG_COUNT,  // Call log count
  VEH_BT_CALL_STATE,     // Bluetooth call state, 0: unsupported, 1-6: various
                         // states
  VEH_BT_PHONE_SIGNAL,   // Phone signal level, 0-5
  VEH_BT_PHONE_BATTERY,  // Phone battery level, 0-5

  // Weather and Navigation
  VEH_WEATHER_TYPE,  // Weather type, 0: none, 1-7: various weather types
  VEH_NAV_MODE,      // Navigation mode, 0: none, 1: basic, 2: full screen
  VEH_NAV_STATUS,    // Navigation status, 0: off, 1: on

  // Miscellaneous
  VEH_LICENSE_AUTH_FAIL,  // License authentication fail, 0: registered, 1: not
                          // registered
  VEH_ACC_OFF_STATUS,     // ACC off status, 0: connected, 1: disconnected

  // Traction Control System (TCS)
  VEH_TCS_ENABLED,  // TCS allow status, 0: not allowed, 1: allowed
  VEH_TCS_MODE,     // TCS mode, 0x00: standard, 0x01: off, 0x02: performance
  VEH_TCS_WARNING,  // TCS warning lamp, 0: off, 1: on

  // Launch Control
  VEH_LAUNCH_CONTROL_STATUS,  // Launch control status, 0: OFF, 1: ON
  VEH_LAUNCH_CONTROL_SWITCH,  // Launch control switch, 0: OFF, 1: ON

  VEH_DATA_END,
} veh_data_e;

void veh_init();
int32_t veh_get_data(uint32_t id);
void veh_set_data(uint32_t id, int32_t value);

#ifdef __cplusplus
}
#endif

#endif  // VEH_DATA_H

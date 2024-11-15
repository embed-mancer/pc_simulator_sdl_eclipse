#include "config.h"
#include <stdlib.h>
#include "../third/json/json_utils.h"
#include "../tool/enums.h"

#define CONFIG_FILE "config.json"
#define INVALID_CONFIG_DATA INT32_MAX
#define CONFIG_ITEM(name) [name] = {#name}

uint32_t *vehicle_data;

typedef struct {
  const char *name;
} config_param_mapping_t;

static const config_param_mapping_t config_param_mappings[] = {
    CONFIG_ITEM(CONFIG_UI_THEME),
    CONFIG_ITEM(CONFIG_UI_DISTANCE_UNIT),
    CONFIG_ITEM(CONFIG_UI_LED_LEVEL),
    CONFIG_ITEM(CONFIG_UI_LANGUAGE),
    CONFIG_ITEM(CONFIG_DAYNIGHT_SETTING_DAY_NIGHT),
    CONFIG_ITEM(CONFIG_DAYNIGHT_DISPLAY_DAY_NIGHT),
    CONFIG_ITEM(CONFIG_HEAT_SEAT_SWITCH),
    CONFIG_ITEM(CONFIG_HEAT_HANDLE_STATUS),
    CONFIG_ITEM(CONFIG_DISPLAY_SUB_MILEAGE),
    CONFIG_ITEM(CONFIG_DISPLAY_AVE_SPEED),
    CONFIG_ITEM(CONFIG_DISPLAY_AVE_FUEL_CONSUMPTION),
    CONFIG_ITEM(CONFIG_DISPLAY_TRIP_TIME),
    CONFIG_ITEM(CONFIG_DISPLAY_INSTANT_FUEL_CONSUMPTION),
    CONFIG_ITEM(CONFIG_DISPLAY_BATTERY_VOLTAGE),
    CONFIG_ITEM(CONFIG_DISPLAY_FRONT_REAR_TIRE_PRESSURE),
    CONFIG_ITEM(CONFIG_DISPLAY_FRONT_REAR_TIRE_TEMP),
    CONFIG_ITEM(CONFIG_DISPLAY_MAX_ANGLE),
    CONFIG_ITEM(CONFIG_DISPLAY_MAX_SPEED),
    CONFIG_ITEM(CONFIG_TIME_DISPLAY_FORMAT),
    CONFIG_ITEM(CONFIG_TIME_SET_MODE),
    CONFIG_ITEM(CONFIG_TRIP_LAST_TIME_A),
    CONFIG_ITEM(CONFIG_TRIP_LAST_TIME_B),
    CONFIG_ITEM(CONFIG_BT_CONNECTABILITY),
    CONFIG_ITEM(CONFIG_HEADLIGHT_AUTO_STATUS),
    CONFIG_ITEM(CONFIG_HEADLIGHT_MANUAL_STATUS),
    CONFIG_ITEM(CONFIG_MAINTENANCE_IS_SET),
    CONFIG_ITEM(CONFIG_MAINTENANCE_COUNT),
    CONFIG_ITEM(CONFIG_MAINTENANCE_SINGLE_MILEAGE),
    CONFIG_ITEM(CONFIG_MAINTENANCE_SINGLE_TIME),
    CONFIG_ITEM(CONFIG_MAINTENANCE_LAST_MILEAGE),
    CONFIG_ITEM(CONFIG_MAINTENANCE_LAST_TIME),
    CONFIG_ITEM(CONFIG_TPMS_PRESSURE_UNIT),
    CONFIG_ITEM(CONFIG_TPMS_DETECT_SWITCH),
    CONFIG_ITEM(CONFIG_TPMS_FRONT_MAX_PRESSURE),
    CONFIG_ITEM(CONFIG_TPMS_FRONT_MIN_PRESSURE),
    CONFIG_ITEM(CONFIG_TPMS_FRONT_MAX_TEMP),
    CONFIG_ITEM(CONFIG_TPMS_REAR_MAX_PRESSURE),
    CONFIG_ITEM(CONFIG_TPMS_REAR_MIN_PRESSURE),
    CONFIG_ITEM(CONFIG_TPMS_REAR_MAX_TEMP),
    CONFIG_ITEM(CONFIG_TPMS_TEMP_UNIT),
    CONFIG_ITEM(CONFIG_SPEED_MAX_A),
    CONFIG_ITEM(CONFIG_SPEED_MAX_B),
    CONFIG_ITEM(CONFIG_FAULT_HISTORY_CODE),
    CONFIG_ITEM(CONFIG_BT_TPMS_FRONT_PRESSURE),
    CONFIG_ITEM(CONFIG_BT_TPMS_REAR_PRESSURE),
    CONFIG_ITEM(CONFIG_BT_TPMS_FRONT_MAC_ADDR),
    CONFIG_ITEM(CONFIG_BT_TPMS_REAR_MAC_ADDR),
    CONFIG_ITEM(CONFIG_MODULE_IS_CHECK),
};

void config_initialize(void) {
  vehicle_data = (uint32_t *)malloc(CONFIG_END * sizeof(uint32_t));
  if (!vehicle_data) {
    return;
  }
  for (int i = 0; i < CONFIG_END; ++i) {
    vehicle_data[i] = 0;
  }
  config_read();
  config_validate_and_correct();
}

const char *config_param_to_string(config_param_e param) {
  if (param < CONFIG_END) {
    return config_param_mappings[param].name;
  }
  return "UNKNOWN_PARAM";
}

void config_set_data(config_param_e index, uint32_t value) {
  if (index < CONFIG_END) {
    vehicle_data[index] = value;
  }
}

uint32_t config_get_data(config_param_e index) {
  if (index < CONFIG_END) {
    return vehicle_data[index];
  }
  return INVALID_CONFIG_DATA;
}

void config_read() {
  cJSON *content = json_utils_read_json(CONFIG_FILE);
  if (content == NULL) {
    return;
  }

  for (config_param_e param = CONFIG_UI_THEME; param < CONFIG_END; ++param) {
    uint32_t value = json_utils_get_int(content, config_param_to_string(param));
    config_set_data(param, value);
  }

  cJSON_Delete(content);
}

void config_save() {
  config_initialize();
  cJSON *content = json_utils_read_json(CONFIG_FILE);
  if (content == NULL) {
    return;
  }

  for (config_param_e param = CONFIG_UI_THEME; param < CONFIG_END; ++param) {
    uint32_t value = config_get_data(param);
    json_utils_modify_int(content, config_param_to_string(param), value);
  }

  json_utils_save_json(CONFIG_FILE, content);
  cJSON_Delete(content);
}

void config_validate_and_correct() {
  for (config_param_e param = CONFIG_UI_THEME; param < CONFIG_END; ++param) {
    uint32_t value = config_get_data(param);

    switch (param) {
    case CONFIG_UI_THEME:
      if (value >= THEME_COUNT) {
        config_set_data(param, 0);
      }
      break;
    case CONFIG_UI_DISTANCE_UNIT:
      if (value > 1) {
        config_set_data(param, 0);
      }
      break;
    case CONFIG_UI_LANGUAGE:
      if (value >= LANGUAGE_COUNT) {
        config_set_data(param, 0);
      }
      break;
    default:
      break;
    }
  }
}

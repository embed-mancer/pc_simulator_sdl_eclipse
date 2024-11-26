#include "veh_data.h"
#include <stddef.h>
#include "../tool/constrant.h"
#include "../tool/log.h"

#define VEH_INVALID_DATA INT32_MIN

int32_t veh_data[VEH_DATA_END] = {0};
typedef void (*veh_data_callback_t)(uint32_t new_value);
static veh_data_callback_t data_callbacks[VEH_DATA_END] = {NULL};

static inline int is_valid_id(uint32_t id) {
  return id < VEH_DATA_END;
}

static void veh_register_callback(uint32_t id, veh_data_callback_t callback) {
  if (is_valid_id(id)) {
    data_callbacks[id] = callback;
  } else {
    LOG_DEBUG("Attempt to register callback for invalid ID: %u", id);
  }
}

static void veh_set_speed_callback(uint32_t value) {
  if (value > MAX_SPEED)
    value = MAX_SPEED;

  veh_data[VEH_SPEED_CURRENT] = value;
  LOG_DEBUG("Speed change to %d km/h", value);
}

static void veh_set_rpm_callbakc(uint32_t value) {
  if (value > MAX_RPM)
    value = MAX_RPM;

  veh_data[VEH_SPEED_ENGINE] = value;
  LOG_DEBUG("Rpm change to %d RPM", value);
}

void veh_init() {
  for (uint32_t i = 0; i < VEH_DATA_END; ++i) {
    data_callbacks[i] = NULL;
  }
  // TODO
  veh_register_callback(VEH_SPEED_CURRENT, veh_set_speed_callback);
  veh_register_callback(VEH_SPEED_ENGINE, veh_set_rpm_callbakc);
  veh_set_data(VEH_SPEED_CURRENT, 60);
  veh_set_data(VEH_SPEED_ENGINE, 1200);
}

int32_t veh_get_data(uint32_t id) {
  if (is_valid_id(id)) {
    return veh_data[id];
  } else {
    LOG_DEBUG("Attempt to retrieve data for invalid ID: %u", id);
    return VEH_INVALID_DATA;
  }
}

void veh_set_data(uint32_t id, int32_t value) {
  if (!is_valid_id(id)) {
    LOG_DEBUG("Attempt to set data for invalid ID: %u", id);
    return;
  }

  if (veh_data[id] != value) {
    veh_data[id] = value;
    if (data_callbacks[id]) {
      data_callbacks[id](value);
    }
  }
}

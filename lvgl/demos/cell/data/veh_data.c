#include "veh_data.h"

#define VEH_INVALID_DATA INT32_MIN

int32_t veh_data[VEH_DATA_END] = {0};

int32_t veh_get_data(uint32_t id) {
  if (id < VEH_DATA_END)
    return veh_data[id];

  return VEH_INVALID_DATA;
}

void veh_set_data(uint32_t id, int32_t value) {
  if (id >= VEH_DATA_END)
    return;

  if (veh_data[id] != value)
    veh_data[id] = value;
}

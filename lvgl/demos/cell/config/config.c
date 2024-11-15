#include "config.h"

vehicle_data_item_s vehicle_data[CONFIG_END] = {
};

void config_set_data(vehicle_param_e index, void *value) {
  if (index < 0 || index >= CONFIG_END) return;

  switch (vehicle_data[index].type) {
    case UINT16_T:
      vehicle_data[index].value.uint16_val = *(uint16_t *)value;
      break;
    case FLOAT_T:
      vehicle_data[index].value.float_val = *(float *)value;
      break;
    case UINT32_T:
      vehicle_data[index].value.uint32_val = *(uint32_t *)value;
      break;
    case UINT8_T:
      vehicle_data[index].value.uint8_val = *(uint8_t *)value;
      break;
    default:
      break;
  }
}

void config_get_data(vehicle_param_e index, void *out_value) {
  if (index < 0 || index >= CONFIG_END) return;

  datatype_e type = vehicle_data[index].type;
  switch (type) {
    case UINT16_T:
      *(uint16_t *)out_value = vehicle_data[index].value.uint16_val;
      break;
    case FLOAT_T:
      *(float *)out_value = vehicle_data[index].value.float_val;
      break;
    case UINT32_T:
      *(uint32_t *)out_value = vehicle_data[index].value.uint32_val;
      break;
    case UINT8_T:
      *(uint8_t *)out_value = vehicle_data[index].value.uint8_val;
      break;
    default:
      break;
  }
}

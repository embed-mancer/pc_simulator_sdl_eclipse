#ifndef CONFIG_H_
#define CONFIG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  BIT_T,
  UINT8_T,
  UINT16_T,
  UINT32_T,
  FLOAT_T,
} datatype_e;

typedef enum {
  CONFIG_SPEED,
  CONFIG_TEMPERATURE,
  CONFIG_ODOMETER,
  CONFIG_FAULT_CODE,
  CONFIG_END
} config_data_e;

typedef union {
  uint32_t uint32_val;
  uint16_t uint16_val;
  float float_val;
  uint8_t uint8_val;
} vehicle_value_u;

typedef struct {
  datatype_e type;
  vehicle_value_u value;
} vehicle_data_item_s;

void config_set_data(config_data_e index, void *in_value);
void config_get_data(config_data_e index, void *out_value);

#ifdef __cplusplus
}
#endif

#endif  // CONFIG_H_

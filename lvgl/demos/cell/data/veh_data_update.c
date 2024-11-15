#include "veh_data_update.h"
#include "veh_data.h"
#include "../light/light_model.h"
#include "../other/motor_model.h"

static void update_signal_light(int signa_id, uint32_t id) {
  int32_t state = veh_get_data(id);
  light_model_set_state(signa_id, state);
}

void veh_update_light() {
  update_signal_light(SIGNAL_LIGHT_TURN_LEFT, VEH_INDICATOR_TURN_LEFT);
  update_signal_light(SIGNAL_LIGHT_TURN_RIGHT, VEH_INDICATOR_TURN_RIGHT);
  update_signal_light(SIGNAL_LIGHT_AUTO_START_STOP, VEH_LIGHT_AUTO_START_STOP);
  update_signal_light(SIGNAL_LIGHT_HIGH_BEAM, VEH_LIGHT_HIGH_BEAM);
  update_signal_light(SIGNAL_LIGHT_TIRE, VEH_LIGHT_TIRE);
  update_signal_light(SIGNAL_LIGHT_ABS, VEH_LIGHT_ABS);
  update_signal_light(SIGNAL_LIGHT_OIL_PRESSURE, VEH_LIGHT_OIL_PRESSURE);
  update_signal_light(SIGNAL_LIGHT_ENGINE_FAULT, VEH_LIGHT_ENGINE_FAULT);
  update_signal_light(SIGNAL_LIGHT_WIFI, VEH_LIGHT_WIFI);
  update_signal_light(SIGNAL_LIGHT_BT_ICON, VEH_BT_CONNECTED_STATUS);
  double voltage = veh_get_data(VEH_VOLTAGE_BATTERY) / 10.0;
  light_model_set_voltage(voltage);
}

void veh_update_other() {
  int32_t speed = veh_get_data(VEH_SPEED_CURRENT);
  motor_model_set_speed(speed);
  int32_t rpm = veh_get_data(VEH_SPEED_ENGINE);
  motor_model_set_rpm(rpm);
  int32_t water = veh_get_data(VEH_TEMP_WATER);
  motor_model_set_water(water);
  int32_t oil = veh_get_data(VEH_OIL_LEVEL);
  motor_model_set_oil(oil);
  int32_t gear = veh_get_data(VEH_GEAR_POSITION);
  motor_model_set_gear(gear);
  int32_t odo = veh_get_data(VEH_MILEAGE_TOTAL);
  motor_model_set_odo(odo);
  double trip = veh_get_data(VEH_MILEAGE_SUB_A) / 10.0;
  motor_model_set_trip(trip);
}

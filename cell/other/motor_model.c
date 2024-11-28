#include "motor_model.h"
#include "../data/veh_data.h"

static int32_t oil                      = 0;
static int32_t water                    = 0;
static int32_t gear                     = 0;
static int32_t mode                     = 0;
static int32_t avg_speed                = 0;
static int32_t speed                    = 0;
static int32_t odo                      = 0;
static double trip                      = 0.0;
static int32_t rpm                      = 0;
static meter_mode_e current_motor_model = METER_MODE_DAY;

void motor_model_set_oil(int32_t value) {
  oil = value >= 0 ? value : 0;
}
void motor_model_set_water(int32_t value) {
  water = value >= 0 ? value : 0;
}
void motor_model_set_gear(int32_t value) {
  gear = value >= 0 ? value : 0;
}
void motor_model_set_mode(int32_t value) {
  mode = value >= 0 ? value : 0;
}
void motor_model_set_avg_speed(int32_t value) {
  avg_speed = value >= 0 ? value : 0;
}
void motor_model_set_speed(int32_t value) {
  speed = value >= 0 ? value : 0;
}
void motor_model_set_odo(int32_t value) {
  odo = value >= 0 ? value : 0;
}
void motor_model_set_trip(double value) {
  trip = value >= 0 ? value : 0.0;
}
void motor_model_set_rpm(int32_t value) {
  rpm = value >= 0 ? value : 0;
}
void motor_model_set_day_night_mode(meter_mode_e new_mode) {
  current_motor_model = new_mode;
}

int motor_model_get_oil() {
  return oil;
}
int motor_model_get_water() {
  return water;
}
int motor_model_get_gear() {
  return gear;
}
int motor_model_get_mode() {
  return mode;
}
int motor_model_get_avg_speed() {
  return avg_speed;
}
int motor_model_get_speed() {
  return veh_get_data(VEH_SPEED_CURRENT);
  // return speed;
}
int motor_model_get_odo() {
  return odo;
}
double motor_model_get_trip() {
  return trip;
}
int motor_model_get_rpm() {
  return veh_get_data(VEH_SPEED_ENGINE);
  // return rpm;
}
meter_mode_e motor_model_get_day_night_mode() {
  return current_motor_model;
}

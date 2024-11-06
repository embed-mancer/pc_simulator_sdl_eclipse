#include "motor_model.h"

static int oil = 0;
static int water = 0;
static int gear = 0;
static int mode = 0;
static int avg_speed = 0;
static int speed = 0;
static int odo = 0;
static double trip = 0.0;
static int rpm = 0;
static meter_mode_t current_motor_model = METER_MODE_DAY;

void motor_model_set_oil(int value) { oil = value >= 0 ? value : 0; }
void motor_model_set_water(int value) { water = value >= 0 ? value : 0; }
void motor_model_set_gear(int value) { gear = value >= 0 ? value : 0; }
void motor_model_set_mode(int value) { mode = value >= 0 ? value : 0; }
void motor_model_set_avg_speed(int value) {
  avg_speed = value >= 0 ? value : 0;
}
void motor_model_set_speed(int value) { speed = value >= 0 ? value : 0; }
void motor_model_set_odo(int value) { odo = value >= 0 ? value : 0; }
void motor_model_set_trip(double value) { trip = value >= 0 ? value : 0.0; }
void motor_model_set_rpm(int value) { rpm = value >= 0 ? value : 0; }
void motor_model_set_day_night_mode(meter_mode_t new_mode) {
  current_motor_model = new_mode;
}

int motor_model_get_oil() { return oil; }
int motor_model_get_water() { return water; }
int motor_model_get_gear() { return gear; }
int motor_model_get_mode() { return mode; }
int motor_model_get_avg_speed() { return avg_speed; }
int motor_model_get_speed() { return speed; }
int motor_model_get_odo() { return odo; }
double motor_model_get_trip() { return trip; }
int motor_model_get_rpm() { return rpm; }
meter_mode_t motor_model_get_day_night_mode() {
  return current_motor_model;
}

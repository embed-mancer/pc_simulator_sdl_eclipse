#ifndef MOTOR_MODEL_H_
#define MOTOR_MODEL_H_
#include "../cell.h"

void motor_model_set_oil(int value);
void motor_model_set_water(int value);
void motor_model_set_gear(int value);
void motor_model_set_mode(int value);
void motor_model_set_avg_speed(int value);
void motor_model_set_odo(int value);
void motor_model_set_trip(double value);
void motor_model_set_rpm(int value);
void motor_model_set_speed(int value);
void motor_model_set_day_night_mode(meter_mode_t new_mode);

int motor_model_get_oil();
int motor_model_get_water();
int motor_model_get_gear();
int motor_model_get_mode();
int motor_model_get_avg_speed();
int motor_model_get_odo();
double motor_model_get_trip();
int motor_model_get_rpm();
int motor_model_get_speed();
meter_mode_t motor_model_get_day_night_mode();

#endif  // MOTOR_MODEL_H_

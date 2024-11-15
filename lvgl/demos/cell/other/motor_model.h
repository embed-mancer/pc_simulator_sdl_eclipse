#ifndef MOTOR_MODEL_H_
#define MOTOR_MODEL_H_
#include "../cell.h"

void motor_model_set_oil(int32_t value);
void motor_model_set_water(int32_t value);
void motor_model_set_gear(int32_t value);
void motor_model_set_mode(int32_t value);
void motor_model_set_avg_speed(int32_t value);
void motor_model_set_odo(int32_t value);
void motor_model_set_trip(double value);
void motor_model_set_rpm(int32_t value);
void motor_model_set_speed(int32_t value);
void motor_model_set_day_night_mode(meter_mode_e new_mode);

int32_t motor_model_get_oil();
int32_t motor_model_get_water();
int32_t motor_model_get_gear();
int32_t motor_model_get_mode();
int32_t motor_model_get_avg_speed();
int32_t motor_model_get_odo();
double motor_model_get_trip();
int32_t motor_model_get_rpm();
int32_t motor_model_get_speed();
meter_mode_e motor_model_get_day_night_mode();

#endif  // MOTOR_MODEL_H_

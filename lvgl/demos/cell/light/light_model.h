/**
* @file light_model.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-09-10-50
* @author Nemausa
*
*/
#ifndef LIGHT_MODEL_H_
#define LIGHT_MODEL_H_

#ifdef __cplusplus
extern "C"
{
#endif

int light_model_get_abs();
int light_model_get_obd();
int light_model_get_high_beam();
int light_model_get_low_beam();
int light_model_get_clearance();
int light_model_get_turn_left();
int light_model_get_turn_right();
int light_model_get_location();
int light_model_get_oil_pressure();
int light_model_get_engine_fault();
int light_model_get_brake();
int light_model_get_gps();
int light_model_get_key();
double light_model_get_voltage();
int light_model_get_wifi();
int light_model_get_bt();
int light_model_get_maintain();
int light_model_get_cruise();
int light_model_get_signal_strength();
int light_model_get_mode();
int light_model_get_tpms();
int light_model_get_tcs();
int light_model_get_mirror();
int light_model_get_park();
int light_model_get_auto_hold();
int light_model_get_water();

void light_model_set_abs(int);
void light_model_set_obd(int);
void light_model_set_high_beam(int);
void light_model_set_low_beam(int);
void light_model_set_clearance(int);
void light_model_set_turn_left(int);
void light_model_set_turn_right(int);
void light_model_set_location(int);
void light_model_set_oil_pressure(int);
void light_model_set_engine_fault(int);
void light_model_set_brake(int);
void light_model_set_gps(int);
void light_model_set_key(int);
void light_model_set_voltage(double);
void light_model_set_wifi(int);
void light_model_set_bt(int);
void light_model_set_maintain(int);
void light_model_set_cruise(int);
void light_model_set_signal_strength(int);
void light_model_set_mode(int);
void light_model_set_tpms(int);
void light_model_set_tcs(int);
void light_model_set_park(int);
void light_model_set_auto_hold(int);
void light_model_set_water(int);

#ifdef __cplusplus
}
#endif


#endif // LIGHT_MODEL_H_
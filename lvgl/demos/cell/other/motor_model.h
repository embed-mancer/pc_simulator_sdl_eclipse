#ifndef MOTOR_MODEL_H_
#define MOTOR_MODEL_H_
#include "../cell.h"

void MotorModelSetOil(int value);
void MotorModelSetWater(int value);
void MotorModelSetGear(int value);
void MotorModelSetMode(int value);
void MotorModelSetAvgSpeed(int value);
void MotorModelSetODO(int value);
void MotorModelSetTrip(double value);
void MotorModelSetRpm(int value);
void MotorModelSetSpeed(int value);
void MotorModelSetTheme(ThemeTable new_theme);

int MotorModelGetOil();
int MotorModelGetWater();
int MotorModelGetGear();
int MotorModeGetMode();
int MotorModelGetAvgSpeed();
int MotorModelGetODO();
double MotorModelGetTrip();
int MotorModelGetRpm();
int MotorModelGetSpeed();
ThemeTable MotorModelGetTheme();

#endif  // MOTOR_MODEL_H_

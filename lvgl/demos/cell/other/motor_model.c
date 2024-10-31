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
static DayNightMode current_day_night_mode = kNight;

void MotorModelSetOil(int value) { oil = value >= 0 ? value : 0; }
void MotorModelSetWater(int value) { water = value >= 0 ? value : 0; }
void MotorModelSetGear(int value) { gear = value >= 0 ? value : 0; }
void MotorModelSetMode(int value) { mode = value >= 0 ? value : 0; }
void MotorModelSetAvgSpeed(int value) { avg_speed = value >= 0 ? value : 0; }
void MotorModelSetSpeed(int value) { speed = value >= 0 ? value : 0; }
void MotorModelSetODO(int value) { odo = value >= 0 ? value : 0; }
void MotorModelSetTrip(double value) { trip = value >= 0 ? value : 0.0; }
void MotorModelSetRpm(int value) { rpm = value >= 0 ? value : 0; }
void MotorModelSetDayNightMode(DayNightMode new_mode) {
  current_day_night_mode = mode;
}

int MotorModelGetOil() { return oil; }
int MotorModelGetWater() { return water; }
int MotorModelGetGear() { return gear; }
int MotorModelGetMode() { return mode; }
int MotorModelGetAvgSpeed() { return avg_speed; }
int MotorModelGetSpeed() { return speed; }
int MotorModelGetODO() { return odo; }
double MotorModelGetTrip() { return trip; }
int MotorModelGetRpm() { return rpm; }
DayNightMode MotorModelGetDayNightMode() { return current_day_night_mode; }

#include "motor_model.h"

static int oil = 0;
static int water = 0;
static int gear = 0;
static int mode = 0;
static int avg_speed = 0;
static int odo = 0;
static double trip = 0;
static int rpm = 0;


void MotorModelSetOil(int value) {
  oil = value;
}

void MotorModelSetWater(int value) {
  water = value;
}

void MotorModelSetGear(int value) {
  gear = value;
}

void MotorModelSetMode(int value) {
  mode = value;
}

void MotorModelSetAvgSpeed(int value) {
  avg_speed = value;
}

void MotorModelSetODO(int value) {
  odo = value;
}

void MotorModelSetTrip(int value) {
  trip = value / 10.0;
}

void MotorModelSetRpm(int value) {
  rpm = value;
}

int MotorModelGetOil() {
  return oil;
}

int MotorModelGetWater() {
  return water;
}

int MotorModelGetGear() {
  return water;
}

int MotorModeGetMode() {
  return mode;
}

int MotorModelGetAvgSpeed() {
  return avg_speed;
}

int MotorModelGetODO() {
  return odo;
}

double MotorModelGetTrip() {
  return trip;
}

int MotorModelGetRpm() {
  return rpm;
}

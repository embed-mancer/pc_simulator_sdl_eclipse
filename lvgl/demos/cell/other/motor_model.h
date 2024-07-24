/**
* @file motor_model.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-23-17-43
* @author Nemausa
*
*/
#ifndef MOTOR_MODEL_H_
#define MOTOR_MODEL_H_

#ifdef __cplusplus
extern "C"
{
#endif

void MotorModelSetOil(int value);
void MotorModelSetWater(int value);
void MotorModelSetGear(int value);
void MotorModelSetMode(int value);
void MotorModelSetAvgSpeed(int value);
void MotorModelSetODO(int value);
void MotorModelSetTrip(int value);
void MotorModelSetRpm(int value);

int MotorModelGetOil();
int MotorModelGetWater();
int MotorModelGetGear();
int MotorModeGetMode();
int MotorModelGetAvgSpeed();
int MotorModelGetODO();
double MotorModelGetTrip();
int MotorModelGetRpm();

#ifdef __cplusplus
}
#endif


#endif // MOTOR_MODEL_H_
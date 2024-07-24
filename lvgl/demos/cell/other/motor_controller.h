/**
* @file motor_controller.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-23-18-00
* @author Nemausa
*
*/
#ifndef MOTOR_CONTROLLER_H_
#define MOTOR_CONTROLLER_H_

#include "../view/gear_view.h"

#ifdef __cplusplus
extern "C"
{
#endif

void NotifyGear(GearView *view);

#ifdef __cplusplus
}
#endif


#endif // MOTOR_CONTROLLER_H_
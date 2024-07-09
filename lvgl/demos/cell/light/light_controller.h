/**
* @file light_controller.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-09-11-06
* @author Nemausa
*
*/
#ifndef LIGHT_CONTROLLER_H_
#define LIGHT_CONTROLLER_H_

#include "light_view.h"
#include "light_model.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LightNotifyAbs(LightView *view);
void LightNotifyTurnLeft(LightView *view);
void LightNotifyTurnRight(LightView *view);

#ifdef __cplusplus
}
#endif


#endif // LIGHT_CONTROLLER_H_
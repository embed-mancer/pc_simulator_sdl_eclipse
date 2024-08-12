/**
* @file checkself.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-12-15-10
* @author Nemausa
*
*/
#ifndef CHECKSELF_H_
#define CHECKSELF_H_

#include "lvgl/lvgl.h"

void CheckSelfInit();
void CheckSelfFinish();
bool CheckSelfIsChecking();
void CheckSelfChecking(bool is_checking);

#endif // CHECKSELF_H_
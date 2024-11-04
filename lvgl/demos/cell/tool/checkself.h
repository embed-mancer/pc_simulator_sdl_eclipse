#ifndef CHECKSELF_H_
#define CHECKSELF_H_

#include "lvgl/lvgl.h"

void CheckSelfInit();
void CheckSelfFinish();
bool CheckSelfIsChecking();
void CheckSelfChecking(bool is_checking);

#endif // CHECKSELF_H_
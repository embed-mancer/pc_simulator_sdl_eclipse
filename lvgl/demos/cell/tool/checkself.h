#ifndef CHECKSELF_H_
#define CHECKSELF_H_

#include "lvgl/lvgl.h"

void checkself_init();
void checkself_finish();
bool checkself_is_checking();
void checkself_set_checking(bool is_checking);

#endif  // CHECKSELF_H_

#ifndef SCREEN_INTERFACE_H_
#define SCREEN_INTERFACE_H_

#include "lvgl/lvgl.h"
#include "../cell.h"

void set_screen_color(lv_obj_t*, lv_color_t);
window_e get_window();
void set_window(window_e);

#endif  // SCREEN_INTERFACE_H_

/**
 * @file main_window.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-25-14-04
 * @author Nemausa
 *
 */
#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "lvgl/lvgl.h"
#include "../tool/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

void main_window_init();
void main_window_signal_light();
void main_window_gear();
void main_window_oil();
void main_window_water();
void main_window_rpm();
void main_window_speed();
void main_window_other();
void main_window_time();
void main_window_blink();
void main_window_toggle_day_night();
lv_obj_t *main_window_get();
void main_window_click(click_e click);
void main_window_switch_language();

#ifdef __cplusplus
}
#endif

#endif  // MAIN_WINDOW_H_

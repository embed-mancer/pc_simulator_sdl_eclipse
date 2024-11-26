/**
 * @file mobile_window.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-25-13-49
 * @author Nemausa
 *
 */
#ifndef MOBILE_WINDOW_H_
#define MOBILE_WINDOW_H_

#include "lvgl/lvgl.h"
#include "../tool/enums.h"

#ifdef __cplusplus
extern "C" {
#endif

void mobile_window_init();
void mobile_window_destroy();
lv_obj_t *mobile_window_get();
void mobile_window_click(click_e click);

#ifdef __cplusplus
}
#endif

#endif  // MOBILE_WINDOW_H_

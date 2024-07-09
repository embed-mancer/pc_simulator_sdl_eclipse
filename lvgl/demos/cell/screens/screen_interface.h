/**
* @file screen_interface.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-08-17-04
* @author Nemausa
*
*/
#ifndef SCREEN_INTERFACE_H_
#define SCREEN_INTERFACE_H_

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C"
{
#endif

void set_screen_color(lv_obj_t*, lv_color_t);

#ifdef __cplusplus
}
#endif


#endif // SCREEN_INTERFACE_H_
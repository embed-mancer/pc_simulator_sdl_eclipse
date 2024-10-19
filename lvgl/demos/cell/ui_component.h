/**
* @file ui_component.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-10-13-16-36
* @author Nemausa
*
*/
#ifndef UI_COMPONENT_H_
#define UI_COMPONENT_H_

#include "cell.h"
#include <stddef.h>
#include <lvgl/lvgl.h>

typedef struct ui_component{
  void (*refresh)();
  void (*click)(ClickTable id);
  void (*switch_display)();
  void (*destory)();
  void (*open_window);
  void (*close_window);
} UIComponent; 

#endif // UI_COMPONENT_H_

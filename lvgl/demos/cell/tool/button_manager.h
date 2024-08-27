/**
* @file button_manager.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-27-10-02
* @author Nemausa
*
*/
#ifndef BUTTON_MANAGER_HPP_
#define BUTTON_MANAGER_HPP_

#include "lvgl/lvgl.h"

typedef enum {
  kShortSet,
  kLongSet,
  kShortDown,
  kLongDown,
  kButtonEnd,
} ClickTable;

#ifdef __cplusplus
extern "C"
{
#endif

void ButtonManagerInit();
void ButtonManagerHandle();
void ButtonManagerRefresh();
void ButtongManagerEvent(lv_event_t *e);


#ifdef __cplusplus
}
#endif


#endif // BUTTON_MANAGER_HPP_

#ifndef BUTTON_MANAGER_H_
#define BUTTON_MANAGER_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

void button_manager_set_click(click_e click);
click_e button_manager_get_click();
void button_manager_handle();
void button_manager_refresh();
void button_manager_event(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif  // BUTTON_MANAGER_H_

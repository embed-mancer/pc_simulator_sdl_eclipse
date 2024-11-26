#ifndef MENU_WINDOW_H_
#define MENU_WINDOW_H_

#include "../menu/menu_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

void menu_window_init();
void menu_window_toggle_display();
void menu_window_destroy();
lv_obj_t* menu_window_get();
void menu_window_delete();

#ifdef __cplusplus
}
#endif

#endif  // MENU_WINDOW_H_

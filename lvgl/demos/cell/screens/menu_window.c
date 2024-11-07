#include "menu_window.h"
#include "../menu/menu_manager.h"
#include "screen_interface.h"
#include "../key/button_manager.h"

lv_obj_t *menu_window = NULL;

void menu_window_task_cb(lv_timer_t *timer) {
  button_manager_refresh();  
}

void menu_window_init() {
  menu_window = lv_obj_create(NULL);
  lv_scr_load(menu_window);
  tool_init();
  set_screen_color(menu_window, lv_color_black());
  menu_manager();
  lv_timer_t *timer = lv_timer_create(menu_window_task_cb, 50, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

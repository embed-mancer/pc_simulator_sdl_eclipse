#include "menu_window.h"
#include "../menu/menu_manager.h"
#include "../key/button_manager.h"
#include "../config/config.h"
#include "../screens/window_manager.h"

static lv_obj_t *window  = NULL;
static lv_timer_t *timer = NULL;

static void task_cb(lv_timer_t *task_timer __attribute__((unused))) {
  if (window_manager_get() != WINDOW_MENU)
    return;
  menu_manager_refresh();
}

void menu_window_init() {
  window = lv_obj_create(NULL);
  menu_window_toggle_display();
  menu_manager();
  timer = lv_timer_create(task_cb, 50, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void menu_window_toggle_display() {
  if (config_get_data(CONFIG_DAYNIGHT_DISPLAY) == METER_MODE_DAY)
    lv_obj_set_style_bg_color(window, lv_color_white(), 0);
  else
    lv_obj_set_style_bg_color(window, lv_color_black(), 0);
}

void menu_window_destroy() {
  window_manager_set_target(WINDOW_MAIN);
  if (timer) {
    lv_timer_del(timer);
    timer = NULL;
  }
}

lv_obj_t *menu_window_get() {
  return window;
}

void menu_window_delete() {
  if (window) {
    lv_obj_del(window);
    window = NULL;
  }
}

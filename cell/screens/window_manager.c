#include "window_manager.h"
#include "main_window.h"
#include "menu_window.h"
#include "mobile_window.h"

static window_e active_window   = WINDOW_MAIN;
static window_e previous_window = WINDOW_NULL;

static void window_manager_update_task(lv_timer_t *timer __attribute__((unused))) {
  window_manager_switch();
}

void window_manager_init() {
  LOG_INFO("Window Manager Initialized");
  lv_timer_t *timer = lv_timer_create(window_manager_update_task, 33, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void window_manager_switch() {
  static window_e current_window = WINDOW_NULL;

  if (current_window != active_window) {
    previous_window = current_window;

    lv_obj_t *new_window = NULL;
    switch (active_window) {
    case WINDOW_MAIN:
      new_window = main_window_get();
      if (previous_window == WINDOW_MENU)
        main_window_switch_language();
      break;
    case WINDOW_MENU:
      new_window = menu_window_get();
      break;
    case WINDOW_MOBILE:
      new_window = mobile_window_get();
      break;
    default:
      LOG_WARN("Unknown window type: %d", active_window);
      return;
    }

    if (new_window) {
      lv_scr_load(new_window);
    }

    if (current_window == WINDOW_MAIN && previous_window == WINDOW_MENU) {
      menu_window_delete();
    }

    current_window = active_window;
  }
}

bool window_manager_is_active(window_e window_id) {
  return active_window == window_id;
}

void window_manager_set_target(window_e new_window) {
  active_window = new_window;
}

window_e window_manager_get() {
  return active_window;
}

#include "menu_manager.h"
#include <stdlib.h>

#include "../key/button_manager.h"
#include "settings.h"
#include "button_control.h"
#include "../screens/menu_window.h"

screen_t* current_screen = NULL;

void menu_manager() {
  button_control_init();
  settings_init();
}

void menu_manager_refresh() {
  button_control_refresh();
  current_screen = nav_state->current_screen;
  if (current_screen)
    current_screen->component->refresh();
}

static void update_tick() {
}

void menu_manager_click(const click_e click) {
  update_tick();
  current_screen = nav_state->current_screen;
  current_screen->component->handle_click_event(click);
  if (nav_state)
    button_control_update(click);
}

void menu_manager_default_click(const click_e click) {
  switch (click) {
  case CLICK_SHORT_SET:
    break;
  case CLICK_SHORT_BACK:
    return;
  case CLICK_SHORT_UP:
    break;
  case CLICK_SHORT_DOWN:
    break;
  default:
    break;
  }
}

void menu_manager_toggle_day_night() {
}

void menu_manager_destroy() {
  menu_window_destroy();
}

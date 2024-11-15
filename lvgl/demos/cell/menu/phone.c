#include "phone.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "side_bar.h"
#include "menu_navigate.h"

static bool is_active                = false;
static navigation_state_t* nav_state = NULL;

static void refresh() {
}

static bool handle_click_event(const click_e click) {
  switch (click) {
  case CLICK_SHORT_SET:
    is_active = true;
    break;
  case CLICK_SHORT_BACK:
    is_active = false;
    break;
  case CLICK_LONG_SET:
    break;
  case CLICK_LONG_BACK:
    break;
  default:
    return false;
  }
  return is_active;
}

static void toggle_day_night() {
}

static void destroy() {
  menu_navigate_free(nav_state);
}

static void open_window() {
  screen_t* screen =
      menu_navigate_create_screen(0, "phone preview", NULL, 0, 20);
  preview_phone(screen->elements);
  nav_state = menu_navigate_create(screen);
}

static void close_window() {
}

menu_component_t* phone() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}

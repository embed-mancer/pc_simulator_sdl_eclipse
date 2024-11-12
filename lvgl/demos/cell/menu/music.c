#include "music.h"
#include "../cell.h"
static bool is_active = false;

static void refresh() {}

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
  if (!is_active)
    return false; 
  return true;
}

static void toggle_day_night() {}

static void destroy() {}

static void open_window() {}

static void close_window() {}

menu_component_t* music() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}

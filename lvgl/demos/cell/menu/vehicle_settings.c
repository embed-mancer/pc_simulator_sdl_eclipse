#include "vehicle_settings.h"
#include "../cell.h"

static item_t* items[5];
static bool is_active = false;
extern lv_obj_t* menu_window;

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

static void reset_items() {
  for (int i = 0; i < 5; ++i) items[i] = NULL;
}

static void open_window() {
  return;
  reset_items();
  create_item(&items[0], 10, TEXT_ID_BASIC_INFO, NULL, true);
  create_item(&items[1], 80, TEXT_ID_ODO, NULL, true);
  create_item(&items[2], 150, TEXT_ID_TRIP, NULL, true);
  create_item(&items[3], 220, TEXT_ID_FAULT_INFO, "2条", true);
  create_item(&items[4], 290, TEXT_ID_MAINTAIN_MILEAGE, "500km", false);
  set_item_color(&items[0], true);
}

static void close_window() {}

menu_component_t* vehicle_settings() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}

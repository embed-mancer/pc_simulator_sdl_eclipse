#include "settings.h"
#include "../tool/tool.h"
#include "../screens/mobile_window.h"

#define SETTINGS_COUNT 3
static int y_pos[6];

extern void vehicle_init();
extern void fault_init();

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  switch (nav_state->selected_index) {
  case 0:
    vehicle_init();
    break;
  case 1:
    fault_init();
    break;
  case 2:
    mobile_window_init();
    break;
  }
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void update_selection_display() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[6], y_pos[nav_state->selected_index] + 6);
}

static void handle_up() {
  if (nav_state->selected_index == 0) {
    nav_state->prev->selected_index = 5;
    menu_navigate_go_back(&nav_state);
    return;
  }
  update_index(DIRECTION_UP);
  update_selection_display();
}

static void handle_down() {
  if (nav_state->selected_index == 2) {
    nav_state->prev->selected_index = 0;
    menu_navigate_go_back(&nav_state);
    return;
  }
  update_index(DIRECTION_DOWN);
  update_selection_display();
}

static click_handler_t click_handlers[] = {
    [CLICK_SHORT_SET]  = handle_set,
    [CLICK_SHORT_BACK] = handle_back,
    [CLICK_SHORT_UP]   = handle_up,
    [CLICK_SHORT_DOWN] = handle_down,
};

static bool handle_click_event(const click_e click) {
  if (click < sizeof(click_handlers) / sizeof(click_handler_t) &&
      click_handlers[click]) {
    click_handlers[click]();
  }
  print_navigation_state(nav_state);
  return true;
}

static void toggle_day_night() {
}

static void destroy() {
  menu_navigate_free(&nav_state);
}

static void open_window() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  ui_helpers_menu_image(elements, "selected.png", 6, 292, 70);

  y_pos[2] = 188;
  for (size_t i = 0; i < 2; ++i) {
    y_pos[i] = 64 + 62*i;
    ui_helpers_menu_image(elements, "arrow_down.png", 7+i, 755, y_pos[i] + 27);
    ui_helpers_menu_image(elements, "line.png", 13+i, 292, y_pos[i]+ 62);
  }
  ui_helpers_menu_image(elements, "arrow_down.png", 12, 755, y_pos[2] + 27);

  lv_obj_t *parent    = menu_window_get();
  label_font_e font   = LABEL_FONT_HARMONYOS_24;
  label_color_e color = tool_get_color_base();
  ui_helpers_create_label_left(parent, &elements[0], 320, y_pos[0], 300, 62, color,
                               font, lang_text(TEXT_ID_VEHICLE));
  ui_helpers_create_label_left(parent, &elements[1], 320, y_pos[1], 300, 62, color,
                               font, lang_text(TEXT_ID_FAULT));
  ui_helpers_create_label_left(parent, &elements[2], 320, y_pos[2], 300, 62, color,
                               font, lang_text(TEXT_ID_MOBILE));
  update_selection_display();
}

static void close_window() {
}

static void on_return() {
  button_control_set_title(TEXT_ID_SETTINGS);
}

void settings2_init(int index) {
  menu_item_t *items = (menu_item_t *)malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"setting vehicle", SETTING_VEHICLE, OPTION_PAGE};
  items[1] = (menu_item_t){"setting fault", SETTING_FAULT, OPTION_PAGE};
  items[2] = (menu_item_t){"setting mobile", SETTING_MOBILE, OPTION_PAGE};

  screen_t *screen =
      menu_navigate_create_screen(SETTING_MAIN, "setting 2", items, 3, 20);
  menu_component_t *component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  nav_state->selected_index            = index;
  nav_state->current_screen->on_return = on_return;
  open_window();
}

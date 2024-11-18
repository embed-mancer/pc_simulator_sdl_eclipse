#include "settings.h"
#include "../tool/tool.h"
#include "menu_manager.h"
#include "button_control.h"

navigation_state_t *nav_state = NULL;
bool is_active                = true;

extern void display_init();
extern void backlight_init();
extern void bluetooth_init();
extern void clock_init();
extern void unit_init();
extern void language_init();
extern void settings2_init();

static const void (*setting_init_handlers[])(void) = {
    display_init, backlight_init, bluetooth_init,
    clock_init,   unit_init,      language_init};

static void update_selection_display() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[6], 70 + 60 * nav_state->selected_index);
}

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  if (nav_state->selected_index >= 0 &&
      nav_state->selected_index <
          sizeof(setting_init_handlers) / sizeof(setting_init_handlers[0])) {
    setting_init_handlers[nav_state->selected_index]();
  }
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
  menu_manager_destroy();
  menu_navigate_free(&nav_state);
  button_control_destroy();
}

static void handle_up() {
  if (nav_state->selected_index == 0) {
    settings2_init(2);
    return;
  }
  update_index(DIRECTION_UP);
  update_selection_display();
}

static void handle_down() {
  if (nav_state->selected_index == 5) {
    settings2_init(0);
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
  // print_navigation_state(nav_state);
  return is_active;
}

static void toggle_day_night() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  menu_component_t *component = nav_state->current_screen->component;
  if (component->last_mode == motor_model_get_day_night_mode())
    return;
  lv_color_t color    = tool_get_theme_color();
  for (int i = 0; i < 6; ++i)
    lv_obj_set_style_text_color(elements[i], color, 0);
}

static void destroy() {
  menu_navigate_free(&nav_state);
}

static void open_window() {
  lv_obj_t **elements = nav_state->current_screen->elements;

  ui_helpers_menu_image(elements, "selected.png", 6, 293, 70);

  label_params_t params = ui_helpers_params(320, 70, lang_text(TEXT_ID_DISPLAY),
                                            RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[0], &elements[10], params);

  params = ui_helpers_params(320, 130, lang_text(TEXT_ID_BACKLIGHT),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[1], &elements[11], params);

  params = ui_helpers_params(320, 190, lang_text(TEXT_ID_BLUETOOTH),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[2], &elements[12], params);

  params = ui_helpers_params(320, 250, lang_text(TEXT_ID_CLOCK),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[3], &elements[13], params);

  params = ui_helpers_params(320, 310, lang_text(TEXT_ID_UNIT),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[4], &elements[14], params);

  params = ui_helpers_params(320, 370, lang_text(TEXT_ID_LANGUAGE),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[5], &elements[15], params);
}

static void close_window() {
}

void settings_update() {
  static const language_e labels[] = {TEXT_ID_DISPLAY,   TEXT_ID_BACKLIGHT,
                                      TEXT_ID_BLUETOOTH, TEXT_ID_CLOCK,
                                      TEXT_ID_UNIT,      TEXT_ID_LANGUAGE};

  button_control_set_title(TEXT_ID_SETTINGS);
  lv_obj_t **elements = nav_state->current_screen->elements;
  update_selection_display();

  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < 6; ++i) {
    lv_label_set_text(elements[i], lang_text(labels[i]));
    lv_obj_set_style_text_color(elements[i], color, 0);
  }
}

void settings_init() {
  menu_item_t *items = (menu_item_t *)malloc(6 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"setting display", SETTING_DISPLAY, OPTION_PAGE};
  items[1] = (menu_item_t){"setting backlight", SETTING_BACKLIGHT, OPTION_PAGE};
  items[2] = (menu_item_t){"setting bluetooth", SETTING_BLUETOOTH, OPTION_PAGE};
  items[3] = (menu_item_t){"setting clock", SETTING_CLOCK, OPTION_PAGE};
  items[4] = (menu_item_t){"setting unit", SETTING_UNIT, OPTION_PAGE};
  items[5] = (menu_item_t){"setting language", SETTING_UNIT, OPTION_PAGE};

  screen_t *screen =
      menu_navigate_create_screen(SETTING_MAIN, "setting 1", items, 6, 20);
  menu_component_t *component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component                    = component;
  screen->component->last_mode         = motor_model_get_day_night_mode();
  nav_state                            = menu_navigate_create(screen);
  nav_state->current_screen->on_return = settings_update;
  open_window();
}

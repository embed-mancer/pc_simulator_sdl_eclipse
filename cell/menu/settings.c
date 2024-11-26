#include "settings.h"
#include "../tool/tool.h"
#include "menu_manager.h"
#include "button_control.h"

navigation_state_t *nav_state = NULL;
bool is_active                = true;
static int y_pos[6];

extern void display_init();
extern void backlight_init();
extern void bluetooth_init();
extern void clock_init();
extern void unit_init();
extern void language_init();
extern void settings2_init();

static void (*setting_init_handlers[])(void) = {
    display_init, backlight_init, bluetooth_init,
    clock_init,   unit_init,      language_init};

static void update_selection_display() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[6], y_pos[nav_state->selected_index] + 6);
}

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  if (
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
  lv_obj_t **elements         = nav_state->current_screen->elements;
  menu_component_t *component = nav_state->current_screen->component;
  if (component->last_mode == motor_model_get_day_night_mode())
    return;
  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < 6; ++i)
    lv_obj_set_style_text_color(elements[i], color, 0);
}

static void destroy() {
  menu_navigate_free(&nav_state);
}

static void open_window() {
  lv_obj_t **elements = nav_state->current_screen->elements;
  ui_helpers_menu_image(elements, "selected.png", 6, 292, 70);
  y_pos[5] = 374; 
  for (int i = 0; i < 5; ++i) {
    y_pos[i] = 64 + 62*i;
    ui_helpers_menu_image(elements, "arrow_down.png", 7+i, 755, y_pos[i] + 27);
    ui_helpers_menu_image(elements, "line.png", 13+i, 292, y_pos[i]+ 62);
  }
  ui_helpers_menu_image(elements, "arrow_down.png", 12, 755, y_pos[5] + 27);

  lv_obj_t *parent    = menu_window_get();
  label_font_e font   = LABEL_FONT_HARMONYOS_24;
  label_color_e color = tool_get_color_base();
  ui_helpers_create_label_left(parent, &elements[0], 320, y_pos[0], 300, 62, color,
                               font, lang_text(TEXT_ID_DISPLAY));
  ui_helpers_create_label_left(parent, &elements[1], 320, y_pos[1], 300, 62, color,
                               font, lang_text(TEXT_ID_BACKLIGHT));
  ui_helpers_create_label_left(parent, &elements[2], 320, y_pos[2], 300, 62, color,
                               font, lang_text(TEXT_ID_BLUETOOTH));
  ui_helpers_create_label_left(parent, &elements[3], 320, y_pos[3], 300, 62, color,
                               font, lang_text(TEXT_ID_CLOCK));
  ui_helpers_create_label_left(parent, &elements[4], 320, y_pos[4], 300, 62, color,
                               font, lang_text(TEXT_ID_UNIT));
  ui_helpers_create_label_left(parent, &elements[5], 320, y_pos[5], 300, 62, color,
                               font, lang_text(TEXT_ID_LANGUAGE));
  update_selection_display();
}

static void close_window() {
}

void settings_update() {
  static const text_id_e labels[] = {TEXT_ID_DISPLAY,   TEXT_ID_BACKLIGHT,
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

  char image_path[MAX_IMAGE_CHARS];
  sprintf(image_path, RES_PRFIX "menu/%s/%s", tool_get_theme_suffix(), "selected.png");
  lv_img_set_src(elements[6], image_path);
  y_pos[5] = 374; 
  for (int i = 0; i < 5; ++i) {
    y_pos[i] = 64 + 62*i;
    ui_helpers_menu_image(elements, "arrow_down.png", 7+i, 755, y_pos[i] + 27);
    ui_helpers_menu_image(elements, "line.png", 13+i, 292, y_pos[i]+ 62);
  }
  ui_helpers_menu_image(elements, "arrow_down.png", 12, 755, y_pos[5] + 27);
  update_selection_display();
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

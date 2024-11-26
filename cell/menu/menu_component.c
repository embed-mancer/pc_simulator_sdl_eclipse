#include "menu_component.h"
#include "menu_navigate.h"

lv_obj_t* page_bg = NULL;
// extern lv_obj_t* menu_window_get();
// extern navigation_state_t* nav_state;

void free_component(menu_component_t* component) {
  if (component) {
    free(component);
    component = NULL;
  }
}

menu_component_t* allocate_component() {
  menu_component_t* component =
      (menu_component_t*)malloc(sizeof(menu_component_t));
  if (!component) {
    printf("Error: Failed to allocate memory for menu component.\n");
    exit(EXIT_FAILURE);
  }
  return component;
}

void init_component(menu_component_t* component, void (*refresh)(),
                    bool (*handle_click_event)(const click_e),
                    void (*toggle_day_night)(), void (*destroy)(),
                    void (*open_window)(), void (*close_window)()) {
  if (!component)
    return;

  *component = (menu_component_t){.refresh            = refresh,
                                  .handle_click_event = handle_click_event,
                                  .toggle_day_night   = toggle_day_night,
                                  .destroy            = destroy,
                                  .open_window        = open_window,
                                  .close_window       = close_window};
}

void create_item(item_t** item_ptr, int y, text_id_t title_id, const char* num,
                 bool is_arrow) {
  if (!item_ptr)
    return;

  *item_ptr = (item_t*)malloc(sizeof(item_t));
  if (!*item_ptr) {
    printf("Error: Failed to allocate memory for item.\n");
    exit(EXIT_FAILURE);
  }
  item_t* item = *item_ptr;

  *item = (item_t){.bg = NULL, .title = NULL, .num = NULL, .arrow = NULL};

  const int item_height      = 70;
  const int arrow_img_height = 16;
  initialize_background(&item->bg, menu_window_get(), 300, y, 500, item_height,
                        lv_color_black());

  const char* title = lang_text(title_id);
  int line_height =
      lv_font_get_line_height(tool_get_font(LABEL_FONT_MICROSOFT_YAHEI_22));
  label_pos_t title_pos = ui_helpers_init_label_position(
      10, item_height / 2 - line_height / 2, 150, 30, LABEL_COLOR_WHITE,
      LABEL_FONT_MICROSOFT_YAHEI_22, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value(title));
  ui_helpers_create_label(item->bg, &item->title, title_pos);
  lv_obj_set_style_text_align(item->title, LV_TEXT_ALIGN_LEFT, 0);

  if (num) {
    int x_pos           = is_arrow ? 300 : 320;
    label_pos_t num_pos = ui_helpers_init_label_position(
        x_pos, item_height / 2 - line_height / 2, 100, 30, LABEL_COLOR_WHITE,
        LABEL_FONT_MICROSOFT_YAHEI_22, VALUE_TYPE_CHAR,
        ui_helpers_init_label_value(num));
    ui_helpers_create_label(item->bg, &item->num, num_pos);
    lv_obj_set_style_text_align(item->num, LV_TEXT_ALIGN_RIGHT, 0);
  }

  if (is_arrow) {
    image_pos_t arrow_pos = ui_helpers_init_image_position(
        RES_PRFIX "menu/arrow_down_gray.png", 410,
        (item_height - arrow_img_height) / 2);
    ui_helpers_create_image(item->bg, &item->arrow, arrow_pos);
  }
}

void set_item_color(item_t** item_ptr, bool is_selected) {
  if (!item_ptr || !(*item_ptr))
    return;

  item_t* item = *item_ptr;
  lv_color_t color =
      is_selected ? lv_color_make(0x45, 0xc7, 0xe9) : lv_color_black();
  lv_obj_set_style_bg_color(item->bg, color, 0);
  lv_obj_invalidate(item->bg);
}

void update_index(int direction) {
  screen_t* screen = nav_state->current_screen;
  uint8_t* index       = &nav_state->selected_index;

  if (direction == DIRECTION_DOWN) {
    *index = (*index + 1) % screen->menu_item_count;
  } else if (direction == DIRECTION_UP) {
    *index = (*index == 0) ? screen->menu_item_count - 1
                           : (*index - 1) % screen->menu_item_count;
  }
}

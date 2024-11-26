#include "../tool/tool.h"
#include "menu_navigate.h"
#include "../config/config.h"

#define PRESS_DURATION 100

lv_obj_t *bg                        = NULL;
lv_obj_t *title                     = NULL;
uint32_t button_press_timestamps[4] = {0};
lv_obj_t *button_images[4]          = {0};
const char *image_names[]           = {"up", "down", "back", "set"};
const char *image_states[]          = {"off", "on"};
char image_paths[8][MAX_IMAGE_CHARS];

void button_control_update(int button_index) {
  lv_img_set_src(button_images[button_index],
                 image_paths[2 * button_index + 1]);
  button_press_timestamps[button_index] = lv_tick_get();
}

void button_control_refresh() {
  uint32_t current_time = lv_tick_get();

  for (int i = 0; i < 4; ++i) {
    if (button_press_timestamps[i] != 0 &&
        (current_time - button_press_timestamps[i]) >= PRESS_DURATION) {
      lv_img_set_src(button_images[i], image_paths[2 * i]);
      button_press_timestamps[i] = 0;
    }
  }
}

void button_control_init() {
  const char *theme_suffix = tool_get_theme_suffix();

  for (int i = 0; i < sizeof(image_names) / sizeof(image_names[0]); ++i) {
    for (int j = 0; j < sizeof(image_states) / sizeof(image_states[0]); ++j) {
      snprintf(image_paths[i * 2 + j], sizeof(image_paths[i * 2 + j]),
               RES_PRFIX "menu/%s/%s_%s.png", theme_suffix, image_names[i],
               image_states[j]);
    }
  }

  char bg_path[MAX_IMAGE_CHARS];
  sprintf(bg_path, RES_PRFIX "menu/%s/bg.png", theme_suffix);
  image_pos_t pos = ui_helpers_init_image_position(bg_path, 0, 0);
  ui_helpers_create_image(menu_window_get(), &bg, pos);

  pos = ui_helpers_init_image_position(image_paths[0], 89, 173);
  ui_helpers_create_image(menu_window_get(), &button_images[0], pos);

  pos = ui_helpers_init_image_position(image_paths[2], 89, 267);
  ui_helpers_create_image(menu_window_get(), &button_images[1], pos);

  pos = ui_helpers_init_image_position(image_paths[4], 37, 220);
  ui_helpers_create_image(menu_window_get(), &button_images[2], pos);

  pos = ui_helpers_init_image_position(image_paths[6], 150, 220);
  ui_helpers_create_image(menu_window_get(), &button_images[3], pos);

  label_color_e color = tool_get_color_base();
  ui_helpers_create_label_left(menu_window_get(), &title, 40, 25, 300, 44,
                               color, LABEL_FONT_HARMONYOS_MEDIUM_30,
                               lang_text(TEXT_ID_SETTINGS));
}

void button_control_destroy() {
  for (int i = 0; i < 4; i++) {
    if (button_images[i])
      lv_obj_del(button_images[i]);
    button_images[i] = NULL;
  }
  if (bg)
    lv_obj_del(bg);
  if (title)
    lv_obj_del(title);
  bg    = NULL;
  title = NULL;
}

void button_control_set_title(language_e e) {
  lv_label_set_text(title, lang_text(e));
}

void button_control_toggle_display() {
  const char *theme_suffix = tool_get_theme_suffix();

  for (int i = 0; i < sizeof(image_names) / sizeof(image_names[0]); ++i) {
    for (int j = 0; j < sizeof(image_states) / sizeof(image_states[0]); ++j) {
      snprintf(image_paths[i * 2 + j], sizeof(image_paths[i * 2 + j]),
               RES_PRFIX "menu/%s/%s_%s.png", theme_suffix, image_names[i],
               image_states[j]);
    }
  }

  char bg_path[MAX_IMAGE_CHARS];
  sprintf(bg_path, RES_PRFIX "menu/%s/bg.png", theme_suffix);
  lv_img_set_src(bg, bg_path);

  lv_img_set_src(button_images[0], image_paths[0]);
  lv_img_set_src(button_images[1], image_paths[2]);
  lv_img_set_src(button_images[2], image_paths[4]);
  lv_img_set_src(button_images[3], image_paths[6]);
  lv_obj_set_style_text_color(title, tool_get_theme_color(), 0);
}

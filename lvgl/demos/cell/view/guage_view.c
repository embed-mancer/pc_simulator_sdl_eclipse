#include "guage_view.h"

#include "../other/motor_model.h"

#define BLOCK_WIDTH_MAX 195
#define BLOCK_HEIGHT 8

static void UpdateImageSource(guage_view_t *view, const char *from,
                              const char *to) {
  replace_substring(view->icon_position.image, from, to);
  replace_substring(view->line_position.image, from, to);
  for (int i = 0; i < kGuageNum; ++i) {
    if (view->block[i] != NULL) {
      replace_substring(view->block_position[i].image, from, to);
    }
  }
}

static void HideAllBlocks(guage_view_t *view) {
  for (int i = 0; i < kGuageNum; ++i) {
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

static void ShowBlocks(guage_view_t *view, int value) {
  for (int i = 0; i < value; i++) {
    lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
  for (int i = value; i < kGuageNum; i++) {
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void guage_view_init(guage_view_t *view, guage_view_mode mode) {
  view->icon_t = NULL;
  view->line = NULL;
  view->label[0] = NULL;
  view->label[1] = NULL;
  view->mode = mode;
  view->max_value = kGuageNum;
  for (int i = 0; i < kGuageNum; ++i) {
    view->block[i] = NULL;
  }
  guage_view_create(view);
}

void guage_view_create(guage_view_t *view) {
  if (view->background == NULL) {
    return;
  }

  if (view->mode == kGuageViewModeBlock) {
    for (int i = 0; i < kGuageNum; ++i) {
      light_view_one(view->background, &view->block[i],
                     view->block_position[i]);
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
    light_view_one(view->background, &view->icon_t, view->icon_position);
    light_view_one(view->background, &view->line, view->line_position);
  } else if (view->mode == kGuageViewModeWidth) {
    light_view_one(view->background, &view->icon_t, view->icon_position);
    light_view_one(view->background, &view->line, view->line_position);

    view->block[0] = lv_img_create(view->background);
    lv_img_set_src(view->block[0], view->block_position[0].image);
    lv_obj_set_pos(view->block[0], view->block_position[0].x,
                   view->block_position[0].y);
    lv_obj_set_width(view->block[0], 0);

    create_label(view->background, &view->label[0], view->label_position[0]);
    create_label(view->background, &view->label[1], view->label_position[1]);
  }
}

void guage_view_update(guage_view_t *view, int value) {
  value = (value < 0) ? 0 : (value > view->max_value) ? view->max_value : value;

  if (view->mode == kGuageViewModeBlock) {
    if (value <= 0) {
      HideAllBlocks(view);
    } else {
      ShowBlocks(view, value);
    }
  } else if (view->mode == kGuageViewModeWidth) {
    int block_width = BLOCK_WIDTH_MAX * value / 8.0;
    lv_obj_set_size(view->block[0], block_width, BLOCK_HEIGHT);
  }
}

void guage_view_toggle_day_night_mode(guage_view_t *view) {
  const char *from =
      motor_model_get_day_night_mode() == METER_MODE_NIGHT ? "day" : "night";
  const char *to =
      motor_model_get_day_night_mode() == METER_MODE_NIGHT ? "night" : "day";

  UpdateImageSource(view, from, to);
  tool_set_text_on_mode_and_update(view->label[1],
                                   &view->label_position[1].color,
                                   LABEL_COLOR_WHITE, LABEL_COLOR_BLACK);
  lv_img_set_src(view->block[0], view->block_position[0].image);
  lv_img_set_src(view->icon_t, view->icon_position.image);
  lv_img_set_src(view->line, view->line_position.image);
}

void guage_view_main_oil(guage_view_t *view) {
  const char *theme_suffix = tool_get_theme_suffix();
  snprintf(view->icon_position.image, sizeof(view->icon_position.image),
           RES_PRFIX "home/%s/oil_normal.png", theme_suffix);
  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/oil_line.png", theme_suffix);
  snprintf(view->block_position[0].image, sizeof(view->block_position[0].image),
           RES_PRFIX "home/%s/oil_width.png", theme_suffix);

  view->icon_position = create_image_pos(view->icon_position.image, 30, 430);
  view->line_position = create_image_pos(view->line_position.image, 91, 444);
  view->block_position[0] =
      create_image_pos(view->block_position[0].image, 92, 444);

  view->label_position[0] = create_label_pos(
      75, 440, 10, 20, LABEL_COLOR_RED, LABEL_FONT_SOURCEHANSANSCN_18,
      VALUE_TYPE_CHAR, (label_value_t){"E"});
  label_color_t color = tool_get_color_base();
  view->label_position[1] =
      create_label_pos(298, 440, 10, 20, color, LABEL_FONT_SOURCEHANSANSCN_18,
                       VALUE_TYPE_CHAR, (label_value_t){"F"});
  guage_view_init(view, kGuageViewModeWidth);
}

void guage_view_main_water(guage_view_t *view) {
  const char *theme_suffix = tool_get_theme_suffix();

  snprintf(view->icon_position.image, sizeof(view->icon_position.image),
           RES_PRFIX "home/%s/water_normal.png", theme_suffix);
  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/water_line.png", theme_suffix);
  snprintf(view->block_position[0].image, sizeof(view->block_position[0].image),
           RES_PRFIX "home/%s/water_width.png", theme_suffix);

  view->icon_position = create_image_pos(view->icon_position.image, 487, 430);
  view->line_position = create_image_pos(view->line_position.image, 554, 444);
  view->block_position[0] =
      create_image_pos(view->block_position[0].image, 554, 444);

  view->label_position[0] = create_label_pos(
      764, 441, 10, 20, LABEL_COLOR_RED, LABEL_FONT_SOURCEHANSANSCN_18,
      VALUE_TYPE_CHAR, (label_value_t){"H"});
  label_color_t color = tool_get_color_base();
  view->label_position[1] =
      create_label_pos(531, 441, 10, 20, color, LABEL_FONT_SOURCEHANSANSCN_18,
                       VALUE_TYPE_CHAR, (label_value_t){"C"});
  guage_view_init(view, kGuageViewModeWidth);
}
#include "speed_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_accumulator_t speed_accumulator;
static const int mid_position = 400;
static const int width        = 94;

void speed_view_init(speed_view_t *view, lv_obj_t *background) {
  memset(view, 0, sizeof(*view));
  view->background = background;
  view->last_index = -1;
}

void speed_view_create(speed_view_t *view) {
  for (int i = 0; i < 3; ++i) {
    ui_helpers_create_image(view->background, &view->block[i],
                            view->block_position[i]);
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
  ui_helpers_create_label(view->background, &view->unit, view->unit_position);
  speed_view_update(view, 0);
}

static void set_block_positions(speed_view_t *view, const int positions[3]) {
  for (int i = 0; i < 3; ++i) {
    if (positions[i] >= 0) {
      lv_obj_set_x(view->block[i], positions[i]);
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
  }
}

static void update_blocks(speed_view_t *view, int value) {
  int positions[3] = {-1, -1, -1};
  if (value < 10) {
    positions[2] = mid_position - width / 2;
    lv_img_set_src(view->block[2], view->image_paths[value]);
  } else if (value < 100) {
    positions[1] = mid_position - width;
    positions[2] = mid_position;
    lv_img_set_src(view->block[1], view->image_paths[value / 10]);
    lv_img_set_src(view->block[2], view->image_paths[value % 10]);
  } else {
    positions[0] = mid_position - 3 * width / 2 - 5;
    positions[1] = mid_position - width / 2 - 30;
    positions[2] = mid_position + width / 2 - 25;
    lv_img_set_src(view->block[0], view->image_paths[value / 100]);
    lv_img_set_src(view->block[1], view->image_paths[(value / 10) % 10]);
    lv_img_set_src(view->block[2], view->image_paths[value % 10]);
  }
  set_block_positions(view, positions);
}

void speed_view_update(speed_view_t *view, int value) {
  value = (value > MAX_SPEED) ? MAX_SPEED : (value < 0) ? 0 : value;
  if (value != view->last_index) {
    view->last_index = value;
    update_blocks(view, value);
  }
}

void speed_view_toggle_day_night(speed_view_t *view) {
  for (int i = 0; i < 10; ++i) {
    tool_toggle_day_night(view->image_paths[i]);
  }

  tool_set_text_on_mode_and_update(view->unit, &view->unit_position.color,
                                   LABEL_COLOR_WHITE, LABEL_COLOR_BLACK);
  int current_value = speed_view_current();
  view->last_index  = -1;
  speed_view_update(view, current_value);
}

void speed_view_run() {
  int data      = motor_model_get_speed();
  int increment = speed_accumulator.accumulated;

  if (speed_accumulator.current < data) {
    speed_accumulator.current = (speed_accumulator.current + increment > data)
                                    ? data
                                    : speed_accumulator.current + increment;
  } else if (speed_accumulator.current > data) {
    speed_accumulator.current = (speed_accumulator.current - increment < data)
                                    ? data
                                    : speed_accumulator.current - increment;
  }
}

int speed_view_current() {
  return speed_accumulator.current;
}

void speed_view_main(speed_view_t *view, lv_obj_t *background) {
  speed_view_init(view, background);
  const char *theme_suffix = tool_get_theme_suffix();

  for (int i = 0; i < 10; ++i) {
    snprintf(view->image_paths[i], sizeof(view->image_paths[i]),
             RES_PRFIX "home/%s/speed/%d.png", theme_suffix, i);
  }

  for (int i = 0; i < 3; ++i) {
    view->block_position[i] =
        ui_helpers_init_image_position(view->image_paths[0], 320, 258);
  }

  label_color_e color = tool_get_color_base();
  view->unit_position = ui_helpers_init_label_position(
      507, 334, 55, 30, color, LABEL_FONT_SOURCEHANSANSCN_22, VALUE_TYPE_CHAR,
      (label_value_t){"km/h"});
  speed_view_create(view);
}

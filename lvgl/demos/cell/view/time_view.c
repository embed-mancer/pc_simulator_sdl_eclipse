#include "time_view.h"

#define TIME_X_CENTER 400
#define TIME_Y_POSITION 434
#define FIX_WIDTH 14
#define COLON_WIDTH 6

extern blink_manager_t *main_blink;

void time_view_init(time_view_t *view, lv_obj_t *background) {
  memset(view, 0, sizeof(*view));
  view->background = background;

  time_view_create(view);
  time_view_toggle_day_night(view);
}

void time_view_create(time_view_t *view) {
  if (view->background == NULL) {
    return;
  }

  int positions[5] = {
      TIME_X_CENTER - COLON_WIDTH / 2 - 2 * FIX_WIDTH,  // hour1_x
      TIME_X_CENTER - COLON_WIDTH / 2 - FIX_WIDTH,      // hour2_x
      TIME_X_CENTER - COLON_WIDTH / 2,                  // colon_x
      TIME_X_CENTER + COLON_WIDTH / 2,                  // min1_x
      TIME_X_CENTER + COLON_WIDTH / 2 + FIX_WIDTH       // min2_x
  };

  label_color_e color  = tool_get_color_base();
  lv_obj_t **labels[5] = {&view->hour_digit1, &view->hour_digit2, &view->colon,
                          &view->minute_digit1, &view->minute_digit2};

  label_pos_t label_positions[5] = {
      create_label_pos(positions[0], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                       LABEL_FONT_SOURCEHANSANSCN_28, VALUE_TYPE_INT,
                       (label_value_t)1),
      create_label_pos(positions[1], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                       LABEL_FONT_SOURCEHANSANSCN_28, VALUE_TYPE_INT,
                       (label_value_t)7),
      create_label_pos(positions[2], TIME_Y_POSITION, COLON_WIDTH, 25, color,
                       LABEL_FONT_SOURCEHANSANSCN_28, VALUE_TYPE_CHAR,
                       (label_value_t){":"}),
      create_label_pos(positions[3], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                       LABEL_FONT_SOURCEHANSANSCN_28, VALUE_TYPE_INT,
                       (label_value_t)1),
      create_label_pos(positions[4], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                       LABEL_FONT_SOURCEHANSANSCN_28, VALUE_TYPE_INT,
                       (label_value_t)7)};

  for (int i = 0; i < 5; ++i) {
    create_label(view->background, labels[i], label_positions[i]);
    lv_obj_set_style_text_align(*labels[i], LV_TEXT_ALIGN_CENTER, 0);
  }

  blink_manager_add(main_blink, view->colon, BLINK_INTERVAL_HZ_1);
}

// TODO
void time_view_update(time_view_t *view) {
}

void time_view_toggle_day_night(time_view_t *view) {
  lv_color_t color    = tool_get_theme_color();
  lv_obj_t *labels[5] = {view->hour_digit1, view->hour_digit2, view->colon,
                         view->minute_digit1, view->minute_digit2};
  for (int i = 0; i < 5; ++i) {
    lv_obj_set_style_text_color(labels[i], color, 0);
  }
}

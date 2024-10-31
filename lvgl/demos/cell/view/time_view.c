#include "time_view.h"

#define TIME_X_CENTER 400
#define TIME_Y_POSITION 434
#define FIX_WIDTH 14
#define COLON_WIDTH 6
#define DEFAULT_COLOR kColorWhite

void TimeViewInit(TimeView *view) {
  view->hour_digit1 = NULL;
  view->hour_digit2 = NULL;
  view->colon = NULL;
  view->minute_digit1 = NULL;
  view->minute_digit2 = NULL;

  TimeViewCreate(view);
}

void TimeViewCreate(TimeView *view) {
  if (view->background == NULL) {
    return;
  }
  int hour1_x = TIME_X_CENTER - COLON_WIDTH / 2 - 2 * FIX_WIDTH;
  int hour2_x = TIME_X_CENTER - COLON_WIDTH / 2 - FIX_WIDTH;
  int colon_x = TIME_X_CENTER - COLON_WIDTH / 2;
  int min1_x = TIME_X_CENTER + COLON_WIDTH / 2;
  int min2_x = TIME_X_CENTER + COLON_WIDTH / 2 + FIX_WIDTH;
  Color color = ToolGetColorBase();
  view->hour_digit1_position =
      CreateLabelPos(hour1_x, TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->hour_digit2_position =
      CreateLabelPos(hour2_x, TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7);
  view->colon_position =
      CreateLabelPos(colon_x, TIME_Y_POSITION, COLON_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextChar, (LabelValue){":"});
  view->minute_digit1_position =
      CreateLabelPos(min1_x, TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->minute_digit2_position =
      CreateLabelPos(min2_x, TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7);
  CreateLabel(view->background, &view->hour_digit1, view->hour_digit1_position);
  CreateLabel(view->background, &view->hour_digit2, view->hour_digit2_position);
  CreateLabel(view->background, &view->colon, view->colon_position);
  CreateLabel(view->background, &view->minute_digit1,
              view->minute_digit1_position);
  CreateLabel(view->background, &view->minute_digit2,
              view->minute_digit2_position);
  lv_obj_set_style_text_align(view->hour_digit1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->hour_digit2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->colon, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->minute_digit1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->minute_digit2, LV_TEXT_ALIGN_CENTER, 0);
}

// TODO
void TimeViewUpdate(TimeView *view) {}

void TimeViewToggleDayNightMode(TimeView *view) {
  lv_color_t color = ToolGetThemeColor();
  lv_obj_set_style_text_color(view->hour_digit1, color, 0);
  lv_obj_set_style_text_color(view->hour_digit2, color, 0);
  lv_obj_set_style_text_color(view->colon, color, 0);
  lv_obj_set_style_text_color(view->minute_digit1, color, 0);
  lv_obj_set_style_text_color(view->minute_digit2, color, 0);
}

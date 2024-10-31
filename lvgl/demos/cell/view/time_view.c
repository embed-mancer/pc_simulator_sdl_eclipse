#include "time_view.h"

#define TIME_X_CENTER 400
#define TIME_Y_POSITION 434
#define FIX_WIDTH 14
#define COLON_WIDTH 6
#define DEFAULT_COLOR kColorWhite

void TimeViewInit(TimeView *view) {
  view->time_hour1 = NULL;
  view->time_hour2 = NULL;
  view->time_colon = NULL;
  view->time_minute1 = NULL;
  view->time_minute2 = NULL;

  TimeViewCreate(view);
  TimeViewToggleDayNightMode(view);
}

void TimeViewCreate(TimeView *view) {
  if (view->bg == NULL) {
    return;
  }
  int hour1_x = TIME_X_CENTER - COLON_WIDTH / 2 - 2 * FIX_WIDTH;
  int hour2_x = TIME_X_CENTER - COLON_WIDTH / 2 - FIX_WIDTH;
  int colon_x = TIME_X_CENTER - COLON_WIDTH / 2;
  int min1_x = TIME_X_CENTER + COLON_WIDTH / 2;
  int min2_x = TIME_X_CENTER + COLON_WIDTH / 2 + FIX_WIDTH;
  view->pos_time_hour1 =
      CreateLabelPos(hour1_x, TIME_Y_POSITION, FIX_WIDTH, 25, kColorWhite,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->pos_time_hour2 =
      CreateLabelPos(hour2_x, TIME_Y_POSITION, FIX_WIDTH, 25, kColorWhite,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7);
  view->pos_time_colon =
      CreateLabelPos(colon_x, TIME_Y_POSITION, COLON_WIDTH, 25, kColorWhite,
                     kSourceHanSansCN_28, kTextChar, (LabelValue){":"});
  view->pos_time_minute1 =
      CreateLabelPos(min1_x, TIME_Y_POSITION, FIX_WIDTH, 25, kColorWhite,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->pos_time_minute2 =
      CreateLabelPos(min2_x, TIME_Y_POSITION, FIX_WIDTH, 25, kColorWhite,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7);
  Label(view->bg, &view->time_hour1, view->pos_time_hour1);
  Label(view->bg, &view->time_hour2, view->pos_time_hour2);
  Label(view->bg, &view->time_colon, view->pos_time_colon);
  Label(view->bg, &view->time_minute1, view->pos_time_minute1);
  Label(view->bg, &view->time_minute2, view->pos_time_minute2);
  lv_obj_set_style_text_align(view->time_hour1, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->time_hour2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->time_colon, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->time_minute2, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->time_minute2, LV_TEXT_ALIGN_CENTER, 0);
}

void TimeViewUpdate(TimeView *view) {}

void TimeViewToggleDayNightMode(TimeView *view) {
  lv_color_t color = ToolGetThemeColor();
  color = lv_color_make(0xFF, 0, 0);

  lv_obj_set_style_text_color(view->time_hour1, color, 0);
  lv_obj_set_style_text_color(view->time_hour2, color, 0);
  lv_obj_set_style_text_color(view->time_colon, color, 0);
  lv_obj_set_style_text_color(view->time_minute1, color, 0);
  lv_obj_set_style_text_color(view->time_minute2, color, 0);
} 

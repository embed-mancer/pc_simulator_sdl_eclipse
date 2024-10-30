#include "time_view.h"

#define TIME_X_CENTER 400
#define TIME_Y_POSITION 434
#define FIX_WIDTH 14
#define COLON_WIDTH 6

void TimeViewInit(TimeView *view) {
  view->time_hour1 = NULL;
  view->time_hour2 = NULL;
  view->time_colon = NULL;
  view->time_minute1 = NULL;
  view->time_minute2 = NULL;

  TimeViewCreate(view);
  // TimeViewSetTheme(view);
}

void TimeViewCreate(TimeView *view) {
  if (view->bg == NULL) {
    return;
  }

  view->pos_time_hour1 = CreateLabelPos(
      TIME_X_CENTER - COLON_WIDTH / 2 - 2 * FIX_WIDTH, TIME_Y_POSITION,
      FIX_WIDTH, 25, kColorWhite, kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->pos_time_hour2 = CreateLabelPos(
      TIME_X_CENTER - COLON_WIDTH / 2 - FIX_WIDTH, TIME_Y_POSITION, FIX_WIDTH,
      25, kColorWhite, kSourceHanSansCN_28, kTextInt, (LabelValue)7);
  view->pos_time_colon = CreateLabelPos(
      TIME_X_CENTER - COLON_WIDTH / 2, TIME_Y_POSITION, COLON_WIDTH, 25,
      kColorWhite, kSourceHanSansCN_28, kTextChar, (LabelValue){":"});
  view->pos_time_minute1 = CreateLabelPos(
      TIME_X_CENTER + COLON_WIDTH / 2, TIME_Y_POSITION, FIX_WIDTH, 25,
      kColorWhite, kSourceHanSansCN_28, kTextInt, (LabelValue)1);
  view->pos_time_minute2 = CreateLabelPos(
      TIME_X_CENTER + COLON_WIDTH / 2 + FIX_WIDTH, TIME_Y_POSITION, FIX_WIDTH,
      25, kColorWhite, kSourceHanSansCN_28, kTextInt, (LabelValue)7);

  lv_obj_t *labels[] = {&view->time_hour1, &view->time_hour2, &view->time_colon,
                        &view->time_minute1, &view->time_minute2};
  const LabelPosition *positions[] = {
      view->pos_time_hour1, view->pos_time_hour2, view->pos_time_colon,
      view->pos_time_minute1, view->pos_time_minute2};

  for (int i = 0; i < 5; i++) {
    Label(view->bg, labels[i], *positions[i]);
    lv_obj_set_style_text_align(*labels[i], LV_TEXT_ALIGN_CENTER, 0);
  }
}

void TimeViewUpdate(TimeView *view) {
  // Logic for updating the time would go here
}

void TimeViewSetTheme(TimeView *view) {
  lv_color_t color = ToolGetThemeColor();

  // Set color for each label
  lv_obj_t *labels[] = {view->time_hour1, view->time_hour2, view->time_colon,
                        view->time_minute1, view->time_minute2};
  for (int i = 0; i < 5; i++) {
    lv_obj_set_style_text_color(labels[i], color, 0);
  }
}

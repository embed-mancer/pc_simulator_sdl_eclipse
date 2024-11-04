#include "time_view.h"

#define TIME_X_CENTER 400
#define TIME_Y_POSITION 434
#define FIX_WIDTH 14
#define COLON_WIDTH 6

extern BlinkManager *main_blink;

void TimeViewInit(TimeView *view) {
  view->hour_digit1 = NULL;
  view->hour_digit2 = NULL;
  view->colon = NULL;
  view->minute_digit1 = NULL;
  view->minute_digit2 = NULL;

  TimeViewCreate(view);
  TimeViewToggleDayNightMode(view);
}

void TimeViewCreate(TimeView *view) {
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

  Color color = ToolGetColorBase();
  lv_obj_t **labels[5] = {&view->hour_digit1, &view->hour_digit2, &view->colon,
                          &view->minute_digit1, &view->minute_digit2};

  LabelPos label_positions[5] = {
      CreateLabelPos(positions[0], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1),
      CreateLabelPos(positions[1], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7),
      CreateLabelPos(positions[2], TIME_Y_POSITION, COLON_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextChar, (LabelValue){":"}),
      CreateLabelPos(positions[3], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)1),
      CreateLabelPos(positions[4], TIME_Y_POSITION, FIX_WIDTH, 25, color,
                     kSourceHanSansCN_28, kTextInt, (LabelValue)7)};

  for (int i = 0; i < 5; ++i) {
    CreateLabel(view->background, labels[i], label_positions[i]);
    lv_obj_set_style_text_align(*labels[i], LV_TEXT_ALIGN_CENTER, 0);
  }

  BlinkManagerAdd(main_blink, view->colon, BLINK_INTERVAL_HZ_1);
}

// TODO
void TimeViewUpdate(TimeView *view) {}

void TimeViewToggleDayNightMode(TimeView *view) {
  lv_color_t color = ToolGetThemeColor();
  lv_obj_t *labels[5] = {view->hour_digit1, view->hour_digit2, view->colon,
                         view->minute_digit1, view->minute_digit2};
  for (int i = 0; i < 5; ++i) {
    lv_obj_set_style_text_color(labels[i], color, 0);
  }
}
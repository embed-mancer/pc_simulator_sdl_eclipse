#include "speed_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_acc acc;

void SpeedViewInit(SpeedView *view) {
  view->unit = NULL;
  for (int i = 0; i < 3; ++i) view->block[i] = NULL;
  SpeedViewCreate(view);
}

void SpeedViewCreate(SpeedView *view) {
  for (int i = 0; i < 3; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
  Label(view->bg, &view->unit, view->pos_unit);
  SpeedViewUpdate(view, 0);
}

// Update UI for a single digit speed
static void UpdateSingleDigit(SpeedView *view, int mid, int width, int value) {
  lv_obj_set_x(view->block[2], mid - width / 2);
  lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
  lv_img_set_src(view->block[2], view->sz_block[value]);
}

// Update UI for a double digit speed
static void UpdateDoubleDigit(SpeedView *view, int mid, int width, int value) {
  lv_obj_set_x(view->block[1], mid - width);
  lv_obj_set_x(view->block[2], mid);
  lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
  lv_img_set_src(view->block[1], view->sz_block[value / 10]);
  lv_img_set_src(view->block[2], view->sz_block[value % 10]);
}

// Update UI for a triple digit speed
static void UpdateTripleDigit(SpeedView *view, int mid, int width, int value) {
  lv_obj_set_x(view->block[0], mid - 3 * width / 2 - 5);
  lv_obj_set_x(view->block[1], mid - width / 2 - 30);
  lv_obj_set_x(view->block[2], mid + width / 2 - 25);
  lv_obj_clear_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
  lv_img_set_src(view->block[0], view->sz_block[value / 100]);
  lv_img_set_src(view->block[1], view->sz_block[value / 10 % 10]);
  lv_img_set_src(view->block[2], view->sz_block[value % 10]);
}

void SpeedViewUpdate(SpeedView *view, int value) {
  value = (value > kMaxSpeed) ? kMaxSpeed : value;
  const int mid = 400;
  const int width = 94;
  if (value < 10) {
    UpdateSingleDigit(view, mid, width, value);
  } else if (value < 100) {
    UpdateDoubleDigit(view, mid, width, value);
  } else {
    UpdateTripleDigit(view, mid, width, value);
  }
}

void SpeedViewToggleDayNightMode(SpeedView *view) {
  for (int i = 0; i < 10; ++i) {
    ToolToggleDayNightMode(view->sz_block[i]);
  }

  ToolSetTextOnModeAndUpdate(view->unit, &view->pos_unit.color, kColorWhite,
                             kColorBlack);
}

void SpeedViewRun() {
  int data = MotorModelGetSpeed();
  if (acc.current < data) {
    acc.current += acc.acc;
    if (acc.current > data) acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.acc;
    if (acc.current < data) acc.current = data;
  }
}

int SpeedViewCurrent() { return acc.current; }

void SpeedViewMain(SpeedView *view) {
  const char *theme_suffix = ToolGetThemeSuffix();

  for (int i = 0; i < 10; ++i) {
    snprintf(view->sz_block[i], sizeof(view->sz_block[i]),
             RES_PRFIX "home/%s/speed/%d.png", theme_suffix, i);
  }
  view->pos_block[0] = CreateImagePos(view->sz_block[0], 320, 258);
  view->pos_block[1] = CreateImagePos(view->sz_block[0], 320, 258);
  view->pos_block[2] = CreateImagePos(view->sz_block[0], 320, 258);
  color_t color =
      (MotorModelGetDayNightMode() == kDay) ? kColorBlack : kColorWhite;
  view->pos_unit = CreateLabelPos(507, 334, 55, 30, color, kSourceHanSansCN_22,
                                  kTextChar, (LabelValue){"km/h"});
  SpeedViewInit(view);
}

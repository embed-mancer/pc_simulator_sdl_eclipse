#include "speed_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static DataAccumulator speed_accumulator;
static const int kMidPosition = 400;
static const int kWidth = 94;

void SpeedViewInit(SpeedView *view) {
  for (int i = 0; i < 3; ++i)
    view->block[i] = NULL;
  
  view->unit = NULL;
  SpeedViewCreate(view);
}

void SpeedViewCreate(SpeedView *view) {
  for (int i = 0; i < 3; ++i) {
    LightViewOne(view->background, &view->block[i], view->block_position[i]);
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
  CreateLabel(view->background, &view->unit, view->unit_position);
  SpeedViewUpdate(view, 0);
}

static void SetBlockPositions(SpeedView *view, const int positions[3]) {
  for (int i = 0; i < 3; ++i) {
    if (positions[i] >= 0) {
      lv_obj_set_x(view->block[i], positions[i]);
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
  }
}

static void UpdateBlocks(SpeedView *view, int value) {
  int positions[3] = {-1, -1, -1};
  if (value < 10) {
    positions[2] = kMidPosition - kWidth / 2;
    lv_img_set_src(view->block[2], view->image_paths[value]);
  } else if (value < 100) {
    positions[1] = kMidPosition - kWidth;
    positions[2] = kMidPosition;
    lv_img_set_src(view->block[1], view->image_paths[value / 10]);
    lv_img_set_src(view->block[2], view->image_paths[value % 10]);
  } else {
    positions[0] = kMidPosition - 3 * kWidth / 2 - 5;
    positions[1] = kMidPosition - kWidth / 2 - 30;
    positions[2] = kMidPosition + kWidth / 2 - 25;
    lv_img_set_src(view->block[0], view->image_paths[value / 100]);
    lv_img_set_src(view->block[1], view->image_paths[(value / 10) % 10]);
    lv_img_set_src(view->block[2], view->image_paths[value % 10]);
  }
  SetBlockPositions(view, positions);
}

void SpeedViewUpdate(SpeedView *view, int value) {
  value = (value > kMaxSpeed) ? kMaxSpeed : (value < 0) ? 0 : value;
  UpdateBlocks(view, value);
}

void SpeedViewToggleDayNightMode(SpeedView *view) {
  for (int i = 0; i < 10; ++i) {
    ToolToggleDayNightMode(view->image_paths[i]);
  }

  ToolSetTextOnModeAndUpdate(view->unit, &view->unit_position.color,
                             kColorWhite, kColorBlack);
}

void SpeedViewRun() {
  int data = MotorModelGetSpeed();
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

int SpeedViewCurrent() { return speed_accumulator.current; }

void SpeedViewMain(SpeedView *view) {
  const char *theme_suffix = ToolGetThemeSuffix();

  for (int i = 0; i < 10; ++i) {
    snprintf(view->image_paths[i], sizeof(view->image_paths[i]),
             RES_PRFIX "home/%s/speed/%d.png", theme_suffix, i);
  }

  for (int i = 0; i < 3; ++i) {
    view->block_position[i] = CreateImagePos(view->image_paths[0], 320, 258);
  }

  Color color = ToolGetColorBase();
  view->unit_position =
      CreateLabelPos(507, 334, 55, 30, color, kSourceHanSansCN_22, kTextChar,
                     (LabelValue){"km/h"});
  SpeedViewInit(view);
}
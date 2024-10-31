#include "guage_view.h"

#include "../other/motor_model.h"

#define BLOCK_WIDTH_MAX 195
#define BLOCK_HEIGHT 8
#define DAY_THEME "day"
#define NIGHT_THEME "night"

static void UpdateImageSource(GuageView *view, const char *from,
                              const char *to) {
  ReplaceSubstring(view->icon_position.image, from, to);
  ReplaceSubstring(view->line_position.image, from, to);
  for (int i = 0; i < kGuageNum; ++i) {
    if (view->block[i] != NULL) {
      ReplaceSubstring(view->block_position[i].image, from, to);
    }
  }
}

static void HideAllBlocks(GuageView *view) {
  for (int i = 0; i < kGuageNum; ++i) {
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

static void ShowBlocks(GuageView *view, int value) {
  for (int i = 0; i < value; i++) {
    lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
  for (int i = value; i < kGuageNum; i++) {
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void GuageViewInit(GuageView *view, GuageViewMode mode) {
  view->icon = NULL;
  view->line = NULL;
  view->label[0] = NULL;
  view->label[1] = NULL;
  view->mode = mode;
  view->max_value = kGuageNum;
  for (int i = 0; i < kGuageNum; ++i) {
    view->block[i] = NULL;
  }
  GuageViewCreate(view);
}

void GuageViewCreate(GuageView *view) {
  if (view->background == NULL) {
    return;
  }

  if (view->mode == kGuageViewModeBlock) {
    for (int i = 0; i < kGuageNum; ++i) {
      LightViewOne(view->background, &view->block[i], view->block_position[i]);
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
    LightViewOne(view->background, &view->icon, view->icon_position);
    LightViewOne(view->background, &view->line, view->line_position);
  } else if (view->mode == kGuageViewModeWidth) {
    LightViewOne(view->background, &view->icon, view->icon_position);
    LightViewOne(view->background, &view->line, view->line_position);

    view->block[0] = lv_img_create(view->background);
    lv_img_set_src(view->block[0], view->block_position[0].image);
    lv_obj_set_pos(view->block[0], view->block_position[0].x,
                   view->block_position[0].y);
    lv_obj_set_width(view->block[0], 0);

    CreateLabel(view->background, &view->label[0], view->label_position[0]);
    CreateLabel(view->background, &view->label[1], view->label_position[1]);
  }
}

void GuageViewUpdate(GuageView *view, int value) {
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

void GuageViewToggleDayNightMode(GuageView *view) {
  const char *from =
      MotorModelGetDayNightMode() == kNightMode ? "day" : "night";
  const char *to = MotorModelGetDayNightMode() == kNightMode ? "night" : "day";

  UpdateImageSource(view, from, to);
  ToolSetTextOnModeAndUpdate(view->label[1], &view->label_position[1].color,
                             kColorWhite, kColorBlack);
  lv_img_set_src(view->block[0], view->block_position[0].image);
  lv_img_set_src(view->icon, view->icon_position.image);
  lv_img_set_src(view->line, view->line_position.image);
}

void GuageViewMainOil(GuageView *view) {
  const char *theme_suffix = ToolGetThemeSuffix();
  snprintf(view->icon_position.image, sizeof(view->icon_position.image),
           RES_PRFIX "home/%s/oil_normal.png", theme_suffix);
  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/oil_line.png", theme_suffix);
  snprintf(view->block_position[0].image, sizeof(view->block_position[0].image),
           RES_PRFIX "home/%s/oil_width.png", theme_suffix);

  view->icon_position = CreateImagePos(view->icon_position.image, 30, 430);
  view->line_position = CreateImagePos(view->line_position.image, 91, 444);
  view->block_position[0] =
      CreateImagePos(view->block_position[0].image, 92, 444);

  view->label_position[0] =
      CreateLabelPos(75, 440, 10, 20, kColorRed, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"E"});
  Color color =
      (MotorModelGetDayNightMode() == kDayMode) ? kColorBlack : kColorWhite;
  view->label_position[1] =
      CreateLabelPos(298, 440, 10, 20, color, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"F"});
  GuageViewInit(view, kGuageViewModeWidth);
}

void GuageViewMainWater(GuageView *view) {
  const char *theme_suffix = ToolGetThemeSuffix();

  snprintf(view->icon_position.image, sizeof(view->icon_position.image),
           RES_PRFIX "home/%s/water_normal.png", theme_suffix);
  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/water_line.png", theme_suffix);
  snprintf(view->block_position[0].image, sizeof(view->block_position[0].image),
           RES_PRFIX "home/%s/water_width.png", theme_suffix);

  view->icon_position = CreateImagePos(view->icon_position.image, 487, 430);
  view->line_position = CreateImagePos(view->line_position.image, 554, 444);
  view->block_position[0] =
      CreateImagePos(view->block_position[0].image, 554, 444);

  view->label_position[0] =
      CreateLabelPos(764, 441, 10, 20, kColorRed, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"H"});
  Color color =
      (MotorModelGetDayNightMode() == kDayMode) ? kColorBlack : kColorWhite;
  view->label_position[1] =
      CreateLabelPos(531, 441, 10, 20, color, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"C"});
  GuageViewInit(view, kGuageViewModeWidth);
}

#include "guage_view.h"

#include "../other/motor_model.h"

#define BLOCK_WIDTH_MAX 195
#define BLOCK_HEIGHT 8
#define DAY_THEME "day"
#define NIGHT_THEME "night"

static void UpdateImageSource(GuageView *view, const char *from,
                              const char *to) {
  ReplaceSubstr(view->pos_icon.image, from, to);
  ReplaceSubstr(view->pos_line.image, from, to);
  for (int i = 0; i < kGuageNum; ++i) {
    if (view->block[i] != NULL) {
      ReplaceSubstr(view->pos_block[i].image, from, to);
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
  if (view->bg == NULL) {
    return;
  }

  if (view->mode == kGuageViewModeBlock) {
    for (int i = 0; i < kGuageNum; ++i) {
      LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
    LightViewOne(view->bg, &view->icon, view->pos_icon);
    LightViewOne(view->bg, &view->line, view->pos_line);
  } else if (view->mode == kGuageViewModeWidth) {
    LightViewOne(view->bg, &view->icon, view->pos_icon);
    LightViewOne(view->bg, &view->line, view->pos_line);

    view->block[0] = lv_img_create(view->bg);
    lv_img_set_src(view->block[0], view->pos_block[0].image);
    lv_obj_set_pos(view->block[0], view->pos_block[0].x, view->pos_block[0].y);
    lv_obj_set_width(view->block[0], 0);

    Label(view->bg, &view->label[0], view->pos_label[0]);
    Label(view->bg, &view->label[1], view->pos_label[1]);
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

void GuageViewSetTheme(GuageView *view) {
  const char *from = MotorModelGetTheme() == kNight ? "day" : "night";
  const char *to = MotorModelGetTheme() == kNight ? "night" : "day";

  UpdateImageSource(view, from, to);
  view->pos_label[1].color =
      (MotorModelGetTheme() == kNight) ? kColorWhite : kColorBlack;
  lv_obj_set_style_text_color(view->label[1],
                              ToolGetColor(view->pos_label[1].color), 0);
  lv_img_set_src(view->block[0], view->pos_block[0].image);
  lv_img_set_src(view->icon, view->pos_icon.image);
  lv_img_set_src(view->line, view->pos_line.image);
}

void GuageViewMainOil(GuageView *view) {
  const char *theme_suffix =
      (MotorModelGetTheme() == kDay) ? DAY_THEME : NIGHT_THEME;

  snprintf(view->pos_icon.image, sizeof(view->pos_icon.image),
           RES_PRFIX "home/%s/oil_normal.png", theme_suffix);
  snprintf(view->pos_line.image, sizeof(view->pos_line.image),
           RES_PRFIX "home/%s/oil_line.png", theme_suffix);
  snprintf(view->pos_block[0].image, sizeof(view->pos_block[0].image),
           RES_PRFIX "home/%s/oil_width.png", theme_suffix);

  view->pos_icon = CreateImagePos(view->pos_icon.image, 30, 430);
  view->pos_line = CreateImagePos(view->pos_line.image, 91, 444);
  view->pos_block[0] = CreateImagePos(view->pos_block[0].image, 92, 444);

  view->pos_label[0] =
      CreateLabelPos(75, 440, 10, 20, kColorRed, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"E"});
  color_t color = (MotorModelGetTheme() == kDay) ? kColorBlack : kColorWhite;
  view->pos_label[1] =
      CreateLabelPos(298, 440, 10, 20, color, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"F"});
  GuageViewInit(view, kGuageViewModeWidth);
}

void GuageViewMainWater(GuageView *view) {
  const char *theme_suffix =
      (MotorModelGetTheme() == kDay) ? DAY_THEME : NIGHT_THEME;

  snprintf(view->pos_icon.image, sizeof(view->pos_icon.image),
           RES_PRFIX "home/%s/water_normal.png", theme_suffix);
  snprintf(view->pos_line.image, sizeof(view->pos_line.image),
           RES_PRFIX "home/%s/water_line.png", theme_suffix);
  snprintf(view->pos_block[0].image, sizeof(view->pos_block[0].image),
           RES_PRFIX "home/%s/water_width.png", theme_suffix);

  view->pos_icon = CreateImagePos(view->pos_icon.image, 487, 430);
  view->pos_line = CreateImagePos(view->pos_line.image, 554, 444);
  view->pos_block[0] = CreateImagePos(view->pos_block[0].image, 554, 444);

  view->pos_label[0] =
      CreateLabelPos(764, 441, 10, 20, kColorRed, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"H"});
  color_t color = (MotorModelGetTheme() == kDay) ? kColorBlack : kColorWhite;
  view->pos_label[1] =
      CreateLabelPos(531, 441, 10, 20, color, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"C"});
  GuageViewInit(view, kGuageViewModeWidth);
}

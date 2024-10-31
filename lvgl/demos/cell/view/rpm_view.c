#include "rpm_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static DataAccumulator acc;

void RpmViewInit(RpmView *view) {
  view->line = NULL;
  view->num = NULL;
  view->unit = NULL;
  view->block = NULL;
  RpmViewCreate(view);
}

void RpmViewCreate(RpmView *view) {
  const char *theme_suffix = ToolGetThemeSuffix();

  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/rpm/line.png", theme_suffix);
  snprintf(view->number_position.image, sizeof(view->number_position.image),
           RES_PRFIX "home/%s/rpm/num.png", theme_suffix);
  snprintf(view->unit_position.image, sizeof(view->unit_position.image),
           RES_PRFIX "home/%s/rpm/unit.png", theme_suffix);
  view->line_position = CreateImagePos(view->line_position.image, 0, 94);
  view->number_position = CreateImagePos(view->number_position.image, 5, 166);
  view->unit_position = CreateImagePos(view->unit_position.image, 713, 112);
  view->block_positions[0] =
      CreateImagePos(RES_PRFIX "home/night/rpm/1.png", 0, 176);
  view->block_positions[1] =
      CreateImagePos(RES_PRFIX "home/night/rpm/2.png", 0, 174);
  view->block_positions[2] =
      CreateImagePos(RES_PRFIX "home/night/rpm/3.png", 0, 172);
  view->block_positions[3] =
      CreateImagePos(RES_PRFIX "home/night/rpm/4.png", 0, 170);
  view->block_positions[4] =
      CreateImagePos(RES_PRFIX "home/night/rpm/5.png", 0, 168);
  view->block_positions[5] =
      CreateImagePos(RES_PRFIX "home/night/rpm/6.png", 0, 166);
  view->block_positions[6] =
      CreateImagePos(RES_PRFIX "home/night/rpm/7.png", 0, 164);
  view->block_positions[7] =
      CreateImagePos(RES_PRFIX "home/night/rpm/8.png", 0, 162);
  view->block_positions[8] =
      CreateImagePos(RES_PRFIX "home/night/rpm/9.png", 0, 160);
  view->block_positions[9] =
      CreateImagePos(RES_PRFIX "home/night/rpm/10.png", 0, 159);
  view->block_positions[10] =
      CreateImagePos(RES_PRFIX "home/night/rpm/11.png", 0, 156);
  view->block_positions[11] =
      CreateImagePos(RES_PRFIX "home/night/rpm/12.png", 0, 155);
  view->block_positions[12] =
      CreateImagePos(RES_PRFIX "home/night/rpm/13.png", 0, 154);
  view->block_positions[13] =
      CreateImagePos(RES_PRFIX "home/night/rpm/14.png", 0, 152);
  view->block_positions[14] =
      CreateImagePos(RES_PRFIX "home/night/rpm/15.png", 0, 151);
  view->block_positions[15] =
      CreateImagePos(RES_PRFIX "home/night/rpm/16.png", 0, 149);
  view->block_positions[16] =
      CreateImagePos(RES_PRFIX "home/night/rpm/17.png", 0, 148);
  view->block_positions[17] =
      CreateImagePos(RES_PRFIX "home/night/rpm/18.png", 0, 147);
  view->block_positions[18] =
      CreateImagePos(RES_PRFIX "home/night/rpm/19.png", 0, 146);
  view->block_positions[19] =
      CreateImagePos(RES_PRFIX "home/night/rpm/20.png", 0, 144);
  view->block_positions[20] =
      CreateImagePos(RES_PRFIX "home/night/rpm/21.png", 0, 143);
  view->block_positions[21] =
      CreateImagePos(RES_PRFIX "home/night/rpm/22.png", 0, 142);
  view->block_positions[22] =
      CreateImagePos(RES_PRFIX "home/night/rpm/23.png", 0, 141);
  view->block_positions[23] =
      CreateImagePos(RES_PRFIX "home/night/rpm/24.png", 0, 140);
  view->block_positions[24] =
      CreateImagePos(RES_PRFIX "home/night/rpm/25.png", 0, 139);
  view->block_positions[25] =
      CreateImagePos(RES_PRFIX "home/night/rpm/26.png", 0, 138);
  view->block_positions[26] =
      CreateImagePos(RES_PRFIX "home/night/rpm/27.png", 0, 137);
  view->block_positions[27] =
      CreateImagePos(RES_PRFIX "home/night/rpm/28.png", 0, 136);
  view->block_positions[28] =
      CreateImagePos(RES_PRFIX "home/night/rpm/29.png", 0, 135);
  view->block_positions[29] =
      CreateImagePos(RES_PRFIX "home/night/rpm/30.png", 0, 134);
  view->block_positions[30] =
      CreateImagePos(RES_PRFIX "home/night/rpm/31.png", 0, 133);
  view->block_positions[31] =
      CreateImagePos(RES_PRFIX "home/night/rpm/32.png", 0, 132);
  view->block_positions[32] =
      CreateImagePos(RES_PRFIX "home/night/rpm/33.png", 0, 131);
  view->block_positions[33] =
      CreateImagePos(RES_PRFIX "home/night/rpm/34.png", 0, 130);
  view->block_positions[34] =
      CreateImagePos(RES_PRFIX "home/night/rpm/35.png", 0, 130);
  view->block_positions[35] =
      CreateImagePos(RES_PRFIX "home/night/rpm/36.png", 0, 129);
  view->block_positions[36] =
      CreateImagePos(RES_PRFIX "home/night/rpm/37.png", 0, 128);
  view->block_positions[37] =
      CreateImagePos(RES_PRFIX "home/night/rpm/38.png", 0, 128);
  view->block_positions[38] =
      CreateImagePos(RES_PRFIX "home/night/rpm/39.png", 0, 127);
  view->block_positions[39] =
      CreateImagePos(RES_PRFIX "home/night/rpm/40.png", 0, 126);
  view->block_positions[40] =
      CreateImagePos(RES_PRFIX "home/night/rpm/41.png", 0, 125);
  view->block_positions[41] =
      CreateImagePos(RES_PRFIX "home/night/rpm/42.png", 0, 125);
  view->block_positions[42] =
      CreateImagePos(RES_PRFIX "home/night/rpm/43.png", 0, 124);
  view->block_positions[43] =
      CreateImagePos(RES_PRFIX "home/night/rpm/44.png", 0, 124);
  view->block_positions[44] =
      CreateImagePos(RES_PRFIX "home/night/rpm/45.png", 0, 123);
  view->block_positions[45] =
      CreateImagePos(RES_PRFIX "home/night/rpm/46.png", 0, 123);
  view->block_positions[46] =
      CreateImagePos(RES_PRFIX "home/night/rpm/47.png", 0, 123);
  view->block_positions[47] =
      CreateImagePos(RES_PRFIX "home/night/rpm/48.png", 0, 123);
  for (int i = 48; i < 110; ++i) {
    view->block_positions[i] = CreateImagePos("", 0, 122);
    snprintf(view->block_positions[i].image,
             sizeof(view->block_positions[i].image),
             RES_PRFIX "home/night/rpm/%d.png", i+1);
  }
  LightViewOne(view->background, &view->line, view->line_position);
  LightViewOne(view->background, &view->num, view->number_position);
  LightViewOne(view->background, &view->unit, view->unit_position);
  LightViewOne(view->background, &view->block, view->block_positions[0]);
  lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
}

void RpmViewUpdate(RpmView *view, int value) {
  value = (value > kMaxRpm) ? kMaxRpm : value;
  int index = (value > 0) ? (value - 1) / 100 : -1;

  if (index >= 0) {
    lv_img_set_src(view->block, view->block_positions[index].image);
    lv_obj_set_pos(view->block, view->block_positions[index].x,
                   view->block_positions[index].y);
    lv_obj_clear_flag(view->block, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewToggleDayNightMode(RpmView *view) {
  ToolToggleDayNightMode(view->line_position.image);
  ToolToggleDayNightMode(view->number_position.image);
  ToolToggleDayNightMode(view->unit_position.image);
  lv_img_set_src(view->line, view->line_position.image);
  lv_img_set_src(view->num, view->number_position.image);
  lv_img_set_src(view->unit, view->unit_position.image);
}

void RpmViewRun() {
  int data = MotorModelGetRpm();
  if (acc.current < data) {
    acc.current += acc.accumulated;
    if (acc.current > data) acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.accumulated;
    if (acc.current < data) acc.current = data;
  }
}

int RpmViewCurrent() { return acc.current; }

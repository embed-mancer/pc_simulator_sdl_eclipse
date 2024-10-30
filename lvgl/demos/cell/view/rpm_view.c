#include "rpm_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_acc acc;

void RpmViewInit(RpmView *view) {
  view->line = NULL;
  view->num = NULL;
  view->unit = NULL;
  view->block = NULL;
  RpmViewCreate(view);
}

void RpmViewCreate(RpmView *view) {
  view->pos_line = CreateImagePos(RES_PRFIX "home/night/rpm/line.png", 0, 94);
  view->pos_num = CreateImagePos(RES_PRFIX "home/night/rpm/num.png", 5, 166);
  view->pos_unit =
      CreateImagePos(RES_PRFIX "home/night/rpm/unit.png", 713, 112);
  view->pos_block[0] = CreateImagePos(RES_PRFIX "home/night/rpm/1.png", 0, 176);
  view->pos_block[1] = CreateImagePos(RES_PRFIX "home/night/rpm/2.png", 0, 174);
  view->pos_block[2] = CreateImagePos(RES_PRFIX "home/night/rpm/3.png", 0, 172);
  view->pos_block[3] = CreateImagePos(RES_PRFIX "home/night/rpm/4.png", 0, 170);
  view->pos_block[4] = CreateImagePos(RES_PRFIX "home/night/rpm/5.png", 0, 168);
  view->pos_block[5] = CreateImagePos(RES_PRFIX "home/night/rpm/6.png", 0, 166);
  view->pos_block[6] = CreateImagePos(RES_PRFIX "home/night/rpm/7.png", 0, 164);
  view->pos_block[7] = CreateImagePos(RES_PRFIX "home/night/rpm/8.png", 0, 162);
  view->pos_block[8] = CreateImagePos(RES_PRFIX "home/night/rpm/9.png", 0, 160);
  view->pos_block[9] =
      CreateImagePos(RES_PRFIX "home/night/rpm/10.png", 0, 159);
  view->pos_block[10] =
      CreateImagePos(RES_PRFIX "home/night/rpm/11.png", 0, 156);
  view->pos_block[11] =
      CreateImagePos(RES_PRFIX "home/night/rpm/12.png", 0, 155);
  view->pos_block[12] =
      CreateImagePos(RES_PRFIX "home/night/rpm/13.png", 0, 154);
  view->pos_block[13] =
      CreateImagePos(RES_PRFIX "home/night/rpm/14.png", 0, 152);
  view->pos_block[14] =
      CreateImagePos(RES_PRFIX "home/night/rpm/15.png", 0, 151);
  view->pos_block[15] =
      CreateImagePos(RES_PRFIX "home/night/rpm/16.png", 0, 149);
  view->pos_block[16] =
      CreateImagePos(RES_PRFIX "home/night/rpm/17.png", 0, 148);
  view->pos_block[17] =
      CreateImagePos(RES_PRFIX "home/night/rpm/18.png", 0, 147);
  view->pos_block[18] =
      CreateImagePos(RES_PRFIX "home/night/rpm/19.png", 0, 146);
  view->pos_block[19] =
      CreateImagePos(RES_PRFIX "home/night/rpm/20.png", 0, 144);
  view->pos_block[20] =
      CreateImagePos(RES_PRFIX "home/night/rpm/21.png", 0, 143);
  view->pos_block[21] =
      CreateImagePos(RES_PRFIX "home/night/rpm/22.png", 0, 142);
  view->pos_block[22] =
      CreateImagePos(RES_PRFIX "home/night/rpm/23.png", 0, 141);
  view->pos_block[23] =
      CreateImagePos(RES_PRFIX "home/night/rpm/24.png", 0, 140);
  view->pos_block[24] =
      CreateImagePos(RES_PRFIX "home/night/rpm/25.png", 0, 139);
  view->pos_block[25] =
      CreateImagePos(RES_PRFIX "home/night/rpm/26.png", 0, 138);
  view->pos_block[26] =
      CreateImagePos(RES_PRFIX "home/night/rpm/27.png", 0, 137);
  view->pos_block[27] =
      CreateImagePos(RES_PRFIX "home/night/rpm/28.png", 0, 136);
  view->pos_block[28] =
      CreateImagePos(RES_PRFIX "home/night/rpm/29.png", 0, 135);
  view->pos_block[29] =
      CreateImagePos(RES_PRFIX "home/night/rpm/30.png", 0, 134);
  view->pos_block[30] =
      CreateImagePos(RES_PRFIX "home/night/rpm/31.png", 0, 133);
  view->pos_block[31] =
      CreateImagePos(RES_PRFIX "home/night/rpm/32.png", 0, 132);
  view->pos_block[32] =
      CreateImagePos(RES_PRFIX "home/night/rpm/33.png", 0, 131);
  view->pos_block[33] =
      CreateImagePos(RES_PRFIX "home/night/rpm/34.png", 0, 130);
  view->pos_block[34] =
      CreateImagePos(RES_PRFIX "home/night/rpm/35.png", 0, 130);
  view->pos_block[35] =
      CreateImagePos(RES_PRFIX "home/night/rpm/36.png", 0, 129);
  view->pos_block[36] =
      CreateImagePos(RES_PRFIX "home/night/rpm/37.png", 0, 128);
  view->pos_block[37] =
      CreateImagePos(RES_PRFIX "home/night/rpm/38.png", 0, 128);
  view->pos_block[38] =
      CreateImagePos(RES_PRFIX "home/night/rpm/39.png", 0, 127);
  view->pos_block[39] =
      CreateImagePos(RES_PRFIX "home/night/rpm/40.png", 0, 126);
  view->pos_block[40] =
      CreateImagePos(RES_PRFIX "home/night/rpm/41.png", 0, 125);
  view->pos_block[41] =
      CreateImagePos(RES_PRFIX "home/night/rpm/42.png", 0, 125);
  view->pos_block[42] =
      CreateImagePos(RES_PRFIX "home/night/rpm/43.png", 0, 124);
  view->pos_block[43] =
      CreateImagePos(RES_PRFIX "home/night/rpm/44.png", 0, 124);
  view->pos_block[44] =
      CreateImagePos(RES_PRFIX "home/night/rpm/45.png", 0, 123);
  view->pos_block[45] =
      CreateImagePos(RES_PRFIX "home/night/rpm/46.png", 0, 123);
  view->pos_block[46] =
      CreateImagePos(RES_PRFIX "home/night/rpm/47.png", 0, 123);
  view->pos_block[47] =
      CreateImagePos(RES_PRFIX "home/night/rpm/48.png", 0, 123);
  for (int i = 48; i < 110; ++i) {
    view->pos_block[i] = CreateImagePos("", 0, 122);
    snprintf(view->pos_block[i].image, sizeof(view->pos_block[i].image),
             RES_PRFIX "home/night/rpm/%d.png", i);
  }
  LightViewOne(view->bg, &view->line, view->pos_line);
  LightViewOne(view->bg, &view->num, view->pos_num);
  LightViewOne(view->bg, &view->unit, view->pos_unit);
  LightViewOne(view->bg, &view->block, view->pos_block[0]);
  lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
}

void RpmViewUpdate(RpmView *view, int value) {
  value = (value > kMaxRpm) ? kMaxRpm : value;
  int index = (value > 0) ? (value - 1) / 100 : -1;

  if (index >= 0) {
    lv_img_set_src(view->block, view->pos_block[index].image);
    lv_obj_set_pos(view->block, view->pos_block[index].x,
                   view->pos_block[index].y);
    lv_obj_clear_flag(view->block, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewRun() {
  int data = MotorModelGetRpm();
  if (acc.current < data) {
    acc.current += acc.acc;
    if (acc.current > data) acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.acc;
    if (acc.current < data) acc.current = data;
  }
}

int RpmViewCurrent() { return acc.current; }

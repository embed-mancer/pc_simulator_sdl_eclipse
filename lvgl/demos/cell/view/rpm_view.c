#include "rpm_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_accumulator_t acc;

void rpm_view_init(rpm_view_t *view, lv_obj_t *background) {
  memset(view, 0, sizeof(*view));
  view->background = background;
  view->last_index = -1;
  rpm_view_create(view);
}

void rpm_view_create(rpm_view_t *view) {
  const char *theme_suffix = tool_get_theme_suffix();

  snprintf(view->line_position.image, sizeof(view->line_position.image),
           RES_PRFIX "home/%s/rpm/line.png", theme_suffix);
  snprintf(view->number_position.image, sizeof(view->number_position.image),
           RES_PRFIX "home/%s/rpm/num.png", theme_suffix);
  snprintf(view->unit_position.image, sizeof(view->unit_position.image),
           RES_PRFIX "home/%s/rpm/unit.png", theme_suffix);
  view->line_position = create_image_pos(view->line_position.image, 0, 94);
  view->number_position = create_image_pos(view->number_position.image, 5, 166);
  view->unit_position = create_image_pos(view->unit_position.image, 713, 112);
  view->block_positions[0] =
      create_image_pos(RES_PRFIX "home/night/rpm/1.png", 0, 176);
  view->block_positions[1] =
      create_image_pos(RES_PRFIX "home/night/rpm/2.png", 0, 174);
  view->block_positions[2] =
      create_image_pos(RES_PRFIX "home/night/rpm/3.png", 0, 172);
  view->block_positions[3] =
      create_image_pos(RES_PRFIX "home/night/rpm/4.png", 0, 170);
  view->block_positions[4] =
      create_image_pos(RES_PRFIX "home/night/rpm/5.png", 0, 168);
  view->block_positions[5] =
      create_image_pos(RES_PRFIX "home/night/rpm/6.png", 0, 166);
  view->block_positions[6] =
      create_image_pos(RES_PRFIX "home/night/rpm/7.png", 0, 164);
  view->block_positions[7] =
      create_image_pos(RES_PRFIX "home/night/rpm/8.png", 0, 162);
  view->block_positions[8] =
      create_image_pos(RES_PRFIX "home/night/rpm/9.png", 0, 160);
  view->block_positions[9] =
      create_image_pos(RES_PRFIX "home/night/rpm/10.png", 0, 159);
  view->block_positions[10] =
      create_image_pos(RES_PRFIX "home/night/rpm/11.png", 0, 156);
  view->block_positions[11] =
      create_image_pos(RES_PRFIX "home/night/rpm/12.png", 0, 155);
  view->block_positions[12] =
      create_image_pos(RES_PRFIX "home/night/rpm/13.png", 0, 154);
  view->block_positions[13] =
      create_image_pos(RES_PRFIX "home/night/rpm/14.png", 0, 152);
  view->block_positions[14] =
      create_image_pos(RES_PRFIX "home/night/rpm/15.png", 0, 151);
  view->block_positions[15] =
      create_image_pos(RES_PRFIX "home/night/rpm/16.png", 0, 149);
  view->block_positions[16] =
      create_image_pos(RES_PRFIX "home/night/rpm/17.png", 0, 148);
  view->block_positions[17] =
      create_image_pos(RES_PRFIX "home/night/rpm/18.png", 0, 147);
  view->block_positions[18] =
      create_image_pos(RES_PRFIX "home/night/rpm/19.png", 0, 146);
  view->block_positions[19] =
      create_image_pos(RES_PRFIX "home/night/rpm/20.png", 0, 144);
  view->block_positions[20] =
      create_image_pos(RES_PRFIX "home/night/rpm/21.png", 0, 143);
  view->block_positions[21] =
      create_image_pos(RES_PRFIX "home/night/rpm/22.png", 0, 142);
  view->block_positions[22] =
      create_image_pos(RES_PRFIX "home/night/rpm/23.png", 0, 141);
  view->block_positions[23] =
      create_image_pos(RES_PRFIX "home/night/rpm/24.png", 0, 140);
  view->block_positions[24] =
      create_image_pos(RES_PRFIX "home/night/rpm/25.png", 0, 139);
  view->block_positions[25] =
      create_image_pos(RES_PRFIX "home/night/rpm/26.png", 0, 138);
  view->block_positions[26] =
      create_image_pos(RES_PRFIX "home/night/rpm/27.png", 0, 137);
  view->block_positions[27] =
      create_image_pos(RES_PRFIX "home/night/rpm/28.png", 0, 136);
  view->block_positions[28] =
      create_image_pos(RES_PRFIX "home/night/rpm/29.png", 0, 135);
  view->block_positions[29] =
      create_image_pos(RES_PRFIX "home/night/rpm/30.png", 0, 134);
  view->block_positions[30] =
      create_image_pos(RES_PRFIX "home/night/rpm/31.png", 0, 133);
  view->block_positions[31] =
      create_image_pos(RES_PRFIX "home/night/rpm/32.png", 0, 132);
  view->block_positions[32] =
      create_image_pos(RES_PRFIX "home/night/rpm/33.png", 0, 131);
  view->block_positions[33] =
      create_image_pos(RES_PRFIX "home/night/rpm/34.png", 0, 130);
  view->block_positions[34] =
      create_image_pos(RES_PRFIX "home/night/rpm/35.png", 0, 130);
  view->block_positions[35] =
      create_image_pos(RES_PRFIX "home/night/rpm/36.png", 0, 129);
  view->block_positions[36] =
      create_image_pos(RES_PRFIX "home/night/rpm/37.png", 0, 128);
  view->block_positions[37] =
      create_image_pos(RES_PRFIX "home/night/rpm/38.png", 0, 128);
  view->block_positions[38] =
      create_image_pos(RES_PRFIX "home/night/rpm/39.png", 0, 127);
  view->block_positions[39] =
      create_image_pos(RES_PRFIX "home/night/rpm/40.png", 0, 126);
  view->block_positions[40] =
      create_image_pos(RES_PRFIX "home/night/rpm/41.png", 0, 125);
  view->block_positions[41] =
      create_image_pos(RES_PRFIX "home/night/rpm/42.png", 0, 125);
  view->block_positions[42] =
      create_image_pos(RES_PRFIX "home/night/rpm/43.png", 0, 124);
  view->block_positions[43] =
      create_image_pos(RES_PRFIX "home/night/rpm/44.png", 0, 124);
  view->block_positions[44] =
      create_image_pos(RES_PRFIX "home/night/rpm/45.png", 0, 123);
  view->block_positions[45] =
      create_image_pos(RES_PRFIX "home/night/rpm/46.png", 0, 123);
  view->block_positions[46] =
      create_image_pos(RES_PRFIX "home/night/rpm/47.png", 0, 123);
  view->block_positions[47] =
      create_image_pos(RES_PRFIX "home/night/rpm/48.png", 0, 123);
  for (int i = 48; i < 110; ++i) {
    view->block_positions[i] = create_image_pos("", 0, 122);
    snprintf(view->block_positions[i].image,
             sizeof(view->block_positions[i].image),
             RES_PRFIX "home/night/rpm/%d.png", i + 1);
  }
  create_img(view->background, &view->line, view->line_position);
  create_img(view->background, &view->num, view->number_position);
  create_img(view->background, &view->unit, view->unit_position);
  create_img(view->background, &view->block, view->block_positions[0]);
  lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
}

void rpm_view_update(rpm_view_t *view, int value) {
  value = (value > MAX_RPM) ? MAX_RPM : value;
  int index = (value > 0) ? (value - 1) / 100 : -1;

  if (index != view->last_index) {
    view->last_index = index;
    if (index >= 0) {
      lv_img_set_src(view->block, view->block_positions[index].image);
      lv_obj_set_pos(view->block, view->block_positions[index].x,
                     view->block_positions[index].y);
      lv_obj_clear_flag(view->block, LV_OBJ_FLAG_HIDDEN);
    } else {
      lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
    }
  }
}

void rpm_view_toggle_day_night(rpm_view_t *view) {
  tool_toggle_day_night(view->line_position.image);
  tool_toggle_day_night(view->number_position.image);
  tool_toggle_day_night(view->unit_position.image);
  lv_img_set_src(view->line, view->line_position.image);
  lv_img_set_src(view->num, view->number_position.image);
  lv_img_set_src(view->unit, view->unit_position.image);
  int current_value = rpm_view_current();
  view->last_index = -1;
  rpm_view_update(view, current_value);
}

void rpm_view_run() {
  int data = motor_model_get_rpm();
  if (acc.current < data) {
    acc.current += acc.accumulated;
    if (acc.current > data) acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.accumulated;
    if (acc.current < data) acc.current = data;
  }
}

int rpm_view_current() { return acc.current; }

#include "rpm_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_accumulator_t acc = {.accumulated = 100, .current = 0};

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
  view->line_position =
      ui_helpers_init_image_position(view->line_position.image, 0, 94);
  view->number_position =
      ui_helpers_init_image_position(view->number_position.image, 5, 166);
  view->unit_position =
      ui_helpers_init_image_position(view->unit_position.image, 713, 112);
  view->block_positions[0] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/1.png", 0, 176);
  view->block_positions[1] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/2.png", 0, 174);
  view->block_positions[2] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/3.png", 0, 172);
  view->block_positions[3] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/4.png", 0, 170);
  view->block_positions[4] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/5.png", 0, 168);
  view->block_positions[5] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/6.png", 0, 166);
  view->block_positions[6] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/7.png", 0, 164);
  view->block_positions[7] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/8.png", 0, 162);
  view->block_positions[8] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/9.png", 0, 160);
  view->block_positions[9] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/10.png", 0, 159);
  view->block_positions[10] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/11.png", 0, 156);
  view->block_positions[11] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/12.png", 0, 155);
  view->block_positions[12] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/13.png", 0, 154);
  view->block_positions[13] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/14.png", 0, 152);
  view->block_positions[14] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/15.png", 0, 151);
  view->block_positions[15] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/16.png", 0, 149);
  view->block_positions[16] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/17.png", 0, 148);
  view->block_positions[17] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/18.png", 0, 147);
  view->block_positions[18] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/19.png", 0, 146);
  view->block_positions[19] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/20.png", 0, 144);
  view->block_positions[20] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/21.png", 0, 143);
  view->block_positions[21] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/22.png", 0, 142);
  view->block_positions[22] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/23.png", 0, 141);
  view->block_positions[23] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/24.png", 0, 140);
  view->block_positions[24] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/25.png", 0, 139);
  view->block_positions[25] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/26.png", 0, 138);
  view->block_positions[26] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/27.png", 0, 137);
  view->block_positions[27] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/28.png", 0, 136);
  view->block_positions[28] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/29.png", 0, 135);
  view->block_positions[29] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/30.png", 0, 134);
  view->block_positions[30] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/31.png", 0, 133);
  view->block_positions[31] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/32.png", 0, 132);
  view->block_positions[32] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/33.png", 0, 131);
  view->block_positions[33] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/34.png", 0, 130);
  view->block_positions[34] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/35.png", 0, 130);
  view->block_positions[35] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/36.png", 0, 129);
  view->block_positions[36] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/37.png", 0, 128);
  view->block_positions[37] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/38.png", 0, 128);
  view->block_positions[38] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/39.png", 0, 127);
  view->block_positions[39] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/40.png", 0, 126);
  view->block_positions[40] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/41.png", 0, 125);
  view->block_positions[41] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/42.png", 0, 125);
  view->block_positions[42] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/43.png", 0, 124);
  view->block_positions[43] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/44.png", 0, 124);
  view->block_positions[44] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/45.png", 0, 123);
  view->block_positions[45] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/46.png", 0, 123);
  view->block_positions[46] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/47.png", 0, 123);
  view->block_positions[47] =
      ui_helpers_init_image_position(RES_PRFIX "home/night/rpm/48.png", 0, 123);
  for (int i = 48; i < 110; ++i) {
    view->block_positions[i] = ui_helpers_init_image_position("", 0, 122);
    snprintf(view->block_positions[i].image,
             sizeof(view->block_positions[i].image),
             RES_PRFIX "home/night/rpm/%d.png", i + 1);
  }
  ui_helpers_create_image(view->background, &view->line, view->line_position);
  ui_helpers_create_image(view->background, &view->num, view->number_position);
  ui_helpers_create_image(view->background, &view->unit, view->unit_position);
  ui_helpers_create_image(view->background, &view->block,
                          view->block_positions[0]);
  lv_obj_add_flag(view->block, LV_OBJ_FLAG_HIDDEN);
}

void rpm_view_update(rpm_view_t *view, uint16_t value) {
  value     = (value > MAX_RPM) ? MAX_RPM : value;
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
  view->last_index  = -1;
  rpm_view_update(view, current_value);
}

static void run() {
  int inc = acc.accumulated;
  int target = acc.data;

  if (acc.current < target) {
    acc.current = (acc.current + inc > target) ? target : acc.current + inc;
  } else if (acc.current > target) {
    acc.current = (acc.current - inc < target) ? target : acc.current - inc;
  }
}

static bool should_udpate(int target, int current) {
  if (target <= 1000)
    return true;
  else if (target > current)
    return true;
  else if ((target + 200) < current)
    return true;

  return false;
}

void rpm_view_run() {
  acc.data = motor_model_get_rpm();
  if (should_udpate(acc.data, acc.current))
    run();
}

int rpm_view_current() {
  return acc.current;
}

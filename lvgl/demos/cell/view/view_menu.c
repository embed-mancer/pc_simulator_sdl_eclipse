#include "view_menu.h"
#include "lvgl/lvgl.h"

extern lv_obj_t *menu_bg;
int view_menu_id = 0;

const lv_img_dsc_t *dsc_day[] = {&menu_day_bg, &menu_day_center_bg, &menu_day_left_normal,
    &menu_day_left_selected, &menu_day_right_normal, &menu_day_right_selected,
    &menu_day_time_set_icon, &menu_day_brightness_icon, &menu_day_tp_info_icon, &menu_day_language_icon,
    &menu_day_unit_set_icon, &menu_day_connetion_icon};

lv_obj_t *img_blocks[6];
lv_obj_t *img_icons[6];
lv_obj_t *label_icons[6];
lv_obj_t *label_menu;
lv_obj_t *bg;
lv_obj_t *center_bg;

extern lv_obj_t *menu_screen;
const lv_img_dsc_t *images[15];

void ViewMenuInit() {
  for (int i = 0; i < sizeof(dsc_day)/sizeof(dsc_day[0]); ++i)
    images[i] = dsc_day[i];
  bg = lv_img_create(menu_screen);
  center_bg = lv_img_create(menu_screen);
  label_menu = lv_label_create(menu_screen);
  for (int i = 0; i < 6; ++i) {
    img_blocks[i] = lv_img_create(menu_screen);
    img_icons[i] = lv_img_create(menu_screen);
    label_icons[i] = lv_label_create(menu_screen);
  }
  ViewMenuCrate();
}

void ViewMenuCrate() {
  lv_img_set_src(bg, dsc_day[0]);
  lv_obj_set_pos(bg, 9, 0);

  lv_img_set_src(center_bg, images[1]);
  lv_obj_set_pos(center_bg, 141, 80);

  lv_obj_set_pos(label_menu, 174, 125);
  lv_obj_set_style_text_font(label_menu, &NimbusSanNovT_33, 0);
  lv_obj_set_style_text_color(label_menu, lv_color_black(), 0);
  lv_label_set_text(label_menu, "MENU");

  lv_img_set_src(img_blocks[0], images[3]);
  lv_obj_set_pos(img_blocks[0], 50, 34);
  lv_img_set_src(img_blocks[1], images[2]);
  lv_obj_set_pos(img_blocks[1], 14, 116);
  lv_img_set_src(img_blocks[2], images[2]);
  lv_obj_set_pos(img_blocks[2], 50, 198);
  lv_img_set_src(img_blocks[3], images[4]);
  lv_obj_set_pos(img_blocks[3], 277, 34);
  lv_img_set_src(img_blocks[4], images[4]);
  lv_obj_set_pos(img_blocks[4], 313, 116);
  lv_img_set_src(img_blocks[5], images[4]);
  lv_obj_set_pos(img_blocks[5], 277, 198);

  for (int i = 0; i < 6; ++i) {
    lv_img_set_src(img_icons[i], images[i+6]);
  }
  lv_obj_set_pos(img_icons[0], 69, 44);
  lv_obj_set_pos(img_icons[1], 33, 126);
  lv_obj_set_pos(img_icons[2], 69, 208);
  lv_obj_set_pos(img_icons[3], 391, 44);
  lv_obj_set_pos(img_icons[4], 427, 126);
  lv_obj_set_pos(img_icons[5], 391, 208);

  ViewMenuLabel(label_icons[0], "TIME SET", 94, 49);
  ViewMenuLabel(label_icons[1], "BRIGHTNESS", 60, 131);
  ViewMenuLabel(label_icons[2], "TP INFO", 94, 213);
  ViewMenuLabel(label_icons[3], "LANGUAGE", 308, 49);
  ViewMenuLabel(label_icons[4], "UNIT SET", 358, 131);
  ViewMenuLabel(label_icons[5], "CONNECTION", 301, 213);
}

void ViewMenuLabel(lv_obj_t *label, const char* text, lv_coord_t x, lv_coord_t y) {
  lv_obj_set_pos(label, x, y);
  lv_obj_set_style_text_font(label, &NimbusSanNovT_14, 0);
  lv_obj_set_style_text_color(label, lv_color_black(), 0);
  lv_label_set_text(label, text);
}

void ViewMenuClick(ClickTable table) {
  switch (table) {
    case kShortSet:
      break;
    case kLongSet:
      break;
    case kShortDown:
      view_menu_id = (++view_menu_id) % 6;
      ViewMenuUpdate();
      break;
    case kLongDown:

      break;
  } 
}

void ViewMenuUpdate() {
  lv_img_set_src(img_blocks[0], images[2]);
  lv_img_set_src(img_blocks[1], images[2]);
  lv_img_set_src(img_blocks[2], images[2]);
  lv_img_set_src(img_blocks[3], images[4]);
  lv_img_set_src(img_blocks[4], images[4]);
  lv_img_set_src(img_blocks[5], images[4]);
  if (view_menu_id < 3) {
    lv_img_set_src(img_blocks[view_menu_id], images[3]);
  } else {
    lv_img_set_src(img_blocks[view_menu_id], images[5]);
  }
}

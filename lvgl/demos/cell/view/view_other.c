#include "view_other.h"

lv_obj_t *range_key = NULL;
lv_obj_t *range_value = NULL;
lv_obj_t *range_unit = NULL;

lv_obj_t *battery_bg = NULL;
lv_obj_t *battery_label = NULL;
lv_obj_t *battery_value = NULL;

lv_obj_t *trip_key = NULL;
lv_obj_t *trip_value = NULL;
lv_obj_t *trip_unit = NULL;

LV_IMG_DECLARE(battery_line);

extern lv_obj_t *home_bg;

void ViewOtherCreate() {
  ViewOtherBattery();
  ViewOtherRange();
  ViewOtherTrip();
}

void ViewOtherRange() {
  range_key = lv_label_create(home_bg);
  lv_obj_set_pos(range_key, 44, 106);
  lv_obj_set_width(range_key, 50);
  lv_obj_set_style_text_color(range_key, lv_color_hex(0xA7A9AC), 0);
  lv_obj_set_style_text_font(range_key, &NimbusSanNovT_12, 0);
  lv_label_set_text(range_key, "RANGE");
  lv_label_set_long_mode(range_key, LV_LABEL_LONG_WRAP);
  lv_obj_set_style_text_align(range_key, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

  range_value = lv_label_create(home_bg);
  lv_obj_set_pos(range_value, 44, 120);
  lv_obj_set_width(range_value, 50);
  lv_obj_set_style_text_color(range_value, lv_color_black(), 0);
  lv_obj_set_style_text_font(range_value, &AlternateGotNo2D_45, 0);
  lv_label_set_text(range_value, "85");
  lv_label_set_long_mode(range_value, LV_LABEL_LONG_WRAP);
  lv_obj_set_style_text_align(range_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

  range_unit = lv_label_create(home_bg);
  lv_obj_set_pos(range_unit, 44, 158);
  lv_obj_set_width(range_unit, 50);
  lv_obj_set_style_text_color(range_unit, lv_color_hex(0xA7A9AC), 0);
  lv_obj_set_style_text_font(range_unit, &NimbusSanNovT_12, 0);
  lv_label_set_text(range_unit, "MILES");
  lv_label_set_long_mode(range_unit, LV_LABEL_LONG_WRAP);
  lv_obj_set_style_text_align(range_unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ViewOtherBattery() {
  battery_bg = lv_img_create(home_bg);
  lv_obj_set_pos(battery_bg, 18, 244);
  lv_img_set_src(battery_bg, &battery_line);

  battery_label = lv_obj_create(home_bg);
  lv_obj_set_pos(battery_label, 18, 246);
  lv_obj_set_size(battery_label, 50, 15);
  lv_obj_set_style_bg_color(battery_label, lv_color_hex(0X52AF48), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(battery_label, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);

  battery_value = lv_label_create(home_bg);
  lv_obj_set_pos(battery_value, 92, 244);
  lv_obj_set_style_text_color(battery_value, lv_color_black(), 0);
  lv_obj_set_style_text_font(battery_value, &AlternateGotNo2D_15, 0);
  lv_label_set_text(battery_value, "94%");
}

void ViewOtherTrip() {
  ViewOtherLabel(trip_key, "TRIP2",lv_color_hex(0xA7A9AC), &NimbusSanNovT_12,
                 370, 106, 83);
  ViewOtherLabel(trip_value, "2,222", lv_color_black(), &AlternateGotNo2D_45,
                 370, 120, 83);
  ViewOtherLabel(trip_unit, "MILES",lv_color_hex(0xA7A9AC), &NimbusSanNovT_12,
                 370, 158, 83);
}

void ViewOtherODO() {

}

void ViewOtherLabel(lv_obj_t *label, const char* text, lv_color_t color,
                    lv_font_t *font, lv_coord_t x, lv_coord_t y, 
                    lv_coord_t width) {
  label = lv_label_create(home_bg);
  lv_obj_set_pos(label, x, y);
  lv_obj_set_width(label, width);
  lv_obj_set_style_text_color(label, color, 0);
  lv_obj_set_style_text_font(label, font, 0);
  lv_label_set_text(label, text);
  lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
  lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

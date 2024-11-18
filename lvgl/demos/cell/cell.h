#ifndef CELL_H_
#define CELL_H_

#ifdef LVGL_DIR
#define RES_PRFIX LVGL_DIR
#else
#define RES_PRFIX "A:"
#endif

#include "lvgl/lvgl.h"
#include "tool/enums.h"

#define MAX_IMAGE_CHARS 64
#define RIGHT_ARROW_IMG_PATH (RES_PRFIX "menu/night/right_arrow.png")

typedef struct {
  int x;
  int y;
  char image[MAX_IMAGE_CHARS];
} image_pos_t;

typedef union {
  char sz[32];
  double double_value;
  int int_value;
} label_value_t;

typedef struct {
  lv_obj_t *obj;
  const char *name;
  bool is_needed;
} icon_t;

typedef struct {
  lv_coord_t x;
  lv_coord_t y;
  lv_coord_t width;
  lv_coord_t height;
  label_color_e color;
  label_font_e font;
  value_type_e value_type_e;
  label_value_t value;
} label_pos_t;

typedef struct {
  image_pos_t pos[20];
} light;

typedef struct {
  int previous;
  int current;
  int data;
  int accumulated;
} data_accumulator_t;

LV_FONT_DECLARE(Plagiata_27);
LV_FONT_DECLARE(Plagiata_37);
LV_FONT_DECLARE(SourceHanSansCN_18);
LV_FONT_DECLARE(SourceHanSansCN_22);
LV_FONT_DECLARE(SourceHanSansCN_28);
LV_FONT_DECLARE(SourceHanSansCN_34);
LV_FONT_DECLARE(MicrosoftYaHei_18);
LV_FONT_DECLARE(MicrosoftYaHei_20);
LV_FONT_DECLARE(MicrosoftYaHei_22);
LV_FONT_DECLARE(MicrosoftYaHei_30);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_16);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_20);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_24);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_28);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_30);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_36);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_40);
LV_FONT_DECLARE(HarmonyOS_Sans_SC_80);

#include "light/light.h"
#include "light/light_view.h"
#include "lvgl/lvgl.h"
#include "screens/main_window.h"
#include "tool/checkself.h"
#include "tool/enums.h"
#include "tool/tool.h"
#include "view/blink_manager.h"
#include "view/gear_view.h"
#include "view/guage_view.h"
#include "view/other_view.h"
#include "view/rpm_view.h"
#include "view/speed_view.h"
#include "view/time_view.h"
#include "tool/log.h"
#include "tool/ui_helpers.h"
#include <stdlib.h>

void cell_init();

#endif  // CELL_H_

#ifndef CELL_H_
#define CELL_H_

#ifdef LVGL_DIR
#define RES_PRFIX LVGL_DIR
#else
#define RES_PRFIX "A:"
#endif

#define FILENAME \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_INFO printf("[%s:%d] \n", __func__, __LINE__);

#define cell_ui_snprintf(fmt, arg...) snprintf(fmt, 255, ##arg)

#include "lvgl/lvgl.h"

#define MAX_IMAGE_CHARS 64

typedef enum { METER_MODE_DAY, METER_MODE_NIGHT, METER_MODE_AUTO } meter_mode_t;

typedef enum {
  LABEL_COLOR_WHITE,
  LABEL_COLOR_BLACK,
  LABEL_COLOR_RED,
  LABEL_COLOR_GREEN,
  LABEL_COLOR_BLUE,
  LABEL_COLOR_LIME_GREEN,
  LABEL_COLOR_COUNT
} label_color_t;

typedef enum {
  LABEL_FONT_PLAGIATA_27,
  LABEL_FONT_PLAGIATA_37,
  LABEL_FONT_SOURCEHANSANSCN_18,
  LABEL_FONT_SOURCEHANSANSCN_22,
  LABEL_FONT_SOURCEHANSANSCN_28,
  LABEL_FONT_SOURCEHANSANSCN_34,
  LABEL_FONT_MICROSOFT_YAHEI_20,
  LABEL_FONT_COUNT
} label_font_t;

typedef enum {
  VALUE_TYPE_CHAR,
  VALUE_TYPE_FLOAT,
  VALUE_TYPE_INT,
} value_type_t;

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
  label_color_t color;
  label_font_t font;
  value_type_t value_type_t;
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
LV_FONT_DECLARE(MicrosoftYaHei_20);

#include "light/light.h"
#include "light/light_view.h"
#include "lvgl/lvgl.h"
#include "screens/main_screen.h"
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
#include <stdlib.h>

#endif  // CELL_H_

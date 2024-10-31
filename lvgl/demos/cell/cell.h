#ifndef CELL_H_
#define CELL_H_

#if __linux__
#define RES_PRFIX "A:"
#else

#ifndef LVGL_STORAGE_PATH
#define STORAGE_PATH "/rodata/ui"
#endif

#define RES_PRFIX "L:" LVGL_STORAGE_PATH "/"

#endif

#define cell_ui_snprintf(fmt, arg...) snprintf(fmt, 255, ##arg)

#include "lvgl/lvgl.h"

typedef enum { kDayMode, kNightMode, kDayNightModeCount } DayNightMode;

typedef enum {
  kColorWhite,
  kColorBlack,
  kColorRed,
  kColorGreen,
  kColorBlue,
  kColorLimeGreen,
  kColorCount
} Color;

typedef enum {
  kPlagiata_27,
  kPlagiata_37,
  kSourceHanSansCN_18,
  kSourceHanSansCN_22,
  kSourceHanSansCN_28,
  kSourceHanSansCN_34,
  kMicrosoftYaHei_20,
  kFontCount
} Font;

typedef enum {
  kTextChar,
  kTextFloat,
  kTextInt,
} ValueType;

typedef struct {
  int x;
  int y;
  char image[32];
  char prefix[32];
} ImagePos;

typedef union {
  char sz[32];
  double double_value;
  int int_value;
} LabelValue;

typedef struct {
  lv_obj_t *obj;
  const char *name;
  bool is_needed;
} Icon;

typedef struct {
  lv_coord_t x;
  lv_coord_t y;
  lv_coord_t width;
  lv_coord_t height;
  Color color;
  Font font;
  ValueType value_type;
  LabelValue value;
} LabelPos;

typedef struct {
  ImagePos pos[20];
} Light;

typedef struct {
  int previous;
  int current;
  int data;
  int accumulated;
} DataAccumulator;

#include "light/light.h"
#include "lvgl/lvgl.h"
#include "tool/tool.h"
#include <stdlib.h>
#include "tool/enums.h"
#include "light/light_view.h"
#include "screens/main_screen.h"
#include "tool/checkself.h"
#include "view/gear_view.h"
#include "view/guage_view.h"
#include "view/other_view.h"
#include "view/time_view.h"
#include "view/rpm_view.h"
#include "view/speed_view.h"

#endif  // CELL_H_

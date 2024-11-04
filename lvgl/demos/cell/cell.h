#ifndef CELL_H_
#define CELL_H_

#ifdef LVGL_DIR
#define RES_PRFIX LVGL_DIR
#else
#define RES_PRFIX "A:"
#endif

#define FILENAME                                                               \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_INFO printf("[%s:%d] \n", __func__, __LINE__);

#define cell_ui_snprintf(fmt, arg...) snprintf(fmt, 255, ##arg)

#include "lvgl/lvgl.h"

#define kMaxImageChars 64

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
  char image[kMaxImageChars];
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

#endif // CELL_H_
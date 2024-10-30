/**
 * @file cell.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-07-08-16-44
 * @author Nemausa
 *
 */
#ifndef CELL_H_
#define CELL_H_

#if __linux__
#define RES_PRFIX "A:"
#else

#ifndef JUNRUI_LVGL_STORAGE_PATH
#define JUNRUI_LVGL_STORAGE_PATH "/rodata/ui"
#endif

#define RES_PRFIX "L:" JUNRUI_LVGL_STORAGE_PATH "/"

#endif

#define cell_ui_snprintf(fmt, arg...) snprintf(fmt, 255, ##arg)

#include "lvgl/lvgl.h"

typedef enum {
  kDay,
  kNight,
  kThemeCount
} ThemeTable;

typedef struct {
  int x;
  int y;
  char image[32];
  char prefix[32];
} image_pos;

typedef union {
  char sz[32];
  double f;
  int i;
} LabelValue;

typedef struct {
  lv_obj_t *obj;
  const char *name;
  bool is_needed;
} Icon;

typedef enum {
  kColorWhite,
  kColorBlack,
  kColorRed,
  kColorGreen,
  kColorBlue,
  kColorLimeGreen,
  kColorCount
} color_t;

typedef enum {
  kPlagiata_27,
  kPlagiata_37,
  kSourceHanSansCN_18,
  kSourceHanSansCN_22,
  kSourceHanSansCN_28,
  kSourceHanSansCN_34,
  kMicrosoftYaHei_20,
  kFontCount
} font_t;

typedef enum {
  kTextChar,
  kTextFloat,
  kTextInt,
} value_type_t;

typedef struct {
  lv_coord_t x;
  lv_coord_t y;
  lv_coord_t w;
  lv_coord_t h;
  color_t color;
  font_t font;
  value_type_t value_type;
  LabelValue value;
} label_pos;

typedef struct {
  image_pos pos[30];
} Light;

typedef struct {
  int pre;
  int current;
  int data;
  int acc;
} data_acc;

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

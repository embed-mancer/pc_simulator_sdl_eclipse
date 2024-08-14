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
#define JUNRUI_LVGL_DIR "A:"
#else

#ifndef JUNRUI_LVGL_STORAGE_PATH
#define JUNRUI_LVGL_STORAGE_PATH "/rodata/ui"
#endif

#define JUNRUI_LVGL_DIR "L:" JUNRUI_LVGL_STORAGE_PATH "/"

#endif

#define cell_ui_snprintf(fmt, arg...) snprintf(fmt, 255, ##arg)

#include "lvgl/lvgl.h"

typedef struct {
  int x;
  int y;
  char image[32];
  char prefix[32];
} image_pos;

union Text {
  char sz[32];
  double f;
  int i;
};

typedef enum {
  kColorWhite,
  kColorBlack,
} TextColor;

typedef enum {
  kPlagiata_27,
  kPlagiata_37,
} TextFont;

typedef struct {
  lv_coord_t x;
  lv_coord_t y;
  lv_coord_t w;
  lv_coord_t h;
  TextColor color;
  TextFont font;
  int value_type;
  union Text text;
} lable_pos;

typedef struct {
  image_pos abs;
  image_pos turn_left;
  image_pos turn_right;
  image_pos high_beam;
  image_pos engine_fault;
  image_pos location;
  image_pos maintain;
  image_pos voltage;
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

#include "light/light_view.h"
#include "screens/main_screen.h"
#include "tool/checkself.h"
#include "view/gear_view.h"
#include "view/oil_view.h"
#include "view/other_view.h"
#include "view/rpm_view.h"
#include "view/speed_view.h"
#include "view/water_view.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif // CELL_H_

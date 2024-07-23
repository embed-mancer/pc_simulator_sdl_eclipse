/**
* @file light_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-09-11-21
* @author Nemausa
*
*/
#ifndef LIGHT_VIEW_H_
#define LIGHT_VIEW_H_

#include "lvgl/lvgl.h"
#include "light.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
 kHide,
 kShow,
}DisplayTable;

typedef struct light_view {
  lv_obj_t *turn_left_;
  lv_obj_t *turn_right_;
  lv_obj_t *tpms_;
  lv_obj_t *maintain_;
  lv_obj_t *abs_;
  lv_obj_t *engine_fault_;
  lv_obj_t *gps_;
  lv_obj_t *g_;
  lv_obj_t *bt_;
  lv_obj_t *high_beam_;
  lv_obj_t *low_beam_;
  lv_obj_t *cruise_;
  lv_obj_t *voltage_;
  lv_obj_t *voltage_value_;
  lv_obj_t *voltage_unit_;
  lv_obj_t *key_;
  lv_obj_t *mode_;
  lv_obj_t *wifi_;
  lv_obj_t *park_;
  lv_obj_t *oil_pressure_;
  lv_obj_t *water_;
  lv_obj_t *water_value_;
  lv_obj_t *auto_hold_;
  lv_obj_t *tcs_;
  lv_obj_t *location_;
  lv_obj_t *clearance_;

  lv_obj_t *bg_;
  Light *light;
} LightView;

void LightViewInit(LightView *view);
void LightViewCreate(LightView *view);
void LightViewOne(LightView *view, lv_obj_t *lv, image_pos pos);


void LightViewTurnLeft(LightView *view, DisplayTable table);
void LightViewTurnRight(LightView *view, DisplayTable table);
void LightViewAbs(LightView *view, DisplayTable table);
void LightViewHighBeam(LightView *view, DisplayTable table);
void LightViewEngine(LightView *view, DisplayTable table);
void LightViewLocation(LightView *view, DisplayTable table);
void LightViewMaintain(LightView *view, DisplayTable table);
void LightViewVoltage(LightView *view, DisplayTable table);

#ifdef __cplusplus
}
#endif


#endif // LIGHT_VIEW_H_
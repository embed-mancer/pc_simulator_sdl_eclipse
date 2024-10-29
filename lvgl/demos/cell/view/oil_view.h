#ifndef OIL_VIEW_H_
#define OIL_VIEW_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

#define kOilNum 8

typedef enum {
  kOilViewModeBlock,
  kOilViewModeWidth,
} OilViewMode;

typedef struct oil_view {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[kOilNum];
  lv_obj_t *E;
  lv_obj_t *F;
  lv_obj_t *bg;
  image_pos pos_icon;
  image_pos pos_line;
  image_pos pos_block[kOilNum];
  label_pos pos_E;
  label_pos pos_F;
  OilViewMode mode; 
  int max_oil_value;
} OilView;

void OilViewInit(OilView *view, OilViewMode mode);
void OilViewCreate(OilView *view);
void OilViewUpdate(OilView *view, int value);

#ifdef __cplusplus
}
#endif

#endif  // OIL_VIEW_H_

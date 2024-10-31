#ifndef GUAGE_VIEW_H_
#define GUAGE_VIEW_H_

#include "../cell.h"

#define kGuageNum 8

typedef enum {
  kGuageViewModeBlock,
  kGuageViewModeWidth,
} GuageViewMode;

typedef struct {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[kGuageNum];
  lv_obj_t *label[2];
  lv_obj_t *background;
  ImagePos icon_position;
  ImagePos line_position;
  ImagePos block_position[kGuageNum];
  LabelPos label_position[2];
  GuageViewMode mode;
  int max_value;
} GuageView;

void GuageViewInit(GuageView *view, GuageViewMode mode);
void GuageViewCreate(GuageView *view);
void GuageViewUpdate(GuageView *view, int value);
void GuageViewToggleDayNightMode(GuageView *view);
void GuageViewMainOil(GuageView *view);
void GuageViewMainWater(GuageView *view);

#endif  // GUAGE_VIEW_H_

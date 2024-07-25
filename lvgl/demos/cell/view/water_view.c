#include "water_view.h"


void WaterViewInit(WaterView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < 8; ++i)
    view->block[i] = NULL;
}

void WaterViewCreate(WaterView *view) {
  for (int i = 0; i < 8; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line);
}

void WaterViewUpdate(WaterView *view, int value) {
  
}
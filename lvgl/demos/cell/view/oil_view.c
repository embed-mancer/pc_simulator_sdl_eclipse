#include "oil_view.h"

void OilViewInit(OilView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < 8; ++i)
    view->block[i] = NULL;
}

void OilViewCreate(OilView *view) {
  for (int i = 0; i < 8; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line);
}

void OilViewUpdate(OilView *view, int value) {

}
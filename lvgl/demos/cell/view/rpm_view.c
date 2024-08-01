#include "rpm_view.h"

void RpmViewInit(RpmView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < 24; ++i)
    view->block[i] = NULL;
  for (int i = 0; i < 7; ++i)
    view->num[i] = NULL;
}

void RpmViewCreate(RpmView *view) {
  for (int i = 0; i < 7; ++i) {
    LightViewOne(view->bg, &view->num[i], view->pos_num[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line); 
  for (int i = 0; i < 24; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
}

void RpmViewUpdate(RpmView *view, int value) {

}
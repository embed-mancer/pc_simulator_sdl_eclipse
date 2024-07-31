#include "gear_view.h"
#include "../cell.h"
#include "../light/light_view.h"

char sz_img[32];
void GearViewInit(GearView *view) {
  view->key = NULL;
  view->value = NULL;
}

void GearViewCreate(GearView *view) {
  LightViewOne(view->bg_, &view->key, view->pos_key);
  LightViewOne(view->bg_, &view->value, view->pos_value);
  strcpy(sz_img, view->pos_key.image);
}

void GearViewUpdate(GearView *view, int value) {
  char sz[4];
  sprintf(sz, "%d", value);
  char *temp = ReplaceSubstr(sz_img, "9", sz);
  strcpy(view->pos_key.image, temp);
  lv_img_set_src(view->key, view->pos_key.image);
  free(temp);
}
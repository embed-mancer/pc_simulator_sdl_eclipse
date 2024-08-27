#include "menu_screen.h"
#include "../view/view_menu.h"

lv_obj_t *menu_screen = NULL;

void MenuScreenInit() {
  menu_screen = lv_obj_create(NULL);
  lv_scr_load(menu_screen);
  MenuScreenCreate();
}

void MenuScreenCreate() {
  ViewMenuInit();
}

void MenuScreenClick(ClickTable table) {
  switch (table) {
    case kShortSet:
      break;
    case kLongSet:
      break;
    case kShortDown:
      break;
    case kLongDown:
      break;
  }  
}

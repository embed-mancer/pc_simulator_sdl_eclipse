#include "button_manager.h"
#include "../screens/screen_interface.h"
#include "../screens/home_screen.h"
#include "../screens/menu_screen.h"

static ClickTable table = kButtonEnd;

void ButtongManagerEvent(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e); 
  if (code == kButtonEnd)
    return;
  switch (code) {
    case kShortSet:
      table = kShortSet;
      break;
    case kLongSet:
      table = kShortSet;
      break;
    case kShortDown:
      table = kShortDown;
      break;
    case kLongDown:
      table = kLongDown;
      break;
  }
}

void ButtonManagerHandle() {
  PageTable page = ScreenInterfacePage();
  switch (page) {
    case kPageHome:
      HomeScreenClick(table);
      break;
    case kPageMenu:
      MenuScreenClick(table);
      break;
  }
}

void ButtonManagerRefresh() {
  if (table == kButtonEnd)
    return;
  ButtonManagerHandle();
  table = kButtonEnd;
}

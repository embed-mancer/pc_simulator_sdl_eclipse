#include "menu_manager.h"
#include "menu_theme.h"
#include <stdlib.h>

static UIComponent *current_screen = NULL;
uint8_t menu_page_id;

typedef UIComponent* (*CompontentFactory)(void);

CompontentFactory compontent_factories[] = {
  [kTheme] = MenuThemeInit,
};

void MenuManager() {
  menu_page_id = kTheme; 
  UIComponent * screen = MenuManagerCreateComponent(menu_page_id);
  MenuManagerSwitchScreen(screen);
}

void MenuManagerSwitchScreen(UIComponent *screen) {
  if (current_screen && current_screen->close_window) {
    current_screen->destory();
    free(current_screen);
    current_screen = NULL;
  }
  current_screen = screen;
}

void MenuManagerRefresh() {
  if (current_screen)
    current_screen->refresh();
}

void MenuManagerSendClick(ClickTable table) {
  MenuManagerUpdateTick();
  current_screen->click(table);
}

void MenuManagerClick(ClickTable table) {
  uint8_t page = menu_page_id;
  switch (table) {
    case kShortSet:
      ++page;
      break;
    case kShortMode:
      break;
    case kLongSet:
      // TODO go home
      break;
    case kLongMode:
      break;
  }

  if (page < kMenuPageEnd) {
    menu_page_id = page;
  } else {
    menu_page_id = kTheme;
  }

  UIComponent* compontent = MenuManagerCreateComponent(menu_page_id);
  MenuManagerSwitchScreen(compontent);
}

void MenuManagerSwitchDisplay() {
  if (current_screen)
    current_screen->switch_display();
}

void MenuManagerUpdateTick() {

}

// Use facotry
UIComponent* MenuManagerCreateComponent(MenuPage page) {
  if (page < sizeof(compontent_factories) / sizeof(compontent_factories[0]))
    return compontent_factories[page]();

  return NULL;
}

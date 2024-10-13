/**
* @file menu_manager.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-10-13-16-29
* @author Nemausa
*
*/
#ifndef MENU_MANAGER_H_
#define MENU_MANAGER_H_

#include "ui_component.h"

typedef enum {
  kTheme,
  kDisplay,
  kMenuPageEnd,
} MenuPage;

void MenuManager();
void MenuManagerSwitchScreen(UIComponent *screen);
void MenuManagerRefresh();
void MenuManagerSendClick(ClickTable);
void MenuManagerClick(ClickTable);
void MenuManagerSwitchDisplay();
void MenuManagerUpdateTick();
UIComponent* MenuManagerCreateComponent(MenuPage);

#endif // MENU_MANAGER_H_

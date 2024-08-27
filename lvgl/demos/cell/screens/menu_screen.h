/**
* @file menu_screen.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-26-18-03
* @author Nemausa
*
*/
#ifndef MENU_SCREEN_HPP_
#define MENU_SCREEN_HPP_

#include "../tool/button_manager.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MenuScreenInit();
void MenuScreenCreate();
void MenuScreenClick(ClickTable);

#ifdef __cplusplus
}
#endif


#endif // MENU_SCREEN_HPP_

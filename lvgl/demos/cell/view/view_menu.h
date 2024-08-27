/**
* @file view_menu.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-26-17-14
* @author Nemausa
*
*/
#ifndef VIEW_MENU_HPP_
#define VIEW_MENU_HPP_

#include "../menu/menu.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ViewMenuInit();
void ViewMenuCrate();
void ViewMenuLabel(lv_obj_t *label, const char* text, lv_coord_t x, lv_coord_t y);
void ViewMenuClick(ClickTable);
void ViewMenuUpdate();

#ifdef __cplusplus
}
#endif


#endif // VIEW_MENU_HPP_

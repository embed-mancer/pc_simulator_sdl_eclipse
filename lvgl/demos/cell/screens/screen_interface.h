/**
* @file screen_interface.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-22-10-43
* @author Nemausa
*
*/
#ifndef SCREEN_INTERFACE_HPP_
#define SCREEN_INTERFACE_HPP_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
  kPageHome,
  kPageMenu,
  kPageEnd,
} PageTable;

void ScreenInterfaceColor(lv_obj_t *, lv_color_t);
PageTable ScreenInterfacePage();
void ScreenInterfaceSetPage(PageTable);

#ifdef __cplusplus
}
#endif


#endif // SCREEN_INTERFACE_HPP_

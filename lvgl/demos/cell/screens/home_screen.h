/**
* @file home_screen.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-22-10-41
* @author Nemausa
*
*/
#ifndef HOME_SCREEN_HPP_
#define HOME_SCREEN_HPP_

#include "../tool/button_manager.h"

#ifdef __cplusplus
extern "C"
{
#endif

void HomeScreenInit();
void HomeScreenSpeed();
void HomeScreenOther();
void HomeScreenClick(ClickTable);

#ifdef __cplusplus
}
#endif


#endif // HOME_SCREEN_HPP_

/**
* @file view_other.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-22-17-49
* @author Nemausa
*
*/
#ifndef VIEW_OTHER_HPP_
#define VIEW_OTHER_HPP_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ViewOtherInit();
void ViewOtherCreate();
void ViewOtherRange();
void ViewOtherBattery();
void ViewOtherTrip();
void ViewOtherODO();
void ViewOtherLabel(lv_obj_t *label, const char* text, lv_color_t color,
                    const lv_font_t *font, lv_coord_t x, lv_coord_t y, 
                    lv_coord_t width);

#ifdef __cplusplus
}
#endif


#endif // VIEW_OTHER_HPP_

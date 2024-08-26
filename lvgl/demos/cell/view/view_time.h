/**
* @file view_time.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-22-18-05
* @author Nemausa
*
*/
#ifndef VIEW_TIME_HPP_
#define VIEW_TIME_HPP_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
  lv_obj_t *block[5];
  lv_obj_t *format;
}TimeView;

#ifdef __cplusplus
}
#endif


#endif // VIEW_TIME_HPP_

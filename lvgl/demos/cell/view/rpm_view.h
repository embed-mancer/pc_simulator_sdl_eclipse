/**
* @file rpm_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-24-15-17
* @author Nemausa
*
*/
#ifndef RPM_VIEW_H_
#define RPM_VIEW_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct rpm_view {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[24];
  lv_obj_t *num[7];
  lv_obj_t *bg;
  image_pos pos_icon;
  image_pos pos_line;
  image_pos pos_block[24];
  image_pos pos_num[7];
} RpmView;

void RpmViewInit(RpmView *view);
void RpmViewCreate(RpmView *view);
void RpmViewUpdate(RpmView *view, int value);
void RpmViewRun();
int RpmViewCurrent();


#ifdef __cplusplus
}
#endif


#endif // RPM_VIEW_H_
/**
* @file light.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-09-16-51
* @author Nemausa
*
*/
#ifndef LIGHT_H_
#define LIGHT_H_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
 int x;
 int y;
 char image[32];
 char prefix[32];
}image_pos;

typedef struct {
  image_pos abs;
  image_pos turn_left;
  image_pos turn_right;
}Light;

void LightInit();

extern Light light_main;

#ifdef __cplusplus
}
#endif


#endif // LIGHT_H_
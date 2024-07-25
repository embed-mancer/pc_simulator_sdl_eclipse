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

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LightInit();

extern Light light_main;

#ifdef __cplusplus
}
#endif


#endif // LIGHT_H_
/**
* @file main_screen.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-08-16-53
* @author Nemausa
*
*/
#ifndef MAIN_SCREEN_H_
#define MAIN_SCREEN_H_

#ifdef __cplusplus
extern "C"
{
#endif

void main_screen_init();
void main_scrren_light();
void MainScreenGear();
void MainScreenOil();
void MainScreenWater();
void MainScreenRpm();
void MainScreenOther();

#ifdef __cplusplus
}
#endif


#endif // MAIN_SCREEN_H_
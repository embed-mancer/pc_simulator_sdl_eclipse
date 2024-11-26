/**
 * @file button_control.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-15-20-44
 * @author Nemausa
 *
 */
#ifndef BUTTON_CONTROL_H_
#define BUTTON_CONTROL_H_

#include "../language/lang.h"

#ifdef __cplusplus
extern "C" {
#endif

void button_control_update(int button_index);
void button_control_refresh();
void button_control_init();
void button_control_destroy();
void button_control_set_title(language_e e);
void button_control_toggle_display();

#ifdef __cplusplus
}
#endif

#endif  // BUTTON_CONTROL_H_

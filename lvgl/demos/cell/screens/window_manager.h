/**
 * @file window_manager.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-14-12-18
 * @author Nemausa
 *
 */
#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

void window_manager_init();
void window_manager_switch();
void window_manager_set_target(window_e e);
window_e window_manager_get();
bool window_manager_is_active(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif  // WINDOW_MANAGER_H_

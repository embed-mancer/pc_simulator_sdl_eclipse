/**
 * @file checkself.h
 *
 * @brief Functions for initializing and managing the self-check process.
 *
 * This header file declares the functions for initializing, finishing,
 * checking, and setting the self-check process.
 *
 * @ingroup SelfCheckModule
 * @defgroup SelfCheckModule Self-Check Functions
 * @brief Module containing functions for self-check functionality.
 *
 * @date 2024-11-01-17-37
 * @author Nemausa
 */

#ifndef CHECKSELF_H_
#define CHECKSELF_H_

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the checkself module.
 *
 * This function initializes the resources and settings needed for the
 * self-check process.
 */
void checkself_init();

/**
 * @brief Finalizes the checkself module.
 *
 * This function releases any resources used by the self-check process and
 * performs any necessary cleanup.
 */
void checkself_finish();

/**
 * @brief Checks if the self-check process is currently active.
 *
 * @return true if the self-check process is active, false otherwise.
 */
bool checkself_is_checking();

/**
 * @brief Sets the status of the self-check process.
 *
 * @param[in] is_checking A boolean value indicating whether the self-check
 * process is active.
 */
void checkself_set_checking(bool is_checking);

#ifdef __cplusplus
}
#endif

#endif  // CHECKSELF_H_

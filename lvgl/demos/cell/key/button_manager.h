/**
 * @file button_manager.h
 *
 * @brief Manages button interactions and events.
 *
 * This header file declares functions for managing button clicks, handling
 * button events, and refreshing button states in the system.
 *
 * @ingroup ButtonManagerModule
 * @defgroup ButtonManagerModule Button Manager Functions
 * @brief Module for managing button events and interactions.
 *
 * @date 2024-11-15-17-45
 *
 * @author Nemausa
 */
#ifndef BUTTON_MANAGER_H_
#define BUTTON_MANAGER_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sets the current button click state.
 *
 * @param[in] click The current button click state to set.
 */
void button_manager_set_click(click_e click);

/**
 * @brief Retrieves the current button click state.
 *
 * @return The current button click state.
 */
click_e button_manager_get_click();

/**
 * @brief Handles button click events.
 *
 * This function processes button clicks and triggers the corresponding actions.
 */
void button_manager_handle();

/**
 * @brief Refreshes the button manager state.
 *
 * This function updates the button states, typically used when reinitializing
 * or updating the system.
 */
void button_manager_refresh();

/**
 * @brief Handles specific button events based on an ID.
 *
 * @param[in] id The ID of the button event to handle.
 */
void button_manager_event(uint32_t id);

#ifdef __cplusplus
}
#endif

#endif  // BUTTON_MANAGER_H_

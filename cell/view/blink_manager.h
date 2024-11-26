/**
 * @file blink_manager.h
 *
 * @brief Manages blinking functionality for UI objects.
 *
 * This header file declares the functions and structures used for managing
 * blinking animations for UI elements in the system.
 *
 * @ingroup BlinkManagerModule
 * @defgroup BlinkManagerModule Blink Manager Functions
 * @brief Module for managing blinking effects for UI elements.
 *
 * @date 2024-11-10-10-48
 *
 * @author Nemausa
 */
#ifndef BLINK_MANAGER_H_
#define BLINK_MANAGER_H_

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BLINK_INTERVAL_HZ_1 \
  500 /**< Blink interval for 1Hz frequency in milliseconds. */
#define BLINK_INTERVAL_HZ_2 \
  250 /**< Blink interval for 2Hz frequency in milliseconds. */
#define MAX_BLINK_COUNT \
  5 /**< Maximum number of objects that can blink simultaneously. */

/**
 * @brief Structure representing a group of objects to blink.
 */
typedef struct {
  lv_obj_t *objects[MAX_BLINK_COUNT]; /**< Array of objects to blink. */
  uint32_t last_update_time; /**< Last time the blink state was updated. */
  uint32_t blink_interval;   /**< Blink interval in milliseconds. */
  bool is_hidden; /**< Flag indicating if the objects are currently hidden. */
  uint8_t count;  /**< Number of objects in the group. */
} blink_group_t;

/**
 * @brief Structure representing the blink manager.
 */
typedef struct {
  blink_group_t group1; /**< First blink group. */
  blink_group_t group2; /**< Second blink group. */
  uint8_t current_page; /**< Current page for blinking purposes. */
} blink_manager_t;

/**
 * @brief Initializes the blink manager.
 *
 * @param[in,out] bm Pointer to the blink manager structure to initialize.
 */
void blink_manager_init(blink_manager_t *bm);

/**
 * @brief Starts the blinking process for the blink manager.
 *
 * @param[in,out] bm Pointer to the blink manager structure.
 */
void blink_manager_start(blink_manager_t *bm);

/**
 * @brief Adds an object to the blink manager for blinking.
 *
 * @param[in,out] bm Pointer to the blink manager structure.
 * @param[in] object Pointer to the object to be added for blinking.
 * @param[in] frequency The blinking frequency (in milliseconds).
 * @return true if the object was successfully added, false otherwise.
 */
bool blink_manager_add(blink_manager_t *bm, lv_obj_t *object,
                       uint32_t frequency);

/**
 * @brief Removes an object from the blink manager.
 *
 * @param[in,out] bm Pointer to the blink manager structure.
 * @param[in] object Pointer to the object to be removed from blinking.
 * @param[in] frequency The blinking frequency (in milliseconds).
 * @return true if the object was successfully removed, false otherwise.
 */
bool blink_manager_remove(blink_manager_t *bm, lv_obj_t *object,
                          uint32_t frequency);

/**
 * @brief Refreshes the blink manager state.
 *
 * This function updates the blinking state of all objects managed by the blink
 * manager.
 *
 * @param[in,out] bm Pointer to the blink manager structure.
 */
void blink_manager_refresh(blink_manager_t *bm);

#ifdef __cplusplus
}
#endif

#endif  // BLINK_MANAGER_H_

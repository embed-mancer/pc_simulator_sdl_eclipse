/**
 * @file veh_data_update.h
 *
 * @brief This message displayed in Doxygen Files index
 *
 * @ingroup PackageName
 * (note: this needs exactly one @defgroup somewhere)
 *
 * @date	2024-11-15-16-40
 * @author Nemausa
 *
 */
#ifndef VEH_DATA_UPDATE_H_
#define VEH_DATA_UPDATE_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Updates the state of the vehicle's indicator lights.
 *
 * This function updates the vehicle's indicator lights, such as the left and
 * right turn signals. It fetches the latest data for these indicators and
 * updates the corresponding light models.
 */
void veh_update_light();

/**
 * @brief Updates other vehicle-related data.
 *
 * This function updates other vehicle-related data, such as speed, engine RPM,
 * water temperature, oil level, gear position, and mileage. It fetches the
 * latest data and updates the corresponding motor models.
 */
void veh_update_other();

#ifdef __cplusplus
}
#endif

#endif  // VEH_DATA_UPDATE_H_

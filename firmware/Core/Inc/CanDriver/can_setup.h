/*
 * can_setup.h
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef INC_CANDRIVER_CAN_SETUP_H_
#define INC_CANDRIVER_CAN_SETUP_H_

#include "config.h"
#include "stm32g4xx_hal.h"

/**
  * @brief setup the filters of the CAN based on the config.h
  * @param hcan is the can handle
  * @param filters is the reference to the filter which will be set
  * @retval None
  */
void can_setup_filters(FDCAN_HandleTypeDef *hcan, FDCAN_FilterTypeDef *filters);

/**
  * @brief setup the CAN based on the config.h
  * @param hcan is the can handle
  * @param filters is the reference to the filter which will be set
  * @retval None
  */
void can_setup(FDCAN_HandleTypeDef *hcan, FDCAN_FilterTypeDef *filters);

#endif /* INC_CANDRIVER_CAN_SETUP_H_ */

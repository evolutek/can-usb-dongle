/*
 * can_setup.h
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef INC_CANDRIVER_CAN_SETUP_H_
#define INC_CANDRIVER_CAN_SETUP_H_

#include "stm32g4xx_hal.h"

#define CAN_ID_TYPE 		FDCAN_STANDARD_ID
#define	CAN_FILTER_INDEX	0
#define CAN_FILTER_TYPE		FDCAN_FILTER_RANGE_NO_EIDM
#define CAN_FILTER_CONFIG	FDCAN_FILTER_TO_RXFIFO0
#define CAN_FILTER_ID1		0x000
#define CAN_FILTER_ID2		0x7FF

#define CAN_RX_IT			FDCAN_IT_RX_FIFO0_NEW_MESSAGE

/**
  * @brief setup the filters of the CAN based on the config.h
  * @param hcan is the can handle
  * @retval None
  */
void can_setup_filters(FDCAN_HandleTypeDef *hcan);

/**
  * @brief setup the CAN based on the config.h
  * @param hcan is the can handle
  * @param filters is the reference to the filter which will be set
  * @retval None
  */
void can_setup(FDCAN_HandleTypeDef *hcan);

#endif /* INC_CANDRIVER_CAN_SETUP_H_ */

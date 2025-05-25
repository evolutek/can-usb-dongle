/*
 * can_com.c
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef SRC_CANDRIVER_CAN_COM_C_
#define SRC_CANDRIVER_CAN_COM_C_

#include "CanDriver/can_com.h"

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t filterIdx)
{
    FDCAN_RxHeaderTypeDef rxHeader;
    uint8_t rxData[64];

    HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rxHeader, rxData);

    // Handle rxData here
}

#endif /* SRC_CANDRIVER_CAN_COM_C_ */

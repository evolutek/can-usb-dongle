/*
 * config.h
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

// QUEUE CONFIG

//queue size in bytes
#define QUEUE_SIZE 128

// CAN CONFIG

#define CAN_ID_TYPE					FDCAN_STANDARD_ID
#define CAN_FILTER_INDEX			0
#define CAN_FILTER_TYPE				FDCAN_FILTER_MASK
#define CAN_FILTER_CONFIG			FDCAN_FILTER_TO_RXFIFO0
#define CAN_FILTER_ID1				0x0
#define CAN_FILTER_ID2				0x0

#define CAN_NOTIFICATION			FDCAN_IT_RX_FIFO0_NEW_MESSAGE                   \


#endif /* INC_CONFIG_H_ */

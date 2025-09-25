/*
 * can_com.h
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef INC_CANDRIVER_CAN_COM_H_
#define INC_CANDRIVER_CAN_COM_H_

#include "stm32g4xx_hal.h"

#include "Utils/queue.h"

#define MSG_PRIORITY_HIGH		0x00
#define MSG_PRIORITY_LOW		0x01

#define MSG_TYPE_ERROR 			0x00
#define MSG_TYPE_STATUS			0x01
#define MSG_TYPE_COMAND			0x02
#define MSG_TYPE_HEARTBEAT 		0x03

//#define MSG_ID_

#define BOARD_TYPE_ALL			0x00
#define BOARD_TYPE_RASPI		0x01
#define BOARD_TYPE_BEACON		0x02
#define BOARD_TYPE_ACTUATORS	0x03
#define BOARD_TYPE_ASSERV		0x04

#define MASK_PRIO 				0b00000000000000000000000000000001
#define MASK_MSG_TYPE 			0b00000000000000000000000000000110
#define MASK_MSG_ID				0b00000000000000000000000111111000
#define MASK_DST_BOARD_TYPE		0b00000000000000000001111000000000
#define MASK_DST_BOARD_ID		0b00000000000000011110000000000000
#define MASK_SRC_BOARD_TYPE		0b00000000000111100000000000000000
#define MASK_SRC_BOARD_ID		0b00000001111000000000000000000000
#define MASK_TRACKING			0b00011110000000000000000000000000

#define OFFSET_PRIO				0
#define OFFSET_MSG_TYPE			1
#define OFFSET_MSG_ID			3
#define OFFSET_DST_BOARD_TYPE	9
#define OFFSET_DST_BOARD_ID		13
#define OFFSET_SRC_BOARD_TYPE	17
#define OFFSET_SRC_BOARD_ID		21
#define OFFSET_TRACKING			25

#define GET(target, offset, id) (uint64_t)((data & id) >> offset)
#define SET(target, offset, value) target |= ((uint64_t)value << offset)

typedef struct can_rx_msg_s
{
	FDCAN_RxHeaderTypeDef RxHeader;
	uint8_t RxData[64];
} can_rx_msg_t;

typedef struct can_tx_msg_s
{
	FDCAN_TxHeaderTypeDef TxHeader;
	uint8_t TxData[64];
} can_tx_msg_t;


void can_flush_msg(FDCAN_HandleTypeDef* hfdcan, queue_t* q);

//uint8_t data[64]
can_tx_msg_t can_tx_msg_create(uint8_t prio,
								uint8_t msg_type,
								uint8_t msg_id,
								uint8_t dst_board_type,
								uint8_t dst_board_id,
								uint8_t src_board_type,
								uint8_t src_board_id,
								uint8_t tracking,
								uint8_t data);

void can_send_msg(FDCAN_HandleTypeDef* hfdcan, const can_tx_msg_t* msg);

#endif /* INC_CANDRIVER_CAN_COM_H_ */

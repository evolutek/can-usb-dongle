/*
 * can_com.c
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */

#ifndef SRC_CANDRIVER_CAN_COM_C_
#define SRC_CANDRIVER_CAN_COM_C_

#include "CanDriver/can_com.h"
#include "Utils/global.h"

#include <string.h> //memcpy

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0)
	{
		can_rx_msg_t msg;
		HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &msg.RxHeader, msg.RxData);

		queue_enqueue(&from_can_q, &msg, sizeof(can_rx_msg_t), queue_default_overflow_handler);
	}
}

can_tx_msg_t can_tx_msg_create(uint8_t prio,
								uint8_t msg_type,
								uint8_t msg_id,
								uint8_t dst_board_type,
								uint8_t dst_board_id,
								uint8_t src_board_type,
								uint8_t src_board_id,
								uint8_t tracking,
								uint8_t data[64])
{
	can_tx_msg_t msg;
	msg.TxHeader.Identifier = 0;
	SET(msg.TxHeader.Identifier, OFFSET_PRIO, prio);
	SET(msg.TxHeader.Identifier, OFFSET_MSG_TYPE, msg_type);
	SET(msg.TxHeader.Identifier, OFFSET_MSG_ID, msg_id);
	SET(msg.TxHeader.Identifier, OFFSET_DST_BOARD_TYPE, dst_board_type);
	SET(msg.TxHeader.Identifier, OFFSET_DST_BOARD_ID, dst_board_id);
	SET(msg.TxHeader.Identifier, OFFSET_SRC_BOARD_TYPE, src_board_type);
	SET(msg.TxHeader.Identifier, OFFSET_SRC_BOARD_ID, src_board_id);
	SET(msg.TxHeader.Identifier, OFFSET_TRACKING, tracking);

	msg.TxHeader.IdType = FDCAN_STANDARD_ID;
	msg.TxHeader.TxFrameType = FDCAN_DATA_FRAME;
	msg.TxHeader.DataLength = FDCAN_DLC_BYTES_8;
	msg.TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
	msg.TxHeader.BitRateSwitch = FDCAN_BRS_ON;   // FD bit rate switching
	msg.TxHeader.FDFormat = FDCAN_FD_CAN;
	msg.TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
	msg.TxHeader.MessageMarker = 0;

	memcpy(msg.TxData, data, 64);
	return msg; //big copy
}

void can_send_msg(FDCAN_HandleTypeDef* hfdcan, const can_tx_msg_t* msg)
{
	if (HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &msg->TxHeader, &msg->TxData) != HAL_OK)
	{
	    error_handler();
	}
}

void can_flush_msg(FDCAN_HandleTypeDef* hfdcan, queue_t* q)
{
	while(!PQUEUE_EMPTY(q))
	{
		can_tx_msg_t msg;
		if(queue_dequeue(q, &msg, sizeof(can_tx_msg_t)))
			error_handler();

		can_send_msg(hfdcan, &msg);
	}
}

#endif /* SRC_CANDRIVER_CAN_COM_C_ */

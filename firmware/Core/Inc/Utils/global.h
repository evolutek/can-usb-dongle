/*
 * global.h
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#ifndef INC_UTILS_GLOBAL_H_
#define INC_UTILS_GLOBAL_H_

#include "Utils/queue.h"

#define HIGH_PRIO 	0
#define LOW_PRIO	1

#define PRIO_LEVELS	2

#define USB_MSG_SIZE	64

extern uint8_t usb_rx_buffer[USB_MSG_SIZE];

extern queue_t from_usb_q; // queue_t<uint8_t>
extern queue_t from_can_q; // queue_t<can_rx_msg_t>	//FILED with interruptions

extern queue_t to_usb_q[PRIO_LEVELS];   // queue_t<uint8_t>
extern queue_t to_can_q[PRIO_LEVELS];   // queue_t<can_tx_msg_t>

extern volatile uint8_t usb_tx_is_busy;

void error_handler();

#endif /* INC_UTILS_GLOBAL_H_ */

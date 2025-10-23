/*
 * common.h
 *
 *  Created on: Oct 23, 2025
 *      Author: guilhem
 */

#ifndef INC_COMMON_COMMON_H_
#define INC_COMMON_COMMON_H_

#include "Utils/queue.h"

#include "CanDriver/can_com.h"
#include "USBDriver/usb_com.h"

can_tx_msg_t parse_msg(char buffer[USB_MSG_SIZE]);

void usb_get_and_parse(queue_t *from_usb_can, queue_t *to_can_q);

#endif /* INC_COMMON_COMMON_H_ */

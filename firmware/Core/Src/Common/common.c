/*
 * common.c
 *
 *  Created on: Oct 23, 2025
 *      Author: guilhem
 */


#include "Common/common.h"

static int find_r(char buffer[USB_MSG_SIZE])
{
	for(int i = 0; i < USB_MSG_SIZE; i++)
	{
		if(buffer[i] == '\r')
			return i;
	}

	return -1;
}

can_tx_msg_t parse_msg(char buffer[USB_MSG_SIZE])
{
	can_tx_msg_t msg;
	msg.TxHeader.IDE = CAN_ID_STD;
	msg.TxHeader.StdId = 0;
	msg.TxHeader.ExtId = 0;

	int strlen = find_r(bufffer);
	if(strlen < 0)
		return msg;

	//from https://github.com/LekElectronics/slcan/blob/9fddea4ad12b05acc519d90c3771ba5c54a81ea2/src/slcan.c#L84
	for (uint8_t i = 1; i < len; i++)
	{
		// Lowercase letters
		if(buf[i] >= 'a')
			buf[i] = buf[i] - 'a' + 10;
		// Uppercase letters
		else if(buf[i] >= 'A')
			buf[i] = buf[i] - 'A' + 10;
		// Numbers
		else
			buf[i] = buf[i] - '0';
	}

	//TODO parse command
	//TODO copy data

	return msg;
}

void usb_get_and_parse(queue_t *from_usb_can, queue_t *to_can_q)
{
	while(!QUEUE_EMPTY(from_usb_q))
	{
		//char *usb_msg = get_usb_msg(&from_usb_q);
		//can_tx_msg_t msg = parse_msg(&usb_msg);
		queue_enqueue(to_can_q, &msg, sizeof(can_tx_msg_t));
	}
}

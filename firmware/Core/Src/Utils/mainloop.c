/*
 * mainloop.c
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#include "Utils/mainloop.h"

#include "CanDriver/can_com.h"
#include "USBDriver/usb_com.h"
#include "Utils/queue.h"
#include "Utils/global.h"

queue_t from_usb_q;
queue_t from_can_q;

queue_t to_usb_q[PRIO_LEVELS];
queue_t to_can_q[PRIO_LEVELS];

void main_init(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd_USB_FS)
{
	queue_init(&from_usb_q);
	queue_init(&from_can_q);
	for(size_t prio_level = 0; prio_level < PRIO_LEVELS; prio_level++)
	{
		queue_init(&to_usb_q[prio_level]);
		queue_init(&to_can_q[prio_level]);
	}
	usb_setup(hpcd_USB_FS);
	can_setup(hfdcan);
}

void mainloop(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd)
{
	// High prio first
	for(size_t prio_level = 0; prio_level < PRIO_LEVELS; prio_level++)
	{
		//read from usb
		usb_get_and_parse(&from_usb_can[prio_level], &to_can_q[prio_level]);

		can_flush_msg(hfdcan, &to_can_q[prio_level]);

		usb_flush_msg(hpcd, &to_usb_q[prio_level]);
	}
}

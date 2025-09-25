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

void main_init(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd_USB_FS)
{
	queue_init(&from_usb);
	queue_init(&from_can);
	for(size_t prio_level = 0; prio_level < PRIO_LEVELS; prio_level++)
	{
		queue_init(&to_usb[prio_level]);
		queue_init(&to_can[prio_level]);
	}
	usb_setup(hpcd_USB_FS);
	can_setup(hfdcan);
}

void mainloop(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd_USB_FS)
{
	// High prio first
	for(size_t prio_level = 0; prio_level < PRIO_LEVELS; prio_level)
	{
		can_flush_msg(hfdcan, &to_can[prio_level]);
		//from_usb_to_can
		//from_can_to_usb
		//usb_flush_msg
	}
}

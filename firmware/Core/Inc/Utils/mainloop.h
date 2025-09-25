/*
 * mainloop.h
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#ifndef INC_UTILS_MAINLOOP_H_
#define INC_UTILS_MAINLOOP_H_

#include "CanDriver/can_setup.h"
#include "USBDriver/usb_setup.h"

void main_init(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd_USB_FS);
void mainloop(FDCAN_HandleTypeDef* hfdcan, PCD_HandleTypeDef *hpcd_USB_FS); //TODO add usb

#endif /* INC_UTILS_MAINLOOP_H_ */

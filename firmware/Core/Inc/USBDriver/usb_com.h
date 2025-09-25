/*
 * usb_com.h
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#ifndef INC_USBDRIVER_USB_COM_H_
#define INC_USBDRIVER_USB_COM_H_

#include "stm32g4xx_hal.h"

void usb_send_msg(PCD_HandleTypeDef *hpcd, const uint8_t* data, size_t size);

#endif /* INC_USBDRIVER_USB_COM_H_ */

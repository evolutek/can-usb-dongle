/*
 * usb_setup.c
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#include "USBDriver/usb_setup.h"
#include "Utils/global.h"

uint8_t usb_rx_buffer[USB_MSG_SIZE] = { 0 };

void usb_setup(PCD_HandleTypeDef *hpcd_USB_FS)
{
	HAL_PCD_EP_Open(hpcd_USB_FS, ENDPOINT1_IN, 64, USBD_EP_TYPE_BULK);   // IN
	HAL_PCD_EP_Open(hpcd_USB_FS, ENDPOINT1_OUT, 64, USBD_EP_TYPE_BULK);   // OUT

	HAL_PCD_EP_Receive(hpcd_USB_FS, ENDPOINT1_OUT, usb_rx_buffer, sizeof(usb_rx_buffer));
}

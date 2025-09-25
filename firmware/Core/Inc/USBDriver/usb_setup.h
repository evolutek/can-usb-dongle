/*
 * USB_setup.h
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#ifndef INC_USBDRIVER_USB_SETUP_H_
#define INC_USBDRIVER_USB_SETUP_H_


#include "stm32g4xx_hal.h"

#define ENDPOINT1_IN	0x01
#define ENDPOINT1_OUT	0x81

/**
  * @brief setup the USB
  * @param hcan is the can handle
  * @param filters is the reference to the filter which will be set
  * @retval None
  */
void usb_setup(PCD_HandleTypeDef *hpcd_USB_FS);

#endif /* INC_USBDRIVER_USB_SETUP_H_ */

/*
 * usb_com.c
 *
 *  Created on: Sep 25, 2025
 *      Author: guilhem
 */

#include "USBDriver/usb_com.h"
#include "USBDriver/usb_setup.h"
#include "Utils/queue.h"
#include "Utils/global.h"


void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
    if (epnum == 1)
    {
        queue_enqueue(&from_usb_q, usb_rx_buffer, USB_MSG_SIZE, queue_default_overflow_handler);

        // Prepare for next reception
        HAL_PCD_EP_Receive(hpcd, ENDPOINT1_OUT, usb_rx_buffer, sizeof(usb_rx_buffer));
    }
}

void usb_send_msg(PCD_HandleTypeDef *hpcd, const uint8_t* data, size_t size)
{
	while (hpcd->IN_ep[1].is_in_busy);

	HAL_PCD_EP_Transmit(hpcd, ENDPOINT1_IN, data, len);
}


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

volatile uint8_t usb_tx_is_busy = 0;

void HAL_PCD_DataOutStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
    if (epnum == 1)
    {
        queue_enqueue(&from_usb_q, usb_rx_buffer, USB_MSG_SIZE, queue_default_overflow_handler);

        // Prepare for next reception
        HAL_PCD_EP_Receive(hpcd, ENDPOINT1_OUT, usb_rx_buffer, sizeof(usb_rx_buffer));
    }
}

void HAL_PCD_DataInStageCallback(PCD_HandleTypeDef *hpcd, uint8_t epnum)
{
    if (epnum == 1)
    {
        usb_tx_is_busy = 0;
    }
}

void usb_send_msg(PCD_HandleTypeDef *hpcd, uint8_t* data, size_t size)
{
	while (usb_tx_is_busy);
	usb_tx_is_busy = 1;

	HAL_PCD_EP_Transmit(hpcd, ENDPOINT1_IN, data, size);
}

void usb_flush_msg(PCD_HandleTypeDef *hpcd, queue_t* q)
{
	while(!PQUEUE_EMPTY(q))
	{
		uint8_t msg[USB_MSG_SIZE];
		if(queue_dequeue(q, &msg, sizeof(usb_rx_buffer)))
			error_handler();

		usb_send_msg(hpcd, msg, sizeof(msg));
	}
}

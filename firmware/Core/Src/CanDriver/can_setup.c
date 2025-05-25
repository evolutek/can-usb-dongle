/*
 * can_setup.c
 *
 *  Created on: May 25, 2025
 *      Author: guilh
 */


#include "CanDriver/can_setup.h"

void can_setup_filters(FDCAN_HandleTypeDef *hcan, FDCAN_FilterTypeDef *filters)
{
	filters->IdType = CAN_ID_TYPE;
	filters->FilterIndex = CAN_FILTER_INDEX;
	filters->FilterType = CAN_FILTER_TYPE;
	filters->FilterConfig = CAN_FILTER_CONFIG;
	filters->FilterID1 = CAN_FILTER_ID1;
	filters->FilterID2 = CAN_FILTER_ID2;  // mask 0 => accept all IDs

	HAL_FDCAN_ConfigFilter(hcan, filters);
}

void can_setup(FDCAN_HandleTypeDef *hcan, FDCAN_FilterTypeDef *filters)
{
	can_setup_filters(hcan, filters);

	HAL_FDCAN_Start(hcan);

	HAL_FDCAN_ActivateNotification(hcan, CAN_NOTIFICATION, 0);
}

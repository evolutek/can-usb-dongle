/*
 * global.c
 *
 *  Created on: Sep 26, 2025
 *      Author: guilhem
 */

#include "Utils/global.h"
#include "main.h"

void error_handler()
{
	__disable_irq();
	while(1);
}

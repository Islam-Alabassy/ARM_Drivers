/*
 * GPIO_CNG.c
 *
 *  Created on: ???/???/????
 *      Author: Abdelrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GPIO_int.h"



MGPIO_Config_t TX = {
			.Port        = GPIO_PORTA,
			.Pin         = GPIO_PIN9,
			.Mode        = GPIO_MODE_ALTFUN,
			.OutputSpeed = GPIO_SPEED_LOW,
			.OutputType  = GPIO_OTYPE_PUSHPULL,
			.InputPull   = GPIO_INPUT_NO_PULL,
			.AltFunc     =GPIO_AF_7,

	};


MGPIO_Config_t RX = {
			.Port        = GPIO_PORTA,
			.Pin         = GPIO_PIN10,
			.Mode        = GPIO_MODE_ALTFUN,
			.OutputSpeed = GPIO_SPEED_LOW,
			.OutputType  = GPIO_OTYPE_PUSHPULL,
			.InputPull   = GPIO_INPUT_NO_PULL,
			.AltFunc     =GPIO_AF_7,

	};



MGPIO_Config_t led = {
			.Port        = GPIO_PORTA,
			.Pin         = GPIO_PIN1,
			.Mode        = GPIO_MODE_OUTPUT,
			.OutputSpeed = GPIO_SPEED_LOW,
			.OutputType  = GPIO_OTYPE_PUSHPULL,
			.InputPull   = GPIO_INPUT_NO_PULL,
			.AltFunc     =GPIO_NON_AF,

	};


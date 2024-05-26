/*
 * RCC_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"


void MRCC_vInit(void)
{

#if RCC_HSE_ENABLE == 1
	SET_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC->CFGR, SW1);
	SET_BIT(RCC->CR, HSEON);

#elif RCC_HSI_ENABLE == 1
	    CLR_BIT(RCC->CFGR, SW0); // SELECT INTERNAL CLOCK
		CLR_BIT(RCC->CFGR, SW1);
		//RCC->CFGR &=~(0b1111<<4); //DIV INTERNAL CLOCK BY 16
		//RCC->CFGR |=(0b1011<<4);
	    SET_BIT(RCC->CR, HSION); // ENABLE INTERNAL CLOCK

#endif

}

void MRCC_vEnableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,A_u32PeripheralId ) ;
		break;
	case RCC_AHB1LPENR:
		SET_BIT(RCC->AHB1LPENR,A_u32PeripheralId ) ;
		break;
	default:
		/* Error: Bus ID out of range */
		break;
	}
}

void MRCC_vDisableClock(u32 A_u32BusId, u32 A_u32PeripheralId)
{
	switch(A_u32BusId)
	{
	case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,A_u32PeripheralId ) ;
			break;
		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,A_u32PeripheralId ) ;
			break;
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,A_u32PeripheralId ) ;
			break;
		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,A_u32PeripheralId ) ;
			break;
		case RCC_AHB1LPENR:
			CLR_BIT(RCC->AHB1LPENR,A_u32PeripheralId ) ;
			break;
		default:
			/* Error: Bus ID out of range */
			break;
	}
}

/*
 * STK_prg.c
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */




#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "STK_int.h"
#include "STK_prv.h"
#include "STK_cfg.h"


static void (*GS_STK_Callback)(void) ;



void MSTK_vInit(void)
{
	/* 1- clock source */
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL, CLKSOURCE) ;
	CLR_BIT(STK->CTRL, TICKINT) ;
#elif STK_CLK_SOURCE == STK_AHB_DIV_8

	CLR_BIT(STK->CTRL, CLKSOURCE) ;
	CLR_BIT(STK->CTRL, TICKINT) ;


#endif
}


void MSTK_vStart(void)
{
	/* 1-  Stop the timer   */
	CLR_BIT(STK->CTRL, STK_ENABLE);
	/* 2- reset timer value */
	STK->VAL = 0 ;
	/* 3- Load timer with Value */
	STK->LOAD = 255 ;
	/* 4- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);

}



void MSTK_vResetTimer(void)
{
	    /*  Stop the timer   */
		 CLR_BIT(STK->CTRL, STK_ENABLE);
		/* reset timer value */
		 STK->VAL = 0 ;
		/*  Start the timer   */
		SET_BIT(STK->CTRL, STK_ENABLE);
}

void MSTK_vStoptimerAnd_Enterrupte(void)
{

	 /*  Stop the timer   */
	 CLR_BIT(STK->CTRL, STK_ENABLE);
	 /* reset timer value */
	  //STK->VAL = 0 ;
	  //Interrupt disable
	 CLR_BIT(STK->CTRL, TICKINT) ;

}


void MSTK_vSetBusyWait(u32 A_u32Ticks)
{
	/* 1- reset timer value */
	STK->VAL = 0 ;
	/* 2- Load timer with Value */
	STK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);
	/* 4-  wait for timer flag to be raised  */
	while(GET_BIT(STK->CTRL, COUNTFLAG) != 1  ){}
	/* 5-  Stop the timer   */
	CLR_BIT(STK->CTRL, STK_ENABLE);
}

void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	//  GET_BIT(STK->CTRL, COUNTFLAG);

	/* 0- set Callback function */
	GS_STK_Callback = CallbackFunction ;
	/* 1- reset timer value */
	STK->VAL = 0 ;
	/* 2- Load timer with Value */
	STK->LOAD = A_u32Ticks ;
	/* 3- Start the timer   */
	SET_BIT(STK->CTRL, STK_ENABLE);
	/* -Interrupt enable */
	SET_BIT(STK->CTRL, TICKINT) ;

}


u8 CreateVRandom_val(void)  // FUNCTION TO GENERATE RANDOM VALUE
{
	 u8 State_val= STK->VAL;

	 return State_val;

}


void SysTick_Handler()
{
	if(GS_STK_Callback != NULL)
	{
	}
	GS_STK_Callback();

	  GET_BIT(STK->CTRL, COUNTFLAG);
	  CLR_BIT(STK->CTRL, STK_ENABLE);
	  CLR_BIT(STK->CTRL, TICKINT);




}

















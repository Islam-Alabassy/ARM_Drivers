/*
 * STK_int.h
 *
 *  Created on: Sep 1, 2022
 *      Author: mazen
 */

#ifndef MCAL_STK_STK_INT_H_
#define MCAL_STK_STK_INT_H_

#define SCB_VTOR   	*((volatile u32*)(0xE000ED00+0x08))

typedef void (*function_t)(void) ;


void MSTK_vInit(void);

void MSTK_vStart(void);

u8 CreateVRandom_val(void);

void MSTK_vResetTimer(void);


void MSTK_vSetBusyWait(u32 A_u32Ticks);

void MSTK_vStoptimerAnd_Enterrupte(void);


void MSTK_vSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void));






#endif /* MCAL_STK_STK_INT_H_ */

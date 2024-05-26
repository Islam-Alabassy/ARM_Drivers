/*
 * UART_program.c
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahmanhossam
 */



#include  "../../LIB/STD_TYPES.h"
#include  "../../LIB/BIT_MATH.h"

#include "UART_configuration.h"
#include "UART_interface.h"
#include "UART_private.h"




static void (*MUSART1_CallBack)(void);




void MUSART_voidInit(USART_InitType *A_InitStruct)
{
	switch (A_InitStruct->Oversampling)
	{
	case OVER_SAMPLING_16: USART1->BRR = UART_BRR_SAMPLING16(__PCLK__,A_InitStruct->BaudRate); break;
	case OVER_SAMPLING_8 : USART1->BRR = UART_BRR_SAMPLING8(__PCLK__,A_InitStruct->BaudRate); break;
	}


	USART1->CR1 = (A_InitStruct->Oversampling << MUSART_CR1_OVER8_BIT)     |
				  (A_InitStruct->DataWidth <<MUSART_CR1_M_BIT);

	switch (A_InitStruct->TransferDirection)
	{
	case TX_ONLY: SET_BIT(USART1->CR1, MUSART_CR1_TE_BIT); break;
	case RX_ONLY: SET_BIT(USART1->CR1, MUSART_CR1_RE_BIT); break;
	case TX_RX:   SET_BIT(USART1->CR1, MUSART_CR1_TE_BIT);
				  SET_BIT(USART1->CR1, MUSART_CR1_RE_BIT); break;
	}

	USART1->CR2 =   (A_InitStruct->StopBits<<MUSART_CR2_STOP_BIT);

	USART1->SR = 0;
}


void MUSARTAnd_Enterrupte_Enable(void)
{
	SET_BIT(USART1->CR1,MUSART_CR1_UE_BIT);
	SET_BIT(USART1->CR1, MUSART_CR1_RXNEIE_BIT);//enterrupte eneble

}
void MUSARTAnd_Enterrupte_Disable(void)
{
	CLR_BIT(USART1->CR1,MUSART_CR1_UE_BIT);
	CLR_BIT(USART1->CR1, MUSART_CR1_RXNEIE_BIT);//enterrupte eneble}
}
void MUSART_voidTransmitByte (u8 A_u8Byte)
{
	while (GET_BIT(USART1->SR,MUSART_SR_TXE_BIT)==0);
	USART1->DR= A_u8Byte;
	while (GET_BIT(USART1->SR,MUSART_SR_TC_BIT)==0);
	CLR_BIT(USART1->SR,MUSART_SR_TC_BIT);
}


void MUSART_voidTransmitString ( u8 *A_ptru8String )
{
	u8 loc_u8Iterator =0;
	while (A_ptru8String[loc_u8Iterator] != '\0')
	{
		MUSART_voidTransmitByte(A_ptru8String[loc_u8Iterator]);
		loc_u8Iterator++;
	}
}

void MUSART1_voidSetCallBack( void (*ptr) (void) )
{
	MUSART1_CallBack = ptr ;
}



void USART1_IRQHandler(void)
{
	USART1->SR = 0 ;
	MUSART1_CallBack();
}



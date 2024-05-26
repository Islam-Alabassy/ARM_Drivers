/*
 * UART_interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




#define __BAUDRATE__ 9600
#define __PCLK__	 16000000


#define OVER_SAMPLING_16	0
#define OVER_SAMPLING_8 	1

#define TX_ONLY             0
#define RX_ONLY             1
#define TX_RX               2

#define EVEN_PARITY         0
#define ODD_PARITY          1

#define MODE_8BIT			0
#define MODE_9BIT			1

#define STOP_BIT_1			0
#define STOP_BIT_0_5		1
#define STOP_BIT_2			2
#define STOP_BIT_1_5		3

#define ENABLE				1
#define DISABLE				0




#define RCC_UART_ENABLE   4

typedef struct
{
	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 TransferDirection; // TX_ONLY  RX_ONLY  TX_RX
	u8 Oversampling;
}USART_InitType;


extern USART_InitType UART_Intial;



void MUSART_voidInit(USART_InitType *A_InitStruct);

void MUSARTAnd_Enterrupte_Enable(void);

void MUSARTAnd_Enterrupte_Disable(void);

void MUSART_voidTransmitByte (u8 A_u8Byte);

void MUSART_voidTransmitString (u8 * A_ptru8String );

void MUSART1_voidSetCallBack( void (*ptr) (void) );


#endif /* UART_INTERFACE_H_ */

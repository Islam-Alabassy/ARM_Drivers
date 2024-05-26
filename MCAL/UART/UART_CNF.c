/*
 * UART_CNF.c
 *
 *  Created on: ???/???/????
 *      Author: Abdelrahman
 */

#include  "../../LIB/STD_TYPES.h"
#include "UART_interface.h"

// INIAL VAL FOR USART

USART_InitType UART_Intial=
{
    .BaudRate= __BAUDRATE__, // BAUD_RATE 9600
    .DataWidth= MODE_8BIT, // 8BIT MODE
    .StopBits= STOP_BIT_1, // 1 STOP BIT
    .TransferDirection= TX_RX, // USART USE AS MULTI DIRECTION
    .Oversampling= OVER_SAMPLING_8, // 8 SAMPLING
};

/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"



#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_configuration.h"



void MNVIC_VoidEnablePeripheral(u8 Copy_u8INTID)
{
    MNVIC->ISER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}


void MNVIC_VoidDisablePeripheral(u8 Copy_u8INTID)
{
    MNVIC->ICER[Copy_u8INTID / 32] = 1 << (Copy_u8INTID % 32);
}



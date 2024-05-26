/*
 * FMI_prg.c
 *
 *  Created on: Oct 18, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "FMI_int.h"
#include "FMI_prv.h"
#include "FMI_cfg.h"


void FMI_vSectorErase(u8 A_u8SectorNo)
{
	/* 1- Wait if Flash is Busy (BSY) */
	while(GET_BIT(FMI->SR, 16) == 1){}
	/* 2- Unlock Flash Register using KEYR */
	if(GET_BIT(FMI->CR, 31) == 1)
	{
		FMI->KEYR = FMI_KEY1 ;
		FMI->KEYR = FMI_KEY2 ;
	}

	/* 3- select Sector Number to erase */
	FMI->CR &=~((u32)(0b1111<<3));
	FMI->CR |= (A_u8SectorNo <<3);

	/* 4- Select Erase operation */
	SET_BIT(FMI->CR, 1);
	/* 5- Start erase operation  */
	SET_BIT(FMI->CR, 16);
	/* 6- wait for Busy Flag    */
	while(GET_BIT(FMI->SR, 16) == 1){}
	/* 7- Clear EOP flag   */
	SET_BIT(FMI->SR, 0);

	/* 8- DeSelect Erase Operation (reverse of step 4) */
	CLR_BIT(FMI->CR, 1);
}


void FMI_vEraseAppArea(u8 FROM , u8 TO)
{

	for(u8 i=FROM;i<=TO;i++){

		FMI_vSectorErase(i);
	}

}



void FMI_vFlashWrite(u32 A_u32Address,
		             u16* A_pu16Data,
					 u16  A_u16Length)
{
	/* 1- Wait if Flash is Busy (BSY) */
	while(GET_BIT(FMI->SR, 16) == 1){}
	/* 2- Unlock Flash Register using KEYR */
	if(GET_BIT(FMI->CR, 31) == 1)
	{
		FMI->KEYR = FMI_KEY1 ;
		FMI->KEYR = FMI_KEY2 ;
	}

	/* 3- select element size (PSIZE)  */
	FMI->CR &=~((u32)(0b11<<8)) ;
	FMI->CR |= (0b01<<8);

	/* 4- Activate Programming Mode (PG bit) */
	SET_BIT(FMI->CR, 0);

	/* 5- Write Data Array on Flash address */
	for(u16 i=0; i<A_u16Length; i++)
	{
		*((volatile u16*)A_u32Address) = A_pu16Data[i];
		A_u32Address += 2 ;

		/* 6- wait for Busy Flag    */
		while(GET_BIT(FMI->SR, 16) == 1){}
		/* 7- Clear EOP flag   */
		SET_BIT(FMI->SR, 0);
	}
	/* 8- deactivate programming mode */
	CLR_BIT(FMI->CR, 0);

}



void FMI_vFlash_MarkerWrite(u16 A_u16Pattern)

{

	/* 1- Wait if Flash is Busy (BSY) */
		while(GET_BIT(FMI->SR, 16) == 1){}
		/* 2- Unlock Flash Register using KEYR */
		if(GET_BIT(FMI->CR, 31) == 1)
		{
			FMI->KEYR = FMI_KEY1 ;
			FMI->KEYR = FMI_KEY2 ;
		}

		/* 3- select element size (PSIZE)  */
		FMI->CR &=~((u32)(0b11<<8)) ;
		FMI->CR |= (0b01<<8);

		/* 4- Activate Programming Mode (PG bit) */
		   SET_BIT(FMI->CR, 0);
		/* 5- Erase Flash address */
		   FMI_vSectorErase(1);
	    /* 6- Write Data Array on Flash address */

		   Marker_Area = A_u16Pattern;

			/* 6- wait for Busy Flag    */
			while(GET_BIT(FMI->SR, 16) == 1){}
			/* 7- Clear EOP flag   */
			SET_BIT(FMI->SR, 0);
		   /* 8- deactivate programming mode */
		   CLR_BIT(FMI->CR, 0);


}

/*
 * HexParser_prg.c
 *
 *  Created on: Oct 20, 2022
 *      Author: mazen
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/FMI/FMI_int.h"
#include "HexParser_int.h"


#define FLASH_BASE_ADDR     0x08000000

u16 DataBuffer[100] ;


static u8 HexParser_u8Ascii2Hex(u8 A_u8Ascii)
{
	u8 L_u8HexValue = 0;

	if(A_u8Ascii >= '0' && A_u8Ascii <= '9')
	{
		L_u8HexValue = A_u8Ascii - '0' ;
	}
	else if(A_u8Ascii >= 'A' && A_u8Ascii <='F')
	{
		L_u8HexValue = A_u8Ascii - 55 ; // 55='A'-10
	}
	return L_u8HexValue;
}


 void HexParser_vParseData(u8 A_pu8Data[])
{
	/* charachter Count variables */
	u8 CC_high, CC_low, CC ;

	/* 4 digits for conversion */
	u8 digit0,digit1,digit2,digit3 ;

	/* Address variable */
	u32 address = 0;

	/* 1- convert charachter count */
	CC_high = HexParser_u8Ascii2Hex(A_pu8Data[1]);
	CC_low = HexParser_u8Ascii2Hex(A_pu8Data[2]);
	CC = (CC_high<<4)|CC_low ;

	/* 2- convert Address */
	digit0 = HexParser_u8Ascii2Hex(A_pu8Data[3]);
	digit1 = HexParser_u8Ascii2Hex(A_pu8Data[4]);
	digit2 = HexParser_u8Ascii2Hex(A_pu8Data[5]);
	digit3 = HexParser_u8Ascii2Hex(A_pu8Data[6]);


	address = (FLASH_BASE_ADDR) |
			  (digit0 << 12)    |
			  (digit1 << 8 )    |
			  (digit2 << 4 )    |
			  (digit3 << 0 );

	for(u8 i=0; i<(CC/2) ; i++)
	{
		digit0 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+9]);
		digit1 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+10]);
		digit2 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+11]);
		digit3 = HexParser_u8Ascii2Hex(A_pu8Data[(4*i)+12]);

		DataBuffer[i] = (digit0 << 12)    |
				        (digit1 << 8 )    |
				        (digit2 << 4 )    |
				        (digit3 << 0 );

	}

	FMI_vFlashWrite(address, DataBuffer, CC/2);

}





void HexParser_vParseData_2D(u8 (*A_pu8Data)[50])
{
	/* charachter Count variables */
	u8 CC_high, CC_low, CC ;
	/* 4 digits for conversion */
	u8 digit0,digit1,digit2,digit3 ;
	/* Address variable */
	u32 address = 0;
for(u16 i=0;A_pu8Data[i][8]!='1';i++){

	/* 1- convert charachter count */
	CC_high = HexParser_u8Ascii2Hex(A_pu8Data[i][1]);
	CC_low = HexParser_u8Ascii2Hex(A_pu8Data[i][2]);
	CC = (CC_high<<4)|CC_low ;

	/* 2- convert Address */
	digit0 = HexParser_u8Ascii2Hex(A_pu8Data[i][3]);
	digit1 = HexParser_u8Ascii2Hex(A_pu8Data[i][4]);
	digit2 = HexParser_u8Ascii2Hex(A_pu8Data[i][5]);
	digit3 = HexParser_u8Ascii2Hex(A_pu8Data[i][6]);


	address = (FLASH_BASE_ADDR) |
			  (digit0 << 12)    |
			  (digit1 << 8 )    |
			  (digit2 << 4 )    |
			  (digit3 << 0 );

	for(u8 j=0; j<(CC/2) ; j++)
	{
		digit0 = HexParser_u8Ascii2Hex(A_pu8Data[i][(4*j)+9]);
		digit1 = HexParser_u8Ascii2Hex(A_pu8Data[i][(4*j)+10]);
		digit2 = HexParser_u8Ascii2Hex(A_pu8Data[i][(4*j)+11]);
		digit3 = HexParser_u8Ascii2Hex(A_pu8Data[i][(4*j)+12]);

		DataBuffer[j] = (digit0 << 4)    |
				        (digit1 << 0 )   |
				        (digit2 << 12 )  |
				        (digit3 <<  8);

	}

	FMI_vFlashWrite(address, DataBuffer, CC/2);
}

}

u8 HexParser_u8VerifyCheckSum(u8 *A_pu8Data)
{
    u8 i,L_u8CalculatedCheckSum=0,L_u8ReceviedCheckSum=0,L_u8Status=0;
    /* character Count variables */
	u8 CC_high, CC_low, CC ;
	/* 2 digits for conversion */
	u8 digit0,digit1;
    /* convert character count */
	CC_high = HexParser_u8Ascii2Hex(A_pu8Data[1]);
	CC_low = HexParser_u8Ascii2Hex(A_pu8Data[2]);
	CC = (CC_high<<4)|CC_low ;
	CC+=5;//to add extra bytes of checksum , cc itself and address
	for(i=0;i<CC-1;i++)
    {
        digit0 = HexParser_u8Ascii2Hex(A_pu8Data[(2*i)+1]);
        digit1 = HexParser_u8Ascii2Hex(A_pu8Data[(2*i)+2]);
        L_u8CalculatedCheckSum+=  ((digit0 << 4 )  | (digit1 << 0 ));
    }
    digit0 = HexParser_u8Ascii2Hex(A_pu8Data[CC*2-1]);
    digit1 = HexParser_u8Ascii2Hex(A_pu8Data[CC*2]);
    L_u8CalculatedCheckSum = ((~L_u8CalculatedCheckSum)+0x01);
    L_u8ReceviedCheckSum=((digit0 << 4 )  | (digit1 << 0 ));
    if(L_u8CalculatedCheckSum == L_u8ReceviedCheckSum)
    {
        L_u8Status = 1;
    }
    else
    {
        L_u8Status = 0;
    }
    return L_u8Status;
}








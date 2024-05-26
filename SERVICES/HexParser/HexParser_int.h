/*
 * HexParser_int.h
 *
 *  Created on: Oct 20, 2022
 *      Author: mazen
 */

#ifndef APP_HEXPARSER_HEXPARSER_INT_H_
#define APP_HEXPARSER_HEXPARSER_INT_H_


void HexParser_vParseData(u8 A_pu8Data[]);
void HexParser_vParseData_2D(u8 (*A_pu8Data)[50]);

u8 HexParser_u8VerifyCheckSum(u8 *A_pu8Data);

#endif /* APP_HEXPARSER_HEXPARSER_INT_H_ */

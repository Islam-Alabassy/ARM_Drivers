/*
 * FMI_int.h
 *
 *  Created on: Oct 18, 2022
 *      Author: mazen
 */

#ifndef FMI_FMI_INT_H_
#define FMI_FMI_INT_H_

#define FMI_Enable  15

#define Marker_Area    *((volatile u16*)0x08004000)

void FMI_vEraseAppArea(u8 FROM , u8 TO);
void FMI_vSectorErase(u8 A_u8SectorNo);
void FMI_vFlashWrite(u32 A_u32Address,
		             u16* A_pu16Data,
					 u16  A_u16Length);

void FMI_vFlash_MarkerWrite(u16 A_u16Pattern);



#endif /* FMI_FMI_INT_H_ */

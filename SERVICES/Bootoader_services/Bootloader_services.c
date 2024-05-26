/*
 * Bootloader_services.c
 *
 *  Created on: ???/???/????
 *      Author: Abdelrahman
 */

#include "../../LIB/STD_TYPES.h"
#include "Bootloader_services.h"

u32 ApplyVsecurty(u8 Random_Val ) // APPLING SECUTY IN RANDOM VALUE
{

    u32 ValOfEquation; // VARIABLE FOR CARRING CHECK SECURTY
    ValOfEquation = (Random_Val*2)+100; // SIMPLE EQUATION IN BOOT_LOADER AND ESP82
    return ValOfEquation; // RETUEN CHECK SECURTY

}





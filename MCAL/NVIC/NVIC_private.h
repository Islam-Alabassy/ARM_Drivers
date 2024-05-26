/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

typedef struct
{

    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IAPR[32];
    volatile u32 RESERVED[32];
    volatile u8  IPR[128];

} NVIC;

#define MNVIC ((volatile NVIC *)0xE000E100)


#endif /* NVIC_PRIVATE_H_ */

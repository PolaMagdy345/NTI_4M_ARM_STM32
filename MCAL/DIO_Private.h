/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 6/11/2023			 	   */
/*     Description: DIO_Private.h	       */
/*******************************************/

#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H


/**************** Private For DIO Driver ****************/

extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);

/*******************************************************/

#define DIOA_BASE_ADDRESS		0x40010800
#define DIOB_BASE_ADDRESS		0x40010C00
#define DIOC_BASE_ADDRESS		0x40011000

/************* Register Adresses for PORTA *************/


#define DIOA_CRL		*((volatile u32*)  DIOA_BASE_ADDRESS	   )
#define DIOA_CRH		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x04))
#define DIOA_IDR		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x08))
#define DIOA_ODR		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x0C))
#define DIOA_BSR		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x10))
#define DIOA_BRR		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x14))
#define DIOA_LCK		*((volatile u32*) (DIOA_BASE_ADDRESS+ 0x18))


/************* Register Adresses for PORTB *************/


#define DIOB_CRL		*((volatile u32*)  DIOB_BASE_ADDRESS	   )
#define DIOB_CRH		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x04))
#define DIOB_IDR		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x08))
#define DIOB_ODR		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x0C))
#define DIOB_BSR		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x10))
#define DIOB_BRR		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x14))
#define DIOB_LCK		*((volatile u32*) (DIOB_BASE_ADDRESS+ 0x18))


/************* Register Adresses for PORTC *************/


#define DIOC_CRL		*((volatile u32*)  DIOC_BASE_ADDRESS	   )
#define DIOC_CRH		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x04))
#define DIOC_IDR		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x08))
#define DIOC_ODR		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x0C))
#define DIOC_BSR		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x10))
#define DIOC_BRR		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x14))
#define DIOC_LCK		*((volatile u32*) (DIOC_BASE_ADDRESS+ 0x18))





#endif

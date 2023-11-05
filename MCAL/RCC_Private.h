/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 1/11/2023		    	   */
/*     Description: RCC_Private.h  		   */
/*******************************************/



#ifndef __RCC_PRIVATE_H
#define __RCC_PRIVATE_H


/* 			Register Definitions		*/


#define	RCC_CR				*((volatile u32*)0x40021000)
#define	RCC_CFGR			*((volatile u32*)0x40021004)
#define	RCC_CIR				*((volatile u32*)0x40021008)
#define	RCC_APB2RSTR		*((volatile u32*)0x4002100C)
#define	RCC_APB1RSTR		*((volatile u32*)0x40021010)
#define	RCC_AHBENR			*((volatile u32*)0x40021014)
#define	RCC_APB2ENR			*((volatile u32*)0x40021018)
#define	RCC_APB1ENR			*((volatile u32*)0x4002101C)
#define	RCC_BDCR			*((volatile u32*)0x40021020)
#define	RCC_CSR				*((volatile u32*)0x40021024)


/******** Clock Types *******/

typedef enum{
	
	RCC_HSE_CRYSTAL=0,
	RCC_HSE_RC,
	RCC_HSI,
	RCC_PLL,

}RCC_Clock_t; 

/******* PLL Options *******/

//YOU MUST SELECT THE PLL MUL VAL BEFORE ENABLE PLL

#define RCC_PLL_MUL_VAL		4

typedef enum{
	
	RCC_PLL_IN_HSI_DIV2=0,
	RCC_PLL_IN_HSE_DIV2,
	RCC_PLL_IN_HSE
	
}RCC_PLL_Input_t; 

typedef enum{

	PLL_Input_clock_x2=0,
	PLL_Input_clock_x3,
	PLL_Input_clock_x4,
	PLL_Input_clock_x5,
	PLL_Input_clock_x6,
	PLL_Input_clock_x7,
	PLL_Input_clock_x8,
	PLL_Input_clock_x9,
	PLL_Input_clock_x10,
	PLL_Input_clock_x11,
	PLL_Input_clock_x12,
	PLL_Input_clock_x13,
	PLL_Input_clock_x14,
	PLL_Input_clock_x15,
	PLL_Input_clock_x16
	
}PLL_MUL_Factor_t;

#endif

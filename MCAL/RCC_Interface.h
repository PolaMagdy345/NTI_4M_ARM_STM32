/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 1/11/2023		    	   */
/*     Description: RCC_Private.h  		   */
/*******************************************/

#ifndef		__RCC_INTERFACE_H
#define		__RCC_INTERFACE_H


#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

void RCC_InitClk(void);

void RCC_Enable_Clk(u8 BusId, u8 PerId);

void RCC_Disable_Clk(u8 BusId, u8 PerId);





#endif

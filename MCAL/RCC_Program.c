/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 1/11/2023				   */
/*******************************************/

#include "StdTypes.h"
#include "Utils.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Cfg.h"


void RCC_InitClk(void)
{
	RCC_Clock_t x=RCC_CLOCK_TYPE;
	
	RCC_PLL_Input_t	y= PLL_INPUT_SELECTION;
	
	PLL_MUL_Factor_t z=	PLL_FACTOR;
	
	u32 TimeOut = 0;
	
	switch(x)
	{
		case RCC_HSE_CRYSTAL: 
				RCC_CFGR=0x00000001;
				RCC_CR	=0x00010000;		/*		Enable HSE with no bypass		*/
				while(((READ_BIT(RCC_CR , 17)) == 0) && (TimeOut < 100000))
				{
					TimeOut++;
				}
				if( TimeOut >= 100000 )
				{
					TimeOut=0;
					/* we will indicate that it is passed due to time out action */

				}
				break;

		case RCC_HSE_RC:
			CLR_BIT(RCC_CR, 16);

			/* BIT 18 -> To Select HSE BYPASS */
			/* HSEBYPASS Clock Enable */
			SET_BIT(RCC_CR, 18);

			/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
			/* HSE Selected As A System Clock */
			SET_BIT(RCC_CFGR, 0);
			CLR_BIT(RCC_CFGR, 1);

			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT(RCC_CR, 16);

			/* Bit 17 -> Checking While The HSE Clock Is Stable */
				while(((READ_BIT(RCC_CR , 17)) == 0) && (TimeOut < 100000))
				{
					TimeOut++;
				}
				if( TimeOut >= 100000 )
				{
					TimeOut=0;

					/* we will indicate that it is passed due to time out action */

				}
				break;

		case RCC_HSI:
				RCC_CFGR=0x00000000;
				RCC_CR	=0x00000001;		/*		Enable HSI	+ Trimming = 0	*/

				while(((READ_BIT(RCC_CR , 1)) == 0) && (TimeOut < 100000))
				{
					TimeOut++;
				}
				if( TimeOut >= 100000 )
				{
					TimeOut=0;

					/* we will indicate that it is passed due to time out action */

				}
				break;
				
		case RCC_PLL:
			CLR_BIT(RCC_CFGR,0);
			SET_BIT(RCC_CFGR,1);
			RCC_CFGR&=(~((0b1111)<<18));
			RCC_CFGR|=(z<<18);
				switch(y)
				{
					case RCC_PLL_IN_HSI_DIV2:
						CLR_BIT(RCC_CFGR,16);
						break;

					case RCC_PLL_IN_HSE_DIV2:
						SET_BIT(RCC_CR  ,16);
						SET_BIT(RCC_CFGR,16);		
						SET_BIT(RCC_CFGR,17);
						break;
					
					case RCC_PLL_IN_HSE:
						SET_BIT(RCC_CR  ,16);
						SET_BIT(RCC_CFGR,16);
						CLR_BIT(RCC_CFGR,17);
						break;
				}

				SET_BIT(RCC_CR,24);				/* PLL Clock Enable */
				while(((READ_BIT(RCC_CR , 25)) == 0) && (TimeOut < 100000))
				{
					TimeOut++;
				}
				if( TimeOut >= 100000 )
				{
					TimeOut=0;

					/* we will indicate that it is passed due to time out action */

				}
				break;
	}

}
void RCC_Enable_Clk(u8 BusId, u8 PerId)
{
		if(PerId <=	31)
		{
			switch(BusId)
			{
				case RCC_AHB:	SET_BIT(RCC_AHBENR, PerId);
								break;
				case RCC_APB1:	SET_BIT(RCC_APB1ENR, PerId);
								break;

				case RCC_APB2:	SET_BIT(RCC_APB2ENR, PerId);
								break;
			}
		}
		else
		{
			/*	Return Error	*/
		}
		
}


void RCC_Disable_Clk(u8 BusId, u8 PerId)
{
		if(PerId <=	31)
		{
			switch(BusId)
			{
				case RCC_AHB:	CLR_BIT(RCC_AHBENR, PerId);
								break;
				case RCC_APB1:	CLR_BIT(RCC_APB1ENR, PerId);
								break;

				case RCC_APB2:	CLR_BIT(RCC_APB2ENR, PerId);
								break;
			}
		}
		else
		{
			/*	Return Error	*/
		}
		
}

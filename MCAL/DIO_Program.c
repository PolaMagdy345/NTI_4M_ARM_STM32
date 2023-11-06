/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 6/11/2023				   */
/*     Description: DIO_Program.c 	       */
/*******************************************/

#include "StdTypes.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "Utils.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Cfg.h"



/********** Find it on DIO_Services.c **********/

static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
		if(pin<PINB0)
		{
			RCC_Enable_Clk(RCC_APB2,DIOA);
			if(pin<= PINA7)
			{
				DIOA_CRL&=~((0b1111)<<( pin * 4));
				DIOA_CRL|=((status)<< ( pin * 4));

			}
			else if(pin<= PINA15)
			{
				DIOA_CRH&=~((0b1111)<<( (pin-PINA8) * 4));
				DIOA_CRH|=(status)<<  ( (pin-PINA8) * 4);
			}
		}
		else if(pin<PINC0)
		{
			RCC_Enable_Clk(RCC_APB2,DIOB);

			if(pin<= PINB7)			//PINB0=16		PINB7=24
			{
				DIOB_CRL&=~((0b1111)<<( (pin-PINB0) * 4));
				DIOB_CRL|=(status)<<  ( (pin-PINB0) * 4);

			}
			else if(pin<= PINB15)
			{
				DIOB_CRH&=~((0b1111)<<( (pin-PINB8) * 4));
				DIOB_CRH|=(status)<<  ( (pin-PINB8) * 4);
			}
		}
		else if(pin<TOTAL_PINS)
		{
			RCC_Enable_Clk(RCC_APB2,DIOC);

			if(pin<= PINC7)			//PINB0=16		PINB7=24
			{
				DIOC_CRL&=~((0b1111)<<( (pin-PINC0) * 4));
				DIOC_CRL|=(status)<<  ( (pin-PINC0) * 4);

			}
			else if(pin<= PINC15)
			{
				DIOC_CRH&=~((0b1111)<<( (pin-PINC8) * 4));
				DIOC_CRH|=(status)<<  ( (pin-PINC8) * 4);
			}
		}
	}

void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type volt)
{
	if(volt==HIGH)
	{
		if(pin<=PINA15)
		{
			SET_BIT(DIOA_ODR, pin);
		}
		else if(pin<=PINB15)
		{
			SET_BIT(DIOB_ODR, (pin-PINB0));
		}
		else if(pin<=PINC15)
		{
			SET_BIT(DIOC_ODR, (pin-PINC0));
		}
	}
	else
	{
		if(pin<=PINA15)
		{
			CLR_BIT(DIOA_ODR, pin);
		}
		else if(pin<=PINB15)
		{
			CLR_BIT(DIOB_ODR, (pin-PINB0));
		}
		else if(pin<=PINC15)
		{
			CLR_BIT(DIOC_ODR, (pin-PINC0));
		}
	}
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_PinVoltage_type volt=LOW;
	
	if(pin<=PINA15)
	{
		volt=READ_BIT(DIOA_IDR, pin);
	}
	else if(pin<=PINB15)
	{
		volt=READ_BIT(DIOB_IDR, (pin-PINB0));
	}
	else if(pin<=PINC15)
	{
		volt=READ_BIT(DIOC_IDR, (pin-PINC0));
	}
	return volt;
}

/********** Find it on DIO_Services.c **********/

void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArr[i]);
	}
}

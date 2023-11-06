/*******************************************/
/*		Author	: Pola Magdy			   */
/*		Version	: V01					   */
/*		Date	: 5/11/2023			 	   */
/*     Description: DIO_Interface.h        */
/*******************************************/


#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

typedef enum{

	DIOA=2,
	DIOB,
	DIOC
}Buses_Name_t;

typedef enum
{

	/********* DIOA Pins *********/
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINA8,
	PINA9,
	PINA10,
	PINA11,
	PINA12,
	PINA13,
	PINA14,
	PINA15,
	
	/********* DIOB Pins *********/
	
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINB8,
	PINB9,
	PINB10,
	PINB11,
	PINB12,
	PINB13,
	PINB14,
	PINB15,
	
	/********* DIOC Pins *********/
	
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PINC8,
	PINC9,
	PINC10,
	PINC11,
	PINC12,
	PINC13,
	PINC14,
	PINC15,
	TOTAL_PINS
} DIO_Pin_type;

typedef enum
{
	INPUT_ANALOG=0,
	OUTPUT10KHZ_PUSHPALL,
	OUTPUT2KHZ_PUSHPALL,
	OUTPUT50KHZ_PUSHPALL,
	INPUT_FLOATING,
	OUTPUT10KHZ_OPENDRAIN,
	OUTPUT2KHZ_OPENDRAIN,
	OUTPUT50KHZ_OPENDRAIN,
	INPUT_PULL_UP_DOWN,
	OUTPUT10KHZ_AF_PUSHPALL,
	OUTPUT2KHZ_AF_PUSHPALL,
	OUTPUT50KHZ_AF_PUSHPALL,
	INPUT_RESERVED,
	OUTPUT10KHZ_AF_OPENDRAIN,
	OUTPUT2KHZ_AF_OPENDRAIN,
	OUTPUT50KHZ_AF_OPENDRAIN,
}DIO_PinStatus_type;

typedef enum{
	PA,
	PB,
	PC,
}DIO_Port_type;

typedef enum{
	LOW,
	HIGH
}DIO_PinVoltage_type;



void DIO_WritePin(DIO_Pin_type pin, DIO_PinVoltage_type volt);

void DIO_Init(void);

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin);

void DIO_PinDirection(u8 Port, u8 Pin, u8 Mode);

void DIO_PinValue(u8 Port, u8 Pin, u8 Mode);

void DIO_TogglePin(DIO_Pin_type pin);

void DIO_WritePort(DIO_Port_type port,u8 data);

u8 DIO_ReadPort(DIO_Port_type port);



#endif

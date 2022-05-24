/*
 * main.c
 *
 *  Created on: May 24, 2022
 *      Author: moham
 */

#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"
#include"../MCAL/MDIO/MDIO_Interface.h"
#include"../HAL/HCLCD/HCLCD_Interface.h"
#include"../MCAL/MADC/MADC_Interface.h"
#include<util\delay.h>

int main(void)
{
	volatile u8 Local_u8ADCReading;
	u16 MilliVolt;
	u8 temp;

	MDIO_Error_State_SetPinDirection(PIN7,MDIO_PORTD,PIN_OUTPUT);

	MADC_VidInit();                                       //  Initialize ADC
	HCLCD_Vid4Bits_Init();
	HCLCD_Vid4Bits_ClearScreen();
	HCLCD_Vid4Bits_SetPosition(1, 0);

	HCLCD_Vid4Bits_DisplayString((u8*) "SMART HOME");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();
	_delay_ms(1000);



	while (1)
	{
		Local_u8ADCReading = MADC_u16ADC_StartConversion(CHANNEL_0);
		MilliVolt = (u16) ((u32) Local_u8ADCReading * 5000UL) / 256UL;
		temp = MilliVolt / 10;
		if (temp > 15)
		{
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTD, PIN_HIGH);
		}
		else
		{
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTD, PIN_LOW);
		}
		HCLCD_Vid4Bits_SetPosition(1, 0);
		HCLCD_Vid4Bits_DisplayString((u8*) "TEMP =");
		HCLCD_Vid4Bits_DisplayNumber(temp);
		HCLCD_Vid4Bits_DisplayString((u8*) "C");
		HCLCD_Vid4Bits_SetPosition(2,0);
		HCLCD_Vid4Bits_DisplayString((u8*) "PRESS TO LOGIN");
		_delay_ms(1000);
		HCLCD_Vid4Bits_ClearScreen();
	}
	return 0;
}

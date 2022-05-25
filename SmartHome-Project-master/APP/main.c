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
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include<util\delay.h>

void ISR(void);

int main(void)
{
	u8 Local_u8ADCLM35;
	u8 Local_u8ADCLDR;
	u16 MilliVolt;
	u8 temp;




	MDIO_Error_State_SetPinDirection(PIN7,MDIO_PORTD,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(PIN2,MDIO_PORTD,PIN_INPUT);
	MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTD, PIN_HIGH);
	MDIO_Error_State_SetPortDirection(MDIO_PORTB,PORT_OUTPUT);


	EXTI_voidInt0SenseControl();
	EXTI_u8Int0SetCallBack(&ISR);
	EXTI_u8IntEnable(EXTI_INT0);
	GIE_voidEnable();
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
		Local_u8ADCLM35 = MADC_u16ADC_StartConversion(CHANNEL_0);
		Local_u8ADCLDR  = MADC_u16ADC_StartConversion(CHANNEL_1);
		MilliVolt = (u16) ((u32) Local_u8ADCLM35 * 5000UL) / 256UL;
		temp = MilliVolt / 10;
		if ((Local_u8ADCLDR == 0) && (Local_u8ADCLDR <= 28)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_HIGH);
		} else if ((Local_u8ADCLDR > 28) && (Local_u8ADCLDR <= 56)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 56) && (Local_u8ADCLDR <= 84)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 84) && (Local_u8ADCLDR <= 112)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 112) && (Local_u8ADCLDR <= 140)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 140) && (Local_u8ADCLDR <= 168)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 168) && (Local_u8ADCLDR <= 196)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_HIGH);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		} else if ((Local_u8ADCLDR > 196) && (Local_u8ADCLDR <= 224)) {
			MDIO_Error_State_SetPinValue(PIN0, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN1, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN2, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN3, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN4, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN5, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN6, MDIO_PORTB, PIN_LOW);
			MDIO_Error_State_SetPinValue(PIN7, MDIO_PORTB, PIN_LOW);
		}
		if (temp > 10)
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


void ISR(void)
{
	HCLCD_Vid4Bits_ClearScreen();
	_delay_ms(1000);
	HCLCD_Vid4Bits_SetPosition(1, 0);

	HCLCD_Vid4Bits_DisplayString((u8*) "LOGIN MODE");
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();
	_delay_ms(1000);

}

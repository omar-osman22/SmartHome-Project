/*
 * MDIO_Program.c
 *
 *  Created on: Jan 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"


#include"MDIO_Interface.h"
#include "MDIO_Config.h"
#include"MDIO_Private.h"

void DIO_voidInit		 (void)
{

	/*Set Init Direction For Ports*/
		DDRA = Conc(DIO_u8_PA7_DIRECTION,DIO_u8_PA6_DIRECTION,DIO_u8_PA5_DIRECTION,DIO_u8_PA4_DIRECTION,
							   DIO_u8_PA3_DIRECTION,DIO_u8_PA2_DIRECTION,DIO_u8_PA1_DIRECTION,DIO_u8_PA0_DIRECTION) ;

		DDRB = Conc(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,DIO_u8_PB4_DIRECTION,
							   DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION) ;

		DDRC = Conc(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,DIO_u8_PC4_DIRECTION,
							   DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION) ;

		DDRD = Conc(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,DIO_u8_PD4_DIRECTION,
							   DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION) ;

	/*Set Initial Values For Ports*/

		PORTA = Conc(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,
							    DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE) ;

		PORTB = Conc(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,
							    DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE) ;

		PORTC = Conc(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,
							    DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE) ;

		PORTD = Conc(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,
							    DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE) ;

}




/*Set Pin Direction Function */
Error_State  MDIO_Error_State_SetPinDirection(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8PinDirection)
{
	Error_State LOC_Error_State_ReturnState = OK;
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch (Copy_u8PortNumber)
		{

		case  MDIO_PORTA:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			else
			{
				LOC_Error_State_ReturnState = NOK;
			}
			break ;
		case  MDIO_PORTB:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRB,Copy_u8PinNumber);
			}
			else
			{
				LOC_Error_State_ReturnState = NOK;
			}
			break ;
		case  MDIO_PORTC:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRC,Copy_u8PinNumber);
			}
			else
			{
				LOC_Error_State_ReturnState = NOK;
			}
			break;
		case  MDIO_PORTD:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRD,Copy_u8PinNumber);
			}
			else
			{
				LOC_Error_State_ReturnState = NOK;
			}
			break ;
		default:
			LOC_Error_State_ReturnState = NOK;
			break ;
		}
	}
	else
	{
		LOC_Error_State_ReturnState = NOK;
	}
	return  LOC_Error_State_ReturnState ;

}

/*Set Port Direction Function */
Error_State  MDIO_Error_State_SetPortDirection(u8 Copy_u8PortNumber,u8 Copy_u8PortDirection)
{
	Error_State LOC_Error_State_ReturnState = OK;

	if((Copy_u8PortDirection==PORT_OUTPUT)||(Copy_u8PortDirection==PORT_INPUT))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			DDRA = Copy_u8PortDirection;
			break;
		case MDIO_PORTB:
			DDRB = Copy_u8PortDirection;
			break;
		case MDIO_PORTC:
			DDRC = Copy_u8PortDirection;
			break;
		case MDIO_PORTD:
			DDRD = Copy_u8PortDirection;
			break;
		default:
			LOC_Error_State_ReturnState = NOK;
			break ;
		}
	}
	else
	{
		LOC_Error_State_ReturnState = NOK;
	}
	return LOC_Error_State_ReturnState ;
}

/*Set Pin Value Function */
Error_State  MDIO_Error_State_SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8 Copy_u8PinValue)
{
	Error_State LOC_Error_State_ReturnState = OK;
		if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
		{
			switch (Copy_u8PortNumber)
			{

			case  MDIO_PORTA:
				if(Copy_u8PinValue==PIN_HIGH)
				{
					SET_BIT(PORTA,Copy_u8PinNumber);
				}
				else if(Copy_u8PinValue==PIN_LOW)
				{
					CLR_BIT(PORTA,Copy_u8PinNumber);
				}
				else
				{
					LOC_Error_State_ReturnState = NOK;
				}
				break ;
			case  MDIO_PORTB:
				if(Copy_u8PinValue==PIN_HIGH)
				{
					SET_BIT(PORTB,Copy_u8PinNumber);
				}
				else if(Copy_u8PinValue==PIN_LOW)
				{
					CLR_BIT(PORTB,Copy_u8PinNumber);
				}
				else
				{
					LOC_Error_State_ReturnState = NOK;
				}
				break ;
			case  MDIO_PORTC:
				if(Copy_u8PinValue==PIN_HIGH)
				{
					SET_BIT(PORTC,Copy_u8PinNumber);
				}
				else if(Copy_u8PinValue==PIN_LOW)
				{
					CLR_BIT(PORTC,Copy_u8PinNumber);
				}
				else
				{
					LOC_Error_State_ReturnState = NOK;
				}
				break;
			case  MDIO_PORTD:
				if(Copy_u8PinValue==PIN_HIGH)
				{
					SET_BIT(PORTD,Copy_u8PinNumber);
				}
				else if(Copy_u8PinValue==PIN_LOW)
				{
					CLR_BIT(PORTD,Copy_u8PinNumber);
				}
				else
				{
					LOC_Error_State_ReturnState = NOK;
				}
				break ;
			default:
				LOC_Error_State_ReturnState = NOK;
				break ;
			}
		}
		else
		{
			LOC_Error_State_ReturnState = NOK;
		}
		return  LOC_Error_State_ReturnState ;

}
/*Set Port Value Function */
Error_State  MDIO_Error_State_SetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue)
{
	Error_State LOC_Error_State_ReturnState = OK;

			switch(Copy_u8PortNumber)
			{
			case MDIO_PORTA:
				PORTA = Copy_u8PortValue;
				break;
			case MDIO_PORTB:
				PORTB = Copy_u8PortValue;
				break;
			case MDIO_PORTC:
				PORTC = Copy_u8PortValue;
				break;
			case MDIO_PORTD:
				PORTD = Copy_u8PortValue;
				break;
			default:
				LOC_Error_State_ReturnState = NOK;
				break ;
			}

		return LOC_Error_State_ReturnState ;
}
/*Get Pin Value Function */
Error_State  MDIO_Error_State_GetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber,u8* P_u8PinValue)
{
	Error_State LOC_Error_State_ReturnState = OK;

	if(((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))&&(P_u8PinValue !=(u8*)NULL_POINTER))
	{
	switch(Copy_u8PortNumber)
				{
				case MDIO_PORTA:
					*P_u8PinValue= GET_BIT(PINA,Copy_u8PinNumber);
					break;
				case MDIO_PORTB:
					*P_u8PinValue= GET_BIT(PINB,Copy_u8PinNumber);
					break;
				case MDIO_PORTC:
					*P_u8PinValue= GET_BIT(PINC,Copy_u8PinNumber);
					break;
				case MDIO_PORTD:
					*P_u8PinValue= GET_BIT(PIND,Copy_u8PinNumber);
					break;
				default:
					LOC_Error_State_ReturnState = NOK;
					break ;
				}
	}
	else
	{
		LOC_Error_State_ReturnState = NOK;
	}

	return LOC_Error_State_ReturnState ;

}

/*Toggle Pin Value Function */

/*Active Pull Up Resistor Function */

/*Set Nipple Direction Function */

/*Set Nipple Values Function */
Error_State MDIO_Error_State_SetNippleValue(u8 Copy_u8PinStart,u8 Copy_u8PortNumber,u8 Copy_u8Value)
{
	Error_State LOC_Error_State_ReturnState=OK;
	if(Copy_u8PinStart<=4)
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			PORTA&=(~(0x0F<<Copy_u8PinStart));
			PORTA|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case MDIO_PORTB:
			PORTB&=(~(0x0F<<Copy_u8PinStart));
			PORTB|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case MDIO_PORTC:
			PORTC&=(~(0x0F<<Copy_u8PinStart));
			PORTC|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		case MDIO_PORTD:

			PORTD&=(~(0x0F<<Copy_u8PinStart));
			PORTD|=(Copy_u8Value<<Copy_u8PinStart);
			break;
		default:
			LOC_Error_State_ReturnState=NOK;
		}
	}
	else
	{
		LOC_Error_State_ReturnState=NOK;
	}
	return LOC_Error_State_ReturnState;
}

/*Active Pull Up Resistor Function */
void  MDIO_VidActivePullUP(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber)
{
	MDIO_Error_State_SetPinDirection(Copy_u8PinNumber,Copy_u8PortNumber,PIN_INPUT);
    MDIO_Error_State_SetPinValue( Copy_u8PinNumber, Copy_u8PortNumber,PIN_HIGH);

}


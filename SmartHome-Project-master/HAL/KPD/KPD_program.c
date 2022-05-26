/**************************************************************/
/*************** Name    : Omar Osman *************************/
/*************** Date    : 11/1/2021   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : KPD        *************************/
/**************************************************************/

/*LIB Layer`*/
#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"
#include "../KPD/KPD_config.h"
#include "../KPD/KPD_interface.h"
#include "../KPD/KPD_private.h"

/*MCAL Layer*/
#include"..\..\MCAL\MDIO\MDIO_Interface.h"

/*HAL LAYER*/



u8 KPD_u8GetSwitch		(u8 * Copy_pu8ReturnedSwitch)
{
	u8 Local_u8ReturnState = 1;
	u8 Local_u8pinValue;
	u8 Local_u8Flag = 0;
	static u8 Local_Au8RowsPinArr[KPD_u8_ROWS_NB]=KPD_ROWS_PINS;
	static u8 Local_Au8ColsPinArr[KPD_u8_COLS_NB]=KPD_COLS_PINS;
	static u8 Local_Au8KPDValues[KPD_u8_ROWS_NB][KPD_u8_COLS_NB] = KPD_KEYS;
	if(Copy_pu8ReturnedSwitch != 0)
	{
		*Copy_pu8ReturnedSwitch = 0xff;
		for(u8 Local_u8RowsCounter = 0;Local_u8RowsCounter < KPD_u8_ROWS_NB ;Local_u8RowsCounter++)
		{
			/*Activate Each Row*/
			MDIO_Error_State_SetPinValue(Local_Au8RowsPinArr[Local_u8RowsCounter],KPD_u8_ROWS_PORT,0);
			/*Loop to check cols pins*/
			for(u8 Local_u8ColsCounter = 0; Local_u8ColsCounter < KPD_u8_COLS_NB  ; Local_u8ColsCounter ++)
			{
				/*check if col is in low state*/
				MDIO_Error_State_GetPinValue(Local_Au8ColsPinArr[Local_u8ColsCounter],KPD_u8_COLS_PORT,&Local_u8pinValue);
				if(Local_u8pinValue == 0)
				{
					*Copy_pu8ReturnedSwitch = Local_Au8KPDValues[Local_u8RowsCounter][Local_u8ColsCounter];
					while(Local_u8pinValue == 0)
					{
						MDIO_Error_State_GetPinValue(Local_Au8ColsPinArr[Local_u8ColsCounter],KPD_u8_COLS_PORT,&Local_u8pinValue);
					}
					Local_u8Flag = 1;
					break;
				}
			}
			/*Deactivate the current Row*/
			MDIO_Error_State_SetPinValue(Local_Au8RowsPinArr[Local_u8RowsCounter],KPD_u8_ROWS_PORT,1);
			if(Local_u8Flag == 1)
			{
				break;
			}
		}
	}
	else
	{
		Local_u8ReturnState = 0;
	}
	
	
	return Local_u8ReturnState;
	
}

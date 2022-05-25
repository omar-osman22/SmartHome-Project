/***********************************************************************/
/***********************************************************************/
/*********************    Author: Mohamed Osama   **********************/
/*********************    Layer:  MCAL            **********************/
/*********************    SWC:    EXTI            **********************/
/*********************    VER:    1.00            **********************/
/***********************************************************************/
/***********************************************************************/
#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"

#include "../EXTI/EXTI_config.h"
#include "../EXTI/EXTI_interface.h"
#include "../EXTI/EXTI_private.h"
#include "../EXTI/EXTI_register.h"



void (*EXTI_pvInt0PtrFunc)(void) = NULL;
void (*EXTI_pvInt1PtrFunc)(void) = NULL;
void (*EXTI_pvInt2PtrFunc)(void) = NULL;

void EXTI_voidInt0SenseControl(void)
{
#if INT0_SENSE_CONTROL == EXTI_LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SESCE_CONTROL == EXTI_ON_CHANGE

	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE_CONTROL == EXTI_FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE_CONTROL == EXTI_RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE_CONTROL Option"
#endif

}

void EXTI_voidInt1SenseControl(void)
{
#if INT1_SENSE_CONTROL == EXTI_LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SESCE_CONTROL == EXTI_ON_CHANGE

	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE_CONTROL == EXTI_FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE_CONTROL == EXTI_RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE_CONTROL Option"
#endif
}
void EXTI_voidInt2SenseControl(void)
{
#if INT2_SENSE_CONTROL == EXTI_FALLING_EDGE

	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT2_SENSE_CONTROL == EXTI_RISING_EDGE

	SET_BIT(MCUCSR,MCUCSR_INT2);

#else
#error "Wrong INT2_SENSE_CONTROL Option"
#endif
}
u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8IntNumber)
	{
	case EXTI_INT0: SET_BIT(GICR,GICR_INT0);
	break;
	case EXTI_INT1: SET_BIT(GICR,GICR_INT1);
	break;
	case EXTI_INT2: SET_BIT(GICR,GICR_INT2);
	break;
	default  : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState;

}
u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8IntNumber)
	{
	case EXTI_INT0: CLR_BIT(GICR,GICR_INT0);
	break;
	case EXTI_INT1: CLR_BIT(GICR,GICR_INT1);
	break;
	case EXTI_INT2: CLR_BIT(GICR,GICR_INT2);
	break;
	default  : Local_u8ErrorState = NOK ;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNumber , u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Sense)
	{
	case EXTI_LOW_LEVEL :
		switch (Copy_u8IntNumber)
            		{
            		case EXTI_INT0 :

            			CLR_BIT(MCUCR,MCUCR_ISC01);
            			CLR_BIT(MCUCR,MCUCR_ISC00);

            			break;
            		case EXTI_INT1 :

            			CLR_BIT(MCUCR,MCUCR_ISC11);
            			CLR_BIT(MCUCR,MCUCR_ISC10);

            			break;
            		case EXTI_INT2 :

            			Local_u8ErrorState = 2 ;

            			break;
            		default : Local_u8ErrorState = NOK ;
            		}
		break;
		case EXTI_ON_CHANGE :
			switch (Copy_u8IntNumber)
					{
					case EXTI_INT0 :

						CLR_BIT(MCUCR,MCUCR_ISC01);
						SET_BIT(MCUCR,MCUCR_ISC00);

						break;
					case EXTI_INT1 :

						CLR_BIT(MCUCR,MCUCR_ISC11);
						SET_BIT(MCUCR,MCUCR_ISC10);

						break;
					case EXTI_INT2 :

						Local_u8ErrorState = 2 ;

						break;
					default : Local_u8ErrorState = NOK ;
					}
			break;
		case EXTI_FALLING_EDGE :
			switch (Copy_u8IntNumber)
					{
					case EXTI_INT0 :

						SET_BIT(MCUCR,MCUCR_ISC01);
						CLR_BIT(MCUCR,MCUCR_ISC00);

						break;
					case EXTI_INT1 :

						SET_BIT(MCUCR,MCUCR_ISC11);
						CLR_BIT(MCUCR,MCUCR_ISC10);

						break;
					case EXTI_INT2 :

						CLR_BIT(MCUCSR,MCUCSR_INT2);

						break;
					default : Local_u8ErrorState = NOK ;
					}
			break;
		case EXTI_RISING_EDGE :
		switch (Copy_u8IntNumber)
				{
				case EXTI_INT0 :

					SET_BIT(MCUCR,MCUCR_ISC01);
					SET_BIT(MCUCR,MCUCR_ISC00);

					break;
				case EXTI_INT1 :

					SET_BIT(MCUCR,MCUCR_ISC11);
					SET_BIT(MCUCR,MCUCR_ISC10);

					break;
				case EXTI_INT2 :

					SET_BIT(MCUCSR,MCUCSR_INT2);

					break;
				default : Local_u8ErrorState = NOK ;
				}
		    break;
		default : Local_u8ErrorState = NOK ;

	}

	return Local_u8ErrorState ;
}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0PtrFunc = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState=OK;

		if(Copy_pvInt1Func != NULL)
		{
			EXTI_pvInt0PtrFunc = Copy_pvInt1Func;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}

	return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState=OK;

		if(Copy_pvInt2Func != NULL)
		{
			EXTI_pvInt0PtrFunc = Copy_pvInt2Func;
		}
		else
		{
			Local_u8ErrorState = NULL_POINTER;
		}

	return Local_u8ErrorState;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvInt0PtrFunc != NULL)
	{
		EXTI_pvInt0PtrFunc();
	}
	else
	{

	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvInt1PtrFunc != NULL)
	{
		EXTI_pvInt1PtrFunc();
	}
	else
	{

	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvInt2PtrFunc != NULL)
	{
		EXTI_pvInt2PtrFunc();
	}
	else
	{

	}
}


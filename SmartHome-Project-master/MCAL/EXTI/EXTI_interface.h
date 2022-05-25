/***********************************************************************/
/***********************************************************************/
/*********************    Author: Mohamed Osama   **********************/
/*********************    Layer:  MCAL            **********************/
/*********************    SWC:    EXTI            **********************/
/*********************    VER:    1.00            **********************/
/***********************************************************************/
/***********************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_LOW_LEVEL      1
#define EXTI_ON_CHANGE      2
#define EXTI_FALLING_EDGE   3
#define EXTI_RISING_EDGE    4

#define EXTI_INT0           0
#define EXTI_INT1           1
#define EXTI_INT2           2

void EXTI_voidInt0SenseControl(void);

void EXTI_voidInt1SenseControl(void);

void EXTI_voidInt2SenseControl(void);

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber);

u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber);

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNumber , u8 Copy_u8Sense);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif

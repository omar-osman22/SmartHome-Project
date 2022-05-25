/***********************************************************************/
/***********************************************************************/
/*********************    Author: Mohamed Osama   **********************/
/*********************    Layer:  MCAL            **********************/
/*********************    SWC:    EXTI            **********************/
/*********************    VER:    1.00            **********************/
/***********************************************************************/
/***********************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options For INT0 & INT1 1- EXTI_LOW_LEVEL
 *                        2- EXTI_ON_CHANGE
 *                        3- EXTI_FALLING_EDGE
 *                        4- EXTI_RISING_EDGE
 */
#define INT0_SENSE_CONTROL    EXTI_RISING_EDGE

#define INT1_SENSE_CONTROL    EXTI_FALLING_EDGE



/*Options For INT2        1- EXTI_FALLING_EDGE
 *                        2- EXTI_RISING_EDGE
 */
#define INT2_SENSE_CONTROL    EXTI_FALLING_EDGE

#endif

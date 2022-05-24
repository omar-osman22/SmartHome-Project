/*
 * MADC_Private.h
 *
 *  Created on: Jan 18, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

#define ADMUX      *((volatile u8*)0x27)
#define ADCSRA     *((volatile u8*)0x26)
#define ADC        *((volatile u16*)0x24)
#define SFIOR      *((volatile u16*)0x50)

#define  MADC_AVCC_REFERENCEVOLATGE      1
#define  MADC_2.56V_REFERENCEVOLATGE     2

#define MADC_BIT_MASKING_PRESCALER     0xF8
#define MADC_BIT_MASKING_CHANNEL       0x07
#define MADC_BIT_MASKING_REG_CHANNEL   0xE0

#define MADC_2_PRESCALER     1
#define MADC_4_PRESCALER     2
#define MADC_8_PRESCALER     3
#define MADC_16_PRESCALER    4
#define MADC_32_PRESCALER    5
#define MADC_64_PRESCALER    6
#define MADC_128_PRESCALER   7

#define MADC_RIGHT_ADJUST    0
#define MADC_LEFT_ADJUST     1


#endif /* MCAL_MADC_MADC_PRIVATE_H_ */

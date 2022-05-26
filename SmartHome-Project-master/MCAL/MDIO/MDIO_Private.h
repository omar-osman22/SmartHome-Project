/*
 * MDIO_Private.h
 *
 *  Created on: Jan 14, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef MCAL_MDIO_MDIO_PRIVATE_H_
#define MCAL_MDIO_MDIO_PRIVATE_H_

/*Local defines*/
/*Note: volatile because change it by Hardware*/

/*PORTA Registers*/

#define DDRA  *((volatile u8*) 0x3A)
#define PORTA *((volatile u8*) 0x3B)
#define PINA  *((volatile u8*) 0x39)   //because change it by Hardware

/*PORTB Registers*/
#define DDRB  *((volatile u8*) 0x37)
#define PORTB *((volatile u8*) 0x38)
#define PINB  *((volatile u8*) 0x36)

/*PORTC Registers*/
#define DDRC  *((volatile u8*) 0x34)
#define PORTC *((volatile u8*) 0x35)
#define PINC  *((volatile u8*) 0x33)

/*PORTD Registers*/
#define DDRD  *((volatile u8*) 0x31)
#define PORTD *((volatile u8*) 0x32)
#define PIND  *((volatile u8*) 0x30)


#define DIO_u8_INITIAL_OUTPUT				1
#define DIO_u8_INITIAL_INPUT				0


#define	DIO_u8_OUTPUT_HIGH					1
#define	DIO_u8_OUTPUT_LOW					0
#define	DIO_u8_INPUT_FLOATING				0
#define	DIO_u8_INPUT_PULLUP					1

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)		Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* MCAL_MDIO_MDIO_PRIVATE_H_ */

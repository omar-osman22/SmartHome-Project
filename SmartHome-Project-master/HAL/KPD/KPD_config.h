/**************************************************************/
/*************** Name    : Omar Osman *************************/
/*************** Date    : 11/1/2021   *************************/
/*************** Version : 1.0V       *************************/
/*************** SWC     : KPD        *************************/
/**************************************************************/

#ifndef KPD_config_H_
#define KPD_config_H_

/*If Your All Rows Are connected on only one port*/
/*ROWS ==>  Output*/
/*Set rows pins as output high*/
#define 	KPD_u8_ROWS_PORT		MDIO_PORTD

#define		KPD_u8_R1_PORT			MDIO_PORTD
#define		KPD_u8_R1_PIN			PIN4

#define		KPD_u8_R2_PORT			MDIO_PORTA
#define		KPD_u8_R2_PIN			PIN3

#define		KPD_u8_R3_PORT			MDIO_PORTD
#define		KPD_u8_R3_PIN			PIN6

#define		KPD_u8_R4_PORT 			MDIO_PORTD
#define		KPD_u8_R4_PIN			PIN7

/*If Your All Rows Are connected on only one Row*/
/*COLs ==>  Input*/
/* Set cols pins as input pull-up*/
#define 	KPD_u8_COLS_PORT		MDIO_PORTD

#define		KPD_u8_C1_PORT			MDIO_PORTD
#define		KPD_u8_C1_PIN			PIN3

#define		KPD_u8_C2_PORT			MDIO_PORTD
#define		KPD_u8_C2_PIN			PIN1

#define		KPD_u8_C3_PORT			MDIO_PORTD
#define		KPD_u8_C3_PIN			PIN0

#define		KPD_u8_C4_PORT 			MDIO_PORTA
#define		KPD_u8_C4_PIN			PIN2



#define KPD_u8_ROWS_NB		4
#define KPD_u8_COLS_NB		4

#define KPD_ROWS_PINS		{KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN}
#define KPD_COLS_PINS		{KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN}

#define 	KPD_KEYS	{{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'0','%','/','='}}
		
		
		
		
		
	








#endif

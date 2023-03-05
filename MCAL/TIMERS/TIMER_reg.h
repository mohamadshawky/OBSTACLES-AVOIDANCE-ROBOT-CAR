#ifndef MCAL_TIMERS_TIMER_REG_H_
#define MCAL_TIMERS_TIMER_REG_H_

#define TCCR0 				 *((volatile u8*)0x53) 			/*Timer0 Control Register*/
#define TCCR0_WGM00			 6								/*Waveform generation bit0*/
#define TCCR0_WGM01			 3                              /*Waveform generation bit0*/
#define TCCR0_CS02			 2                              /*Prescaler bit 2*/
#define TCCR0_CS01			 1                              /*Prescaler bit 1*/
#define TCCR0_CS00			 0                              /*Prescaler bit 0*/

#define OCR0 				 *((volatile u8*)0x5C)			/*Out compare register 0*/

#define TIMSK 				 *((volatile u8*)0x59)			/*Timer mask*/
#define TIMSK_OCI0			 1
#define TIMSK_TICIE1		 5								/*Timer 1 IC interrupt enable*/

#define TCCR1A 				 *((volatile u8*)0x4F) 			/*Timer1A Control Register*/
#define TCCR1A_WGM10		0
#define TCCR1A_WGM11		1
#define TCCR1A_COM1A0		6
#define TCCR1A_COM1A1		7

#define TCCR1B				 *((volatile u8*)0x4E) 			/*Timer1B Control Register*/
#define TCCR1B_WGM12		3
#define TCCR1B_WGM13		4
#define TCCR1B_ICES1		6

#define ICR1 				 *((volatile u16*)0x46) 			/*Top Register*/

#define OCR1A 				 *((volatile u16*)0x4A) 			/*Compare match Register*/
#define TCNT1 				 *((volatile u16*)0x4C)				/*Timer/counter1 register*/


#define TCCR2 				*((volatile u16*)0x45)
#define TCCR2_CS20			0
#define TCCR2_CS21			1
#define TCCR2_CS22			2
#define TCCR2_WGM21			3
#define TCCR2_COM20			4
#define TCCR2_COM21			5
#define TCCR2_WGM20			6


#define TCNT2 				*((volatile u16*)0x44)



#define OCR2 				*((volatile u16*)0x43)

#define PRESCALER_MASK	0b11111000
#define DEVIDE_BY_8		2
#endif /* MCAL_TIMERS_TIMER_REG_H_ */

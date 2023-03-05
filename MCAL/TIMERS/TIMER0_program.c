#include "../../util/BIT_MATH.h"
#include "../../util/STD_TYPES.h"

#include "TIMER0_config.h"
#include "TIMER_reg.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"


void TIMER0_voidInit(void)
{
	/*Choose Fast PMW Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Output compare match interrupt enable*/
	//	SET_BIT(TIMSK,TIMSK_OCI0);

	/*Set compare match value to 64 for duty cycle 25%*/
	OCR0 = 64;

	/*Prescaler : Div by 64*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	/*Non inverted mode(Clear on comp set on top)*/
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
}


void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}


void TIMER1_voidInit(void)
{
	/*Non inverting Mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*Wave gemeration Mode -> Fast PWM -> TOP:ICR1	Compare match : ocr1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Prescaler : 8 */
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DEVIDE_BY_8;

}


void TIMER2_voidInit(void)
{

}

void TIMER1_voidSetICR(u16 Copy_u16TOP)
{
	ICR1 = Copy_u16TOP;
}
void TIMER1_voidSetChannel1ACompMatch(u16 Copy_u16CompareMatch)
{
	OCR1A = Copy_u16CompareMatch;
}


void TIMER1_ICU_voidInit(void)
{
	/*Initialize at normal mode , prescaler devide by_8*/
	TCCR1B &= PRESCALER_MASK;
	TCCR1B |= DEVIDE_BY_8;
}


void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}

u16 TIMER1_voidReadTimerValue(void)
{
	return TCNT1;
}


















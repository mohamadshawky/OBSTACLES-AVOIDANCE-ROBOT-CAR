#include "../../util/STD_TYPES.h"
#include "../../util/BIT_MATH.h"
#include "PWM_config.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_reg.h"
#include "../TIMERS/TIMER_reg.h"

void PWM0_Init(void)
{
	/*Setting as  Fast PWM mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM00);

	/*Output mode : Set on Top Clear On Compare match (Non_inverted Mode)*/
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

	/*Prescaler: /64 */
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


}
u8 PWM0_Updated_Value(u8 value)
{

	/*OCR0 = (u8)(((u16)value*255UL)/5);*/
	OCR0 = value;
	return OCR0;
}


void PWM2_Init(void)
{
	/*Fast PWM*/
		SET_BIT(TCCR2,TCCR2_WGM20);
		SET_BIT(TCCR2,TCCR2_WGM21);

		/*Set compare match value to 64 for duty cycle 25%*/
		OCR2 = 64;

		/*Non inverted mode(Clear on comp set on top)*/
		SET_BIT(TCCR2,TCCR2_COM21);
		CLR_BIT(TCCR2,TCCR2_COM20);

		/*Prescaler : Div by 8*/
		CLR_BIT(TCCR2,TCCR2_CS20);
		SET_BIT(TCCR2,TCCR2_CS21);
		CLR_BIT(TCCR2,TCCR2_CS22);

}
u8 PWM2_Updated_Value(u8 value)
{

	/*OCR0 = (u8)(((u16)value*255UL)/5);*/
	OCR2 = value;
	return OCR2;
}

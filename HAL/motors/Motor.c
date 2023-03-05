#include "../../util/STD_TYPES.h"
#include "../../util/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Motor.h"
#include "../../MCAL/TIMERS/TIMER0_interface.h"
#include "../../MCAL/PWM/PWM_interface.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include<avr/delay.h>


void go_fwd (void)
{
	//PWM0_Updated_Value(240);
	//fwd of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
	//fwd of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
}
void go_rot (void)
{
	//PWM0_Updated_Value(240);
	//fwd of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	//fwd of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
}
void go_bwd (void)
{
	//PWM0_Updated_Value(220);
	//bwd of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	//bwd of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
}
void go_left (void)
{
	//PWM0_Updated_Value(220);
	//fwd of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);

	//stp of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
}
void go_right (void)
{
	//PWM0_Updated_Value(220);
	//fwd of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);

	//stb of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
}
void go_stb (void)
{
	//PWM0_Updated_Value(0);
	//fwd of dc motor 1
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);

	//stp of dc motor 2
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
	//_delay_ms(500);

}

/*void go_leftback(void){

	//fwd of dc motor 2
	DIO_vidSetPinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
	DIO_vidSetPinVal(DIO_PORTB,DIO_PIN7,DIO_LOW);
}*/

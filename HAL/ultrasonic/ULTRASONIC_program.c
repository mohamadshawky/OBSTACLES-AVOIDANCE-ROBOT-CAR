#include "../../util/STD_TYPES.h"
#include "../../util/BIT_MATH.h"
#include "ULTRASONIC_interface.h"


void UltraSonic_Init(void)
{
	TIMER1_ICU_voidInit();
	EXTI_voidInt0Init();

}
void Ultrasonic_Trigger(void)
{
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_LOW);
}


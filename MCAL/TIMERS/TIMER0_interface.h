#ifndef MCAL_TIMERS_TIMER0_TIMER_REGISTER_H_
#define MCAL_TIMERS_TIMER0_TIMER_REGISTER_H_

#include "../../util/STD_TYPES.h"

#define SIZE   10
#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE		2

void TIMER0_voidInit(void);
void TIMER1_voidInit(void);


void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 TIMER1_voidReadTimerValue(void);



void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);


void TIMER1_ICU_voidInit(void);


#endif /* MCAL_TIMERS_TIMER0_TIMER_REGISTER_H_ */

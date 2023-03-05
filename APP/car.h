#include <avr/delay.h>
#include "../util/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/INT/EXTI_interface.h"
#include "../MCAL/INT/GIE_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/TIMERS/TIMER0_interface.h"
#include "../HAL/ultrasonic/ULTRASONIC_interface.h"
#include "../HAL/motors/Motor.h"
#include "../HAL/SERVO/servo.h"
#include "../MCAL/PWM/PWM_interface.h"

#ifndef car_h
#define car_h

typedef enum {

car_fwd=0,
car_turn_180=1,
car_turn_90=2,

}car_states;



void UltraSonic_Distance(void);

void car_init(void);

void car_look_around(void);

void car_update(void);


#endif

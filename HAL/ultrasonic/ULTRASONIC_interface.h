#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

#include "../../util/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/INT/EXTI_interface.h"
#include "../../MCAL/TIMERS/TIMER0_interface.h"

void UltraSonic_Init(void);
//void UltraSonic_Distance(u16 *value);
void Ultrasonic_Trigger(void);
#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */

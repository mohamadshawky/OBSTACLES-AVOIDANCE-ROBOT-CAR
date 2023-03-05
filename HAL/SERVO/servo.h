#include <avr/delay.h>

#include "../../util/STD_TYPES.h"
typedef enum {
	Servo_left=0 ,
	Servo_right=1,
	Servo_front=2,
	
}angle ;



#ifndef SERVO_H_
#define SERVO_H_

void Servo_angle(u8 angle);
void Servo_init( void );


#endif /* SERVO_H_ */

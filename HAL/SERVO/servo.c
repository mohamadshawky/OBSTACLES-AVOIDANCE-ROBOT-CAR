#include "servo.h"

void Servo_init( void ){
	
	Servo_angle(Servo_front);
	_delay_ms(5000);
	Servo_angle(Servo_left);
	_delay_ms(5000);
	Servo_angle(Servo_right);
	_delay_ms(5000);
	Servo_angle(Servo_front);
	_delay_ms(5000);
	
}

void Servo_angle(angle an){
	if(an==Servo_front)
	{
		an=110;
	}
	else if (an==Servo_left)
	{
		an=175;
	}
	else if(an==Servo_right)
	{
		an=60;
	}
		PWM0_Updated_Value(an);// front angle
	
}

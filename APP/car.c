#include "car.h"

u16 distance =0;
u16 reading =0;
u8 left_flag=0,right_flag=0,front_flag=1;

car_states car_s=car_fwd;

void UltraSonic_Distance(void);

void car_init(void)
{

	PORT_voidInit();
	EXTI_u8Int0SetCallBack(&UltraSonic_Distance);
	UltraSonic_Init();
	PWM0_Init();
	PWM2_Init();
	GIE_voidEnable();
	Servo_init();
}

void UltraSonic_Distance(void)
{
	static u8 counter =0;

	counter++;

	if(counter == 1)
	{
		TIMER1_voidSetTimerValue(0);
		EXTI_u8Int0SetSenseControl(FALLING_EDGE);
	}
	else if(counter == 2)
	{
		reading = TIMER1_voidReadTimerValue();
		EXTI_u8Int0SetSenseControl(RISING_EDGE);

		distance = reading / 58;
		counter =0;
	}
}

void car_update(void)
{

	Ultrasonic_Trigger();

	switch(car_s)
	{

	case car_fwd:
	{
		while(distance>20)
		{
			Ultrasonic_Trigger();
			go_fwd();
			if(distance<20){
				go_stb();
				_delay_ms(3000);
				car_look_around();
				front_flag=0;
				break;
			}
		}

		if((left_flag == 1 || right_flag == 1) && front_flag == 0)
		{
			car_s=car_turn_90;

		}
		else if(left_flag == 0 && right_flag == 0 && front_flag == 0)
		{

			car_s=car_turn_180;

		}
		break;
	}
	case car_turn_180:
	{

		// rotate 180 function
		go_stb();
		_delay_ms(5000);
		go_rot();
		_delay_ms(5000);
		front_flag=1;
		go_stb();
		_delay_ms(5000);

		if( front_flag == 1)
		{
			car_s=car_fwd;
		}
		else if((left_flag == 1 || right_flag == 1) && front_flag == 0)
		{
			car_s=car_turn_90;
		}
		break;
	}
	case car_turn_90:
	{

		if(left_flag==1 )
		{
			go_left();
			_delay_ms(10000);
			go_stb();
			_delay_ms(5000);
			left_flag=0;
			right_flag=0;
			front_flag=1;
		}
		else if(right_flag==1 )
		{
			go_right();
			_delay_ms(10000);
			go_stb();
			_delay_ms(5000);
			front_flag=1;
			right_flag=0;
			left_flag=0;
		}

		if(left_flag == 0 && right_flag == 0 && front_flag == 0)
		{
			car_s=car_turn_180;
		}
		else if(front_flag == 1)
		{
			car_s=car_fwd;
		}
		break;
	}
	}
}




void car_look_around(void)
{
	//look left 
	Servo_angle(Servo_left);
	Ultrasonic_Trigger();
	_delay_ms(5000);
	Ultrasonic_Trigger();
	if(distance<20)
	{
		left_flag=0;
	}
	else{left_flag=1;
	}

	//look right 
	Servo_angle(Servo_right);
	Ultrasonic_Trigger();
	_delay_ms(5000);
	Ultrasonic_Trigger();

	if(distance<20)
	{
		right_flag=0;
	}
	else
	{
		right_flag=1;
	}
	Servo_angle(Servo_front);
}

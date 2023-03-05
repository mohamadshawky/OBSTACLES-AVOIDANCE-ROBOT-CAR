#include<avr/io.h>
#include<avr/delay.h>
#include "APP/car.h"
#define F_CPU 8000000UL

int main ()
{

	car_init();

	while(1)
	{

		car_update();

	}

	return 0;
}


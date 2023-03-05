#include "../../util/BIT_MATH.h"
#include "../../util/STD_TYPES.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Global pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt0func)(void) = NULL;

/*Global pointer to function to hold INT1 ISR address*/
void (*EXTI_pvInt1func)(void) = NULL;

/*Global pointer to function to hold INT2 ISR address*/
void (*EXTI_pvInt2func)(void) = NULL;


/*void EXTI_voidInt0Init(void)
{
	Set sense control for INIT0 (Falling Edge)
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

Peripheral interrupt enable for INIT0
	SET_BIT(GICR,GICR_INT0);
}*/


void EXTI_voidInt0Init(void)
{
	/*1- Check sense control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#else
#error "Wrong INT0_SENSE configuration option"
#endif

	/*Check peripheral interrupt enable initial state*/
#if INT0_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLE
	CLR_BIT(GICR,GICR_INT0);

#else
#error "Wrong INIT0_INITIAL_STATE configuration option"

#endif
}

u8 	 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{
	case LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01);     break;

	case ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00);	CLR_BIT(MCUCR,MCUCR_ISC01);     break;

	case FALLING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00);  break;

	case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00);   break;

	default :Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


void EXTI_voidInt1Init(void)
{
	/*1- Check sense control*/
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#else
#error "Wrong INT1_SENSE configuration option"
#endif

	/*Check peripheral interrupt enable initial state*/
#if INT1_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT1);

#elif INT1_INITIAL_STATE == DISABLE
	CLR_BIT(GICR,GICR_INT1);

#else
#error "Wrong INIT1_INITIAL_STATE configuration option"

#endif
}

u8 	 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{
	case LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11);     break;

	case ON_CHANGE: 	SET_BIT(MCUCR,MCUCR_ISC10);	CLR_BIT(MCUCR,MCUCR_ISC11);     break;

	case FALLING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC11);	CLR_BIT(MCUCR,MCUCR_ISC10); 	break;

	case RISING_EDGE:	SET_BIT(MCUCR,MCUCR_ISC11);	SET_BIT(MCUCR,MCUCR_ISC10);     break;

	default :Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


void EXTI_voidInt2Init(void)
{
	/*1- Check sense control*/
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_INT2);

#else
#error "Wrong INT2_SENSE configuration option"
#endif

	/*2-Check peripheral interrupt enable initial state*/
#if INT2_INITIAL_STATE == ENABLE
	SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL_STATE == DISABLE
	CLR_BIT(GICR,GICR_INT2);

#else
#error "Wrong INIT2_INITIAL_STATE configuration option"

#endif
}

u8 	 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Sense)
	{

	case FALLING_EDGE: 	CLR_BIT(MCUCSR,MCUCSR_INT2); 	break;

	case RISING_EDGE:	SET_BIT(MCUCSR,MCUCSR_INT2);     break;

	default :Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}


u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Int)
	{
	case INT0 : SET_BIT(GICR,GICR_INT0);	break;
	case INT1 : SET_BIT(GICR,GICR_INT1);	break;
	case INT2 : SET_BIT(GICR,GICR_INT2);	break;
	default   : Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int)
	{
	case INT0 : CLR_BIT(GICR,GICR_INT0);	break;
	case INT1 : CLR_BIT(GICR,GICR_INT1);	break;
	case INT2 : CLR_BIT(GICR,GICR_INT2);	break;
	default   : Local_u8ErrorState = NOK;	break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/*ISR for INT0*/

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvInt0func != NULL)
	{
		/*Calling Pointer to function as function by put his name after that put ()*/
		EXTI_pvInt0func();
	}
	else
	{
		//DO Nothing
	}
}


/*ISR for INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvInt0func != NULL)
	{
		/*Calling Pointer to function as function by put his name after that put ()*/
		EXTI_pvInt1func();
	}
	else
	{
		//DO Nothing
	}
}


/*ISR for INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvInt0func != NULL)
	{
		/*Calling Pointer to function as function by put his name after that put ()*/
		EXTI_pvInt2func();
	}
	else
	{
		//DO Nothing
	}
}




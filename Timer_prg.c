/*********************************************************************/
/*********************************************************************/
/**********Author: Mohamed Rezk Bayoumi*******************************/
/**********File: Timer_prg.c********************************************/
/**********Date: 1st oct 2022****************************************/
/**********Version: V1 ***********************************************/
/********* Desc: *****************************************************/
/*********************************************************************/
/*********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer_private.h"
#include "Timer_cfg.h"


static void (* Timer0_Ptr)(void);
static void (* Timer0_CTCCallback)(void);


void Timer_VidPreload(u8 Copy_U8PreloadVal)
{
	TCNT0=Copy_U8PreloadVal;
}

void Timer0_CTCCallbackFunc(void (* Copy_VidPtr)(void))
{
	Timer0_CTCCallback=Copy_VidPtr;
}

void Timer0_Callback(void (* Copy_VidPtr)(void))
{
	Timer0_Ptr=Copy_VidPtr;
}
void Timer_VidInit(void)
{
	/*TIMSK Register Settings*/
	CTC0=125;
	/*Timer/Counter0 OV Interrupt enable*/
#if TIMER0_OV==ON
	SET_BIT(TIMSK,0);
#elif TIMER0_OV==OFF
	CLEAR_BIT(TIMSK,0);
#endif

#if TIMER0_OCR==ON
	SET_BIT(TIMSK,1);
#elif TIMER0_OCR==OFF
	CLEAR_BIT(TIMSK,1);
#endif
	/*Disable Force Output compare*/
	CLEAR_BIT(TCCR0,7);


	/*Wave form Gen mode*/
#if MODE==NORMAL
	/* Clear WGM00*/
	CLEAR_BIT(TCCR0,6);
	/* Clear WGM01*/
	CLEAR_BIT(TCCR0,3);
#elif MODE==PHASE_CORRECT
	SET_BIT(TCCR0,6);
	CLEAR_BIT(TCCR0,3);
#elif MODE==CTC
	CLEAR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif MODE==FASTPWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#endif

	/*Normal Port operation*/
	/*Clear COM00 and COM01*/
	CLEAR_BIT(TCCR0,4);
	CLEAR_BIT(TCCR0,5);
	/*256 Prescaler*/
	/*Clear CS00 bit*/
	SET_BIT(TCCR0,0);
	/*Clear CS01 bit*/
	SET_BIT(TCCR0,1);
	/*Set CS02 bit*/
	CLEAR_BIT(TCCR0,2);



}


void __vector_10(void)
{
	Timer0_CTCCallback();
}


void __vector_11(void) 
{
	Timer0_Ptr();
}

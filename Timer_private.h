/*********************************************************************/
/*********************************************************************/
/**********Author: Mohamed Rezk Bayoumi*******************************/
/**********File: Timer_prg.c********************************************/
/**********Date: 1st oct 2022****************************************/
/**********Version: V1 ***********************************************/
/********* Desc: *****************************************************/
/*********************************************************************/
/*********************************************************************/


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_
void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));
#define TCCR0 *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52) 
#define TIMSK *((volatile u8 *)0x59)
#define CTC0 *((volatile u8 *)0x5c)
#define PRELOAD 247
#define NORMAL 0
#define PHASE_CORRECT 1
#define CTC 2
#define FASTPWM 3

#define ON 0
#define OFF 1

#endif 

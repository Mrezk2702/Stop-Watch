/*
 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: mrezk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "LCD_interface.h"
#include "GIE_interface.h"
#include "EXI_interface.h"
#include "StopWatch_interface.h"

void modify_TimeString(void);
void StopWatch_vidClock(void);
void Reset_Button(void);
void Pause_Button(void);
void Resume_Button(void);
/* the state of the stopwatch is either resume (counting)
 * or stop
 */
typedef enum
{
	stop=0,
	resume=1
}state;

state watch_state=stop; //initializing the stopwatch state
u8 * ptr_time; //pointer to the string to be printed
u8 seconds=0;
u8 minutes=0;
u8 hours=0;







void main (void)
{
	DIO_VidSetPinDirection(3,2,0); //corresponding pin to INT0 is input
		DIO_VidSetPinDirection(3,3,0); //corresponding pin to INT1 is input
		DIO_VidSetPinDirection(1,2,0);//corresponding pin to INT2 is input
		//activating pull up for input pins
		DIO_VidSetPinValue(3,2,1);
		DIO_VidSetPinValue(3,3,1);
		DIO_VidSetPinValue(1,2,1);
		u8  time[9]="00:00:00";
		ptr_time=time;
		LCD_VidInit();
		LCD_VidSendString(time);
		//handling ISRs using call back
		INT_VidInit();
		INT0_CallBack(&Reset_Button);
		INT1_CallBack(&Resume_Button);
		INT2_CallBack(&Pause_Button);
		Timer_VidInit();
		Timer0_CTCCallbackFunc(&StopWatch_vidClock);
		GIE_VidEna();
	while(1)
	{

	}
}




void modify_TimeString(void)
{
	ptr_time[0]=hours/10+'0';
	ptr_time[1]=hours%10+'0';
	ptr_time[3]=minutes/10+'0';
	ptr_time[4]=minutes%10+'0';
	ptr_time[6]=seconds/10+'0';
	ptr_time[7]=seconds%10+'0';

	LCD_VidGoToPos(0,0);
	LCD_VidSendString(ptr_time);
}


void StopWatch_vidClock(void)
{
	static u16 counter=0;
	counter++;
	if(counter==1000) //1000 millisecond
	{
		if(watch_state==resume)
		{
			seconds++;
			if(seconds==60)
			{
				minutes++;
				seconds=0;
			}
			if(minutes==60)
			{
				hours++;
				minutes=0;
			}

		}
		modify_TimeString();
		counter=0;
	}

}


void Resume_Button(void)
{
	watch_state=resume;

}

void Pause_Button(void)
{
	watch_state=stop;
}


void Reset_Button(void)
{
	seconds=0;
	minutes=0;
	hours=0;
	watch_state=stop;
	modify_TimeString();
}

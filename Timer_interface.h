






#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
void Timer_VidInit(void);
void Timer_VidPreload(u8 Copy_U8PreloadVal);
void Timer0_Callback(void (* Copy_VidPtr)(void));
void Timer0_CTCCallbackFunc(void (* Copy_VidPtr)(void));


#endif

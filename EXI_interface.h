
#ifndef EXI_INTERFACE_H_
#define EXI_INTERFACE_H_
void INT_VidInit(void);
void INT0_CallBack(void (* Copy_VidPtr)(void));
void INT1_CallBack(void (* Copy_VidPtr)(void));
void INT2_CallBack(void (* Copy_VidPtr)(void));
void GIE_VidEna(void);
void GIE_VidDis(void);

#endif

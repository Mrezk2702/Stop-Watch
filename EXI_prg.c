/*********************************************************************/
/*********************************************************************/
/**********Author: Mohamed Rezk Bayoumi*******************************/
/**********File: EXI_prg.c***************************************/
/**********Date: 23th sep 2022*****************************************/
/**********Version: V1 ***********************************************/
/*********************************************************************/
#include "STD_TYPES.h"
#include "bit_math.h"
#include "EXI_private.h"
#include "EXI_cfg.h"
#include "DIO_interface.h"
 static void (* INT0_Ptr)(void);
 static void (* INT1_Ptr)(void);
 static void (* INT2_Ptr)(void);

void INT0_CallBack(void (* Copy_VidPtr)(void))
{
	INT0_Ptr=Copy_VidPtr;
}
void INT1_CallBack(void (* Copy_VidPtr)(void))
{
	INT1_Ptr=Copy_VidPtr;
}
void INT2_CallBack(void (* Copy_VidPtr)(void))
{
	INT2_Ptr=Copy_VidPtr;
}
void INT_VidInit(void)
{
	/*Set interrupt sense control for INT0=Falling edge*/
	CLEAR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	CLEAR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
	
	
	
	/*Enable INT0*/
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
}










void __vector_1(void)
{
	INT0_Ptr();
}
void __vector_2(void)
{
	INT1_Ptr();
}
void __vector_3(void)
{
	INT2_Ptr();
}

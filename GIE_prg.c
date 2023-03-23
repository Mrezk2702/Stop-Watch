

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"

void GIE_VidEna(void)
{
	SET_BIT(SREG,7);
}

void GIE_VidDis(void)
{
	CLEAR_BIT(SREG,7);
}

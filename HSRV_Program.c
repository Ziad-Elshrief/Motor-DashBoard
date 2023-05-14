#include "std_types.h"
#include "HSRV_Interface.h"
#include "MTMR_Interface.h"


void HSRV_voidSetAngle(u8 Copy_u8Angle ){
	MTMR_voidTMR1Init();
	MTMR_u8TMR1SetCompareMatchValueChannelA( (100*Copy_u8Angle/9)+450 );
}

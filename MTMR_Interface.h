#ifndef MTMR_INTERFACE_H
#define MTMR_INTERFACE_H

void MTMR_voidTMR0Init(void);

u8 MTMR_u8TMR0SetCallBack( u8 Copy_u8TMRIndex , void(*Copy_Pf)(void) );

void MTMR_u8TMR0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);

void MTMR_voidStopTMR0(void);

void MTMR_voidTMR1Init(void);

void MTMR_u8TMR1SetCompareMatchValueChannelA(u16 Copy_u16CompareMatchValue);


#define MTMR_u8_TMR0_OVF			0
#define MTMR_u8_TMR0_CTC			1

#endif

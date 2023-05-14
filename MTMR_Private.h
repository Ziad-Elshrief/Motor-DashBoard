#ifndef MTMR_PRIVATE_H
#define MTMR_PRIVATE_H

#define MTMR_u8_TCCR0_REG			*((volatile u8*)0x53)

#define MTMR_u8_TCNT0_REG			*((volatile u8*)0x52)

#define MTMR_u8_OCR0_REG			*((volatile u8*)0x5C)

#define MTMR_u8_TIMSK_REG			*((volatile u8*)0x59)

#define MTMR_u8_TIFR_REG			*((volatile u8*)0x58)

#define MTMR_u8_TCCR1A_REG			*((volatile u8*)0x4F)

#define MTMR_u8_TCCR1B_REG			*((volatile u8*)0x4E)

#define MTMR_u16_TCNT1_REG			*((volatile u16*)0x4C)

#define MTMR_u16_OCR1A_REG			*((volatile u16*)0x4A)

#define MTMR_u16_OCR1B_REG			*((volatile u16*)0x48)

#define MTMR_u16_ICR1_REG			*((volatile u16*)0x46)


#define MTMR_u8_TMR0_NORMAL_MODE						0b00000000
#define MTMR_u8_TMR0_CTC_MODE							0b00001000
#define MTMR_u8_TMR0_FAST_PWM_MODE						0b01001000
#define MTMR_u8_TMR0_PWM_PHASE_CORRECT_MODE				0b01000000

#define MTMR_u8_TMR0_NoPre              	0b00000001
#define MTMR_u8_TMR0_pre8              		0b00000010
#define MTMR_u8_TMR0_pre64              	0b00000011
#define MTMR_u8_TMR0_pre256           	  	0b00000100
#define MTMR_u8_TMR0_pre1024             	0b00000101
#define MTMR_u8_TMR0_EXT_T0_FallingEdge  	0b00000110
#define MTMR_u8_TMR0_EXT_T0_RisingEdge   	0b00000111


#endif

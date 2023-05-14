#ifndef MTMR_CONFIG_H
#define MTMR_CONFIG_H

/*Timer0 Mode Selection:
 * 1- MTMR_u8_TMR0_NORMAL_MODE
 * 2- MTMR_u8_TMR0_CTC_MODE
 * 3- MTMR_u8_TMR0_FAST_PWM_MODE
 * 4- MTMR_u8_TMR0_PWM_PHASE_CORRECT_MODE	*/
#define MTMR_u8_TMR0_MODE					MTMR_u8_TMR0_PWM_PHASE_CORRECT_MODE

 #define MTMR_u8_TMR0_PRELOAD_VALUE			0

/*Timer0 Presclaer:
 * 1- 	MTMR_u8_TMR0_NoPre
 * 2-	MTMR_u8_TMR0_pre8
 * 3-	MTMR_u8_TMR0_pre64
 * 4-	MTMR_u8_TMR0_pre256
 * 5-	MTMR_u8_TMR0_pre1024
 * 6-	MTMR_u8_TMR0_EXT_T0_FallingEdge
 * 7-	MTMR_u8_TMR0_EXT_T0_RisingEdge
 * */
#define MTMR_u8_Prescaler_Value		MTMR_u8_TMR0_pre8

#endif

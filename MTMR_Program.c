#include "std_types.h"
#include "bit_math.h"

#include"MTMR_Config.h"
#include "MTMR_Interface.h"
#include "MTMR_Private.h"

static void(*MTMR_Pf[2])(void) = {STD_TYPES_NULL , STD_TYPES_NULL} ;

void MTMR_voidTMR0Init(void){

	/*Select Timer0 Mode*/
	MTMR_u8_TCCR0_REG |=  MTMR_u8_TMR0_MODE ;
	/*Set Preload Value*/
	//MTMR_u8_TCNT0_REG = MTMR_u8_TMR0_PRELOAD_VALUE;
	/*Enable OVF Interrupt*/
	//SET_BIT(MTMR_u8_TIMSK_REG,0);

	/*Select non inverted mode */
	SET_BIT(MTMR_u8_TCCR0_REG ,5);
	CLR_BIT(MTMR_u8_TCCR0_REG ,4);
	/*Enable Interrupt compare match*/
	//SET_BIT(MTMR_u8_TIMSK_REG,1);

	/*Set compare match math Reg */
	MTMR_u8_OCR0_REG = 0;
	/*Set Prescaler Value*/
	MTMR_u8_TCCR0_REG |= MTMR_u8_Prescaler_Value ;
}

u8 MTMR_u8TMR0SetCallBack( u8 Copy_u8TMRIndex , void(*Copy_Pf)(void) ){
	u8 Local_u8ErrorState= STD_TYPES_NOK;
	if( (Copy_Pf != STD_TYPES_NULL) && (Copy_u8TMRIndex <2) ){
		Local_u8ErrorState=STD_TYPES_OK;
		MTMR_Pf[Copy_u8TMRIndex]=Copy_Pf;
	}
	return Local_u8ErrorState;
}

/*Prototype of ISR of OVF TMR0 */

void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	if(Local_u16Counter==3907){
		/*Update Preload value*/
		//MTMR_u8_TCNT0_REG = MTMR_u8_TMR0_PRELOAD_VALUE;
		/*Action*/
		if(MTMR_Pf[MTMR_u8_TMR0_OVF] != STD_TYPES_NULL){
			MTMR_Pf[MTMR_u8_TMR0_OVF]();
		}
		/*Clear Counter*/
		Local_u16Counter =0;
	}
}


/*Prototype of ISR of CTC TMR0 */
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	if(Local_u16Counter == 10000){
		/*Action*/
		if(MTMR_Pf[MTMR_u8_TMR0_CTC] != STD_TYPES_NULL){
			MTMR_Pf[MTMR_u8_TMR0_CTC]();
		}
		Local_u16Counter=0;
	}
}

void MTMR_voidStopTMR0(void){
	MTMR_u8_TCCR0_REG &= 0b11111000;
}

void MTMR_u8TMR0SetCompareMatchValue(u8 Copy_u8CompareMatchValue){
	MTMR_u8_OCR0_REG = Copy_u8CompareMatchValue;
}


void MTMR_voidTMR1Init(void){

		/*Select Timer1 Mode*/
		CLR_BIT(MTMR_u8_TCCR1A_REG ,0);
		SET_BIT(MTMR_u8_TCCR1A_REG ,1);
		SET_BIT(MTMR_u8_TCCR1B_REG ,3);
		SET_BIT(MTMR_u8_TCCR1B_REG ,4);
		/*Select non inverted mode */
		CLR_BIT(MTMR_u8_TCCR1A_REG ,6);
		SET_BIT(MTMR_u8_TCCR1A_REG ,7);
		/*Set top value in ICR1 Reg Freq =50Hz => 20 ms */
		MTMR_u16_ICR1_REG =19999;
		/*Set intial value for OCR1A */
		MTMR_u16_OCR1A_REG = 550 ;
		/*Set Prescaler Value*/
		CLR_BIT(MTMR_u8_TCCR1B_REG ,0);
		SET_BIT(MTMR_u8_TCCR1B_REG ,1);
		CLR_BIT(MTMR_u8_TCCR1B_REG ,2);
}

void MTMR_u8TMR1SetCompareMatchValueChannelA(u16 Copy_u16CompareMatchValue){
	MTMR_u16_OCR1A_REG = Copy_u16CompareMatchValue ;
}


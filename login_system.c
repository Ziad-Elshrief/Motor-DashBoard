/*LIB Layer*/
#include "std_types.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

/*MCAL*/
#include "MDIO_Interface.h"

/*HAL*/
#include "HKPD_Interface.h"
#include "HLCD_interface.h"

u8 LoginSystem(u16 Copy_u16Pass,u8 * Copy_pu8LoginState);
#define LoginFailed 		0
#define LoginSucceed		1

u8 LoginSystem(u16 Copy_u16Pass,u8 * Copy_pu8LoginState){
	u8 Local_u8ErorrState = STD_TYPES_OK;
	u16 Local_u16tempNum=Copy_u16Pass;
	u8 Local_u8DigitNum=0;
	u8 Local_u8KeyValue;
	u8 Local_u8Tries=1;
	u16 Local_u16Pass=0;
	u16 Local_u16DigitPlace=1;
	u16 Local_u16Digit;
	while(Local_u16tempNum!=0){
		Local_u16tempNum=Local_u16tempNum/10;
		Local_u8DigitNum++;
	}

	for(u8 Local_u8LoopCount=0;Local_u8LoopCount<(Local_u8DigitNum-1);Local_u8LoopCount++){
		Local_u16DigitPlace=Local_u16DigitPlace*10;
	}
	Local_u16Digit=Local_u16DigitPlace;
	HLCD_u8SetCursor(HLCD_u8_Line_1,0);
	HLCD_u8WriteString("Enter Password");
	HLCD_u8SetCursor(HLCD_u8_Line_2,0);
	while(Local_u8Tries != 0xFF){
	HKPD_u8GetKey(&Local_u8KeyValue);
	if(Local_u8KeyValue=='='){
		/*Check if password is correct*/
		if(Local_u16Pass==Copy_u16Pass){
			HLCD_u8ClrLCD();
			*Copy_pu8LoginState=LoginSucceed;
			break;
		}
		else if((Local_u16Pass!=Copy_u16Pass)&&(Local_u8Tries<=2)){
			Local_u8Tries++;
			Local_u16Pass=0;
			HLCD_u8ClrLCD();
			HLCD_u8SetCursor(HLCD_u8_Line_1,0);
			HLCD_u8WriteString("Not Correct");
			_delay_ms(2000);
			HLCD_u8SetCursor(HLCD_u8_Line_1,0);
			HLCD_u8WriteString("Enter Password");
			HLCD_u8SetCursor(HLCD_u8_Line_2,0);
		}
		else{
			HLCD_u8ClrLCD();
			HLCD_u8SetCursor(HLCD_u8_Line_1,0);
			HLCD_u8WriteString("Login Failed");
			Local_u8Tries=0xFF;
			*Copy_pu8LoginState=LoginFailed;
		}
	}
	if((Local_u8KeyValue<=48+9)&&(Local_u8KeyValue>=48)&&(Local_u8Tries != 0xFF)){
				HLCD_u8WriteChar('*');
				Local_u16Pass=Local_u16Pass+(Local_u8KeyValue-48)*Local_u16Digit;
				if(Local_u16Digit>1){
				Local_u16Digit=Local_u16Digit/10;
				}
				else{
					Local_u16Digit=Local_u16DigitPlace;
				}
	}
	}
	HLCD_u8ClrLCD();
	return Local_u8ErorrState;
}

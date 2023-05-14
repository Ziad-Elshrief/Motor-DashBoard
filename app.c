#include "std_types.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

#include "MDIO_Interface.h"
#include "HDCM_Interface.h"
#include "HLCD_interface.h"
#include "HKPD_Interface.h"
#include "HSRV_Interface.h"

u8 App_u8GetAngle(void);

#define LoginFailed 		0
#define LoginSucceed		1

int main(void){
	MDIO_u8Init();
	HLCD_u8Init();
	u8 Local_u8LoginState;
	u8 Local_u8keyValue;
	u8 Local_u8ServoAngle;
	while(1){
		Local_u8keyValue=HKPD_u8_NO_KEY_PRESSED;
		HLCD_u8SetCursor(HLCD_u8_Line_1,0);
		HLCD_u8WriteString("Welcome to Motor");
		HLCD_u8SetCursor(HLCD_u8_Line_2,0);
		HLCD_u8WriteString("Dash Board");
		_delay_ms(2000);
		HLCD_u8ClrLCD();
		LoginSystem(1111,&Local_u8LoginState);
		switch(Local_u8LoginState){
		case LoginSucceed :
			while(Local_u8keyValue != '2'){
				HLCD_u8ClrLCD();
				HLCD_u8SetCursor(HLCD_u8_Line_1,0);
				HLCD_u8WriteString("1-DC");
				HLCD_u8SetCursor(HLCD_u8_Line_1,7);
				HLCD_u8WriteString("2-SERVO");
				HLCD_u8SetCursor(HLCD_u8_Line_2,0);
				HLCD_u8WriteString("3-Exit");
				HKPD_u8GetKey(&Local_u8keyValue);
				_delay_ms(100);
				if(Local_u8keyValue=='1'){
					/*DC Motor Options*/
					HLCD_u8ClrLCD();
					HLCD_u8SetCursor(HLCD_u8_Line_1,0);
					HLCD_u8WriteString("1-CW   2-CCW");
					HLCD_u8SetCursor(HLCD_u8_Line_2,0);
					HLCD_u8WriteString("3-Stop 4-Exit");
					_delay_ms(100);
					while(Local_u8keyValue != '4'){
						HKPD_u8GetKey(&Local_u8keyValue);
						switch(Local_u8keyValue-48){
						case 1:
							HDCM_u8CW();
							break;
						case 2:
							HDCM_u8CCW();
							break;
						case 3:
							HDCM_u8StopMotor();
							break;
						case 4:
							HDCM_u8StopMotor();
							break;
						}
					}
				}
				else if(Local_u8keyValue=='2'){
					/*SERVO Motor Options*/
					HLCD_u8ClrLCD();
					HLCD_u8SetCursor(HLCD_u8_Line_1,0);
					HLCD_u8WriteString("1-Set Angle");
					HLCD_u8SetCursor(HLCD_u8_Line_2,0);
					HLCD_u8WriteString("2-Exit");
					_delay_ms(100);
					Local_u8keyValue=HKPD_u8_NO_KEY_PRESSED;
					while(Local_u8keyValue == HKPD_u8_NO_KEY_PRESSED){
					HKPD_u8GetKey(&Local_u8keyValue);
					switch(Local_u8keyValue-48){
					case 1:
						HLCD_u8ClrLCD();
						HLCD_u8SetCursor(HLCD_u8_Line_1,0);
						HLCD_u8WriteString("Enter Angle: ");
						HLCD_u8SetCursor(HLCD_u8_Line_2,0);
						_delay_ms(100);
						Local_u8ServoAngle =App_u8GetAngle();
						if(Local_u8ServoAngle <=180){
						HSRV_voidSetAngle(Local_u8ServoAngle);
						}
						break;
					case 2:
						break;
					}
					}

				}
				else if(Local_u8keyValue=='3'){
					break;
				}
				else{
					_delay_ms(10);
				}
			}
			break;
		case LoginFailed:
			/*Turn on LED And Buzzer*/
			MDIO_u8SetPinValue(MDIO_u8_PORTB,MDIO_u8_PIN_7,MDIO_u8_HIGH);
			_delay_ms(3000);
			MDIO_u8SetPinValue(MDIO_u8_PORTB,MDIO_u8_PIN_7,MDIO_u8_LOW);
		}
	}

	return 0;
}



u8 App_u8GetAngle(void){
		u16 Local_u16Num=0;
		u8 Local_u8KeyValue;
		u8 Local_u8DigitPlace=100;
		u8 Local_u8Digit=0;
		u8 Local_u8Angle;

		while(Local_u8KeyValue != '='){
		HKPD_u8GetKey(&Local_u8KeyValue);
		if( (Local_u8KeyValue>= 48 ) && (Local_u8KeyValue<= 48+9) ){

			HLCD_u8WriteChar(Local_u8KeyValue);
			Local_u8Digit++;
			Local_u16Num= Local_u16Num + ( (Local_u8KeyValue-48) * Local_u8DigitPlace);
			Local_u8DigitPlace /= 10;
		}
		}
		switch(Local_u8Digit){
		case 3:
			Local_u8Angle=Local_u16Num;
			break;
		case 2:
			Local_u8Angle=Local_u16Num/10;
			break;
		case 1:
			Local_u8Angle = Local_u16Num/100;
			break;
		default:
			Local_u8Angle=0;
		}
		return Local_u8Angle;
}

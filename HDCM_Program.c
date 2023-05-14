/*LIB Layer*/
#include "std_types.h"

/*MCAL*/
#include "MDIO_Interface.h"

/*HAL*/
#include "HDCM_Interface.h"
#include "HDCM_Config.h"

/*Function to spin motor CW */
u8 HDCM_u8CW(void){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CCW_DIR_PIN,MDIO_u8_LOW);
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CW_DIR_PIN,MDIO_u8_HIGH);
	return Local_u8ErrorState;
}

/*Function to spin motor CCW */
u8 HDCM_u8CCW(void){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CW_DIR_PIN,MDIO_u8_LOW);
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CCW_DIR_PIN,MDIO_u8_HIGH);
	return Local_u8ErrorState;
}

/*Function to stop motor */
u8 HDCM_u8StopMotor(void){
	u8 Local_u8ErrorState=STD_TYPES_OK;
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CW_DIR_PIN,MDIO_u8_LOW);
	MDIO_u8SetPinValue(MOTOR_PORT,Motor_CCW_DIR_PIN,MDIO_u8_LOW);
	return Local_u8ErrorState;
}



#ifndef HAL_DC_MOTOR_H_
#define HAL_DC_MOTOR_H_

#include "../MCAL/PWM.h"
#include "../ServiceLayer/PLATFORM_TYPES.h"
#include "../MCAL/DIO.h"

typedef enum
{
	STOP,
	FORWARD,
	REVERSE,
	LEFT,
	RIGHT

}JoyStick_State_t;

#define MOTOR_DRV_PWM		PB3

#define MOTOR_DRV_A			PB4
#define MOTOR_DRV_A_DDR		DDRB
#define MOTOR_DRV_A_PORT	PORTB

#define MOTOR_DRV_B			PB5
#define MOTOR_DRV_B_DDR		DDRB
#define MOTOR_DRV_B_PORT	PORTB

#define MOTOR_DRV_C			PB6
#define MOTOR_DRV_C_DDR		DDRB
#define MOTOR_DRV_C_PORT	PORTB

#define MOTOR_DRV_D			PB7
#define MOTOR_DRV_D_DDR		DDRB
#define MOTOR_DRV_D_PORT	PORTB

void DC_Motor_Drive_Init(void);
void DC_Motor_Drive_OUT(JoyStick_State_t State,  uint8 Speed);


#endif /* HAL_DC_MOTOR_H_ */



#include "ULTRASONIC.h"
#include "../ServiceLayer/PLATFORM_TYPES.h"
#include "../MCAL/DIO.h"
#include "../MCAL/TIMER2.h"
#include <util/delay.h>

void UltraSonic_init(UltraSonicID_t UltraSonicID)
{

	switch (UltraSonicID)
	{

	case ULTRASONIC_1:
		SET_BIT(ULTRASONIC_TRIG1_DDR,ULTRASONIC_TRIG1_PIN);
		CLEAR_BIT(ULTRASONIC_ECHO1_DDR,ULTRASONIC_ECHO1_PIN);
		break;

	case ULTRASONIC_2:
		SET_BIT(ULTRASONIC_TRIG2_DDR,ULTRASONIC_TRIG2_PIN);
		CLEAR_BIT(ULTRASONIC_ECHO2_DDR,ULTRASONIC_ECHO2_PIN);
		break;

	default:
		/* Do Nothing */
		break;
	}

	Timer2_init();

}

uint16 UltraSonic_read(UltraSonicID_t UltraSonicID)
{
	double Time=0;
	uint16 Distance=0;

	switch (UltraSonicID)
	{
	/* UltraSonic 1 Code */
	case ULTRASONIC_1:
		CLEAR_BIT(ULTRASONIC_TRIG1_PORT,ULTRASONIC_TRIG1_PIN);
		_delay_ms(5);
		SET_BIT(ULTRASONIC_TRIG1_PORT,ULTRASONIC_TRIG1_PIN);
		_delay_us(10);
		CLEAR_BIT(ULTRASONIC_TRIG1_PORT,ULTRASONIC_TRIG1_PIN);

		while(BIT_CLEARED(ULTRASONIC_ECHO1_PORT,ULTRASONIC_ECHO1_PIN));

		Timer2_start();

		while( ( BIT_SET(ULTRASONIC_ECHO1_PORT,ULTRASONIC_ECHO1_PIN))&&(Timer2_reading() <250) );

		break;

		/* UltraSonic 2 Code */

	case ULTRASONIC_2:
		CLEAR_BIT(ULTRASONIC_TRIG2_PORT,ULTRASONIC_TRIG2_PIN);
		_delay_ms(5);
		SET_BIT(ULTRASONIC_TRIG2_PORT,ULTRASONIC_TRIG2_PIN);
		_delay_us(10);
		CLEAR_BIT(ULTRASONIC_TRIG2_PORT,ULTRASONIC_TRIG2_PIN);

		while(BIT_CLEARED(ULTRASONIC_ECHO2_PORT,ULTRASONIC_ECHO2_PIN));

		Timer2_start();

		while( ( BIT_SET(ULTRASONIC_ECHO2_PORT,ULTRASONIC_ECHO2_PIN))&&(Timer2_reading() <250) );

		break;
	default:
		/* Do Nothing */
		break;
	}


	Timer2_stop();

	Time=Timer2_reading();
#if DISTANCE == CM
	Time*=(0.017*128);

#elif DISTANCE == M
	Time*=(0.00017*128);
#endif
	Distance=(uint16)Time;
	Timer2_clear();
	return Distance;

}



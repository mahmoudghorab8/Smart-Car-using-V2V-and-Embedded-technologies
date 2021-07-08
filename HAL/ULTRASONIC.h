

#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "../ServiceLayer/PLATFORM_TYPES.h"

#define DISTANCE (CM)

typedef enum
{
	ULTRASONIC_1 = 1,
	ULTRASONIC_2

}UltraSonicID_t;



#define ULTRASONIC_TRIG1_DDR  	(DDRD)
#define ULTRASONIC_TRIG1_PIN	 (PD2)
#define ULTRASONIC_TRIG1_PORT  (PORTD)

#define ULTRASONIC_ECHO1_DDR  (DDRD)
#define ULTRASONIC_ECHO1_PIN	 (PD3)
#define ULTRASONIC_ECHO1_PORT  (PIND)


#define ULTRASONIC_TRIG2_DDR  (DDRD)
#define ULTRASONIC_TRIG2_PIN	 (PD4)
#define ULTRASONIC_TRIG2_PORT  (PORTD)

#define ULTRASONIC_ECHO2_DDR  (DDRD)
#define ULTRASONIC_ECHO2_PIN	 (PD5)
#define ULTRASONIC_ECHO2_PORT  (PIND)

extern void UltraSonic_init(UltraSonicID_t UltraSonicID);
extern uint16 UltraSonic_read(UltraSonicID_t UltraSonicID);


#endif /* HAL_ULTRASONIC_H_ */

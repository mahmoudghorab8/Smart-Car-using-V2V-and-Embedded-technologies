

#ifndef MCAL_TIMER0_H_
#define MCAL_TIMER0_H_

#include "../ServiceLayer/PLATFORM_TYPES.h"
#include <avr/io.h>

extern void  Timer0_init(void);
extern void  Timer0_start(void);
extern void  Timer0_stop(void);
extern void  Timer0_clear(void);
extern uint8 Timer0_reading(void);


#endif /* MCAL_TIMER0_H_ */

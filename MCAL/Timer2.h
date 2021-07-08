

#ifndef TIMER2_H_
#define TIMER2_H_

#include "../ServiceLayer/PLATFORM_TYPES.h"
#include <avr/io.h>

extern void  Timer2_init(void);
extern void  Timer2_start(void);
extern void  Timer2_stop(void);
extern void  Timer2_clear(void);
extern uint8 Timer2_reading(void);


#endif /* TIMER2_H_ */

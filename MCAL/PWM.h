

#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

extern void PWM_init(void);
extern void PWM_Duty_Cycle(unsigned char Duty_Cycle);

#endif /* PWM_H_ */

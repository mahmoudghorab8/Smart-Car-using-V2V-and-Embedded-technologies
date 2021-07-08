
#include "PWM.h"

void PWM_init(void)
 {
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS02);
	TCNT0=0;
	OCR0=0;
	DDRB |=(1<<PB3);


 }


void PWM_Duty_Cycle(unsigned char Duty_Cycle)
 {
	OCR0=Duty_Cycle;

 }

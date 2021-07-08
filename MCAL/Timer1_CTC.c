

#include "Timer1_CTC.h"
#include <avr/interrupt.h>

static void (*PTR)(void)= NULL ;

void  Timer1_init(void)
{
	TCCR1A = (1<<FOC1A)|(1<<FOC1B);
	TCCR1B = (1<<WGM12);
	OCR1A = 0;
	OCR1B = 0;
	ICR1 = 0;
	TIMSK =(1<<OCIE1A);
	SREG|=(1<<7);
}


void  Timer1_start(void)
{
	/* CTC  -> Clear Timer1 on Compare Match */
	OCR1A = (TimerPeriod /8ul);

	/* 8MHZ/64 -> 1_Tic - 8us  */
	TCCR1B = (1<<CS11)|(1<<CS10)|(1<<WGM12);

}

void  Timer1_stop(void)
{
	TCCR1B = (1<<WGM12);
}

void  Timer1_clear(void)
{
	TCNT1=0;
}

uint16 Timer1_reading(void)
{
	return TCNT1;
}

void Timer1_Set_Cbk(void (*Cbk)(void))
{
	PTR = Cbk;
}

ISR(TIMER1_COMPA_vect)
{
	/* Loading the Timer Register with the desired Value _1ms */
	if(PTR != NULL )
	{
		PTR();
	}
}

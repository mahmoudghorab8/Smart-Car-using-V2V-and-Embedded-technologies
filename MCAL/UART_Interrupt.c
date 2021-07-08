

#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART_Interrupt.h"

volatile static char Data [UART_MAX_BUFFER_SIZE]= {0};
volatile static signed int Length = 0;

void Uart_Init(long baudrate)
{
	short Result =0;

	UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);

	SREG |=(1<<7);

	Result = ( ((F_CPU)/(16*baudrate))-1);
	UBRRL = (unsigned char)Result;

	UBRRH = ((unsigned char)(Result>>8))&(0x7F);
}

void Uart_Send_Byte(char Data)
{
	while(!   (UCSRA &(1<<UDRE)  )    ); // Waiting
	UDR = Data;
}
void Uart_Send_String(char * String)
{
	int i =0;

	while(String[i] != '\0')
	{
		Uart_Send_Byte(String[i]);
		i++;
	}
	Uart_Send_Byte(String[i]);

}

char Uart_Rec_Byte(void)
{
	char Result =0;

	if(Length != 0)
	{
		Result = Data[--Length];
	}
	else
	{
		Result = 0;
	}

	return Result;
}

void Uart_Rec_String(char * String)
{
	int i=0;

	int Temp_Length = Length;


	for(i=0; i<Temp_Length;i++)
	{
		String[i] = Uart_Rec_Byte();
	}


}

ISR(USART_RXC_vect)
{
	if(Length < UART_MAX_BUFFER_SIZE)
	{
		Data[Length] = UDR;
		Length++;
	}
	else
	{
		Data[Length-1] = UDR;
	}

}

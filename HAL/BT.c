
#include "BT.h"

void BT_Init(long baudrate)
{
	Uart_Init(baudrate);
}
void BT_Send_Byte(char Data)
{
	Uart_Send_Byte(Data);
}
void BT_Send_String(char * String)
{
	Uart_Send_String(String);
}
char BT_Rec_Byte(void)
{
	return Uart_Rec_Byte();
}
void BT_Rec_String(char * String)
{
	Uart_Rec_String(String);
}


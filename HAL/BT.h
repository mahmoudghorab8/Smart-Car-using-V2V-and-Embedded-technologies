

#ifndef HAL_BT_H_
#define HAL_BT_H_
#include "../MCAL/UART_Interrupt.h"

void BT_Init(long baudrate);
void BT_Send_Byte(char Data);
void BT_Send_String(char * String);
char BT_Rec_Byte(void);
void BT_Rec_String(char * String);


#endif /* HAL_BT_H_ */

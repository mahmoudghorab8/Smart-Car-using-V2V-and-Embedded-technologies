

#ifndef UART_INTERRUPT_H_
#define UART_INTERRUPT_H_

#define UART_MAX_BUFFER_SIZE	20

void Uart_Init(long baudrate);
void Uart_Send_Byte(char Data);
void Uart_Send_String(char * String);
char Uart_Rec_Byte(void);
void Uart_Rec_String(char * String);


#endif /* UART_INTERRUPT_H_ */

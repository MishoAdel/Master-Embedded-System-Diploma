/*
 * usart.h
 *
 * Created: 11/27/2023 3:04:53 PM
 *  Author: mesho
 */ 


#ifndef USART_H_
#define USART_H_

void usart_init(void);
void usart_send_byte(unsigned char x);
unsigned char usart_recive_byte(void);
void usart_send_num(unsigned int num);
unsigned int usart_recive_num(void);
void usart_send_string( char* str);
void usart_recieve_string( char* str);




#endif /* USART_H_ */
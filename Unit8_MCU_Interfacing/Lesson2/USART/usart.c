/*
 * usart.c
 *
 * Created: 11/27/2023 3:04:35 PM
 *  Author: mesho
 */ 

#include "usart.h"
#include "avr/io.h"
#include "stdio.h"
#include "string.h"

void usart_init(void){
	//Baud Rate
	UBRRL=51;
	
	//Set Mode
	UCSRA&=~(1<<1);
	UCSRC&=~(1<<6);//Async
	
	UCSRC &= ~(0b111<<3); //No parity and one stop bit
	
	UCSRB&=~(1<<2);
	UCSRC|=0b11<<1; //8-bit data
	
	//Enable
	UCSRB |=(1<<3);
	UCSRB |=(1<<4);
}
void usart_send_byte(unsigned char x){
	while(!((UCSRA>>5)&1));
	UDR= x;
}



unsigned char usart_recive_byte(void){
	while(!((UCSRA>>7)&1));
	return UDR;
}

void usart_send_num(unsigned int num){
	unsigned char *p = (unsigned char *)&num;
	usart_send_byte(p[0]);
	usart_send_byte(p[1]);
	usart_send_byte(p[2]);
	usart_send_byte(p[3]);
}


unsigned int usart_recive_num(void){
	unsigned int num;
	unsigned char* p = (unsigned char *)&num;
	p[0] = usart_recive_byte();
	p[1] = usart_recive_byte();
	p[2] = usart_recive_byte();
	p[3] = usart_recive_byte();
	return num;
	
}

void usart_send_string(char* str)
{
	unsigned char i;
	for(i=0;i<strlen(str);i++)
		usart_send_byte(str[i]);
	usart_send_byte('#');
}

void usart_recieve_string(char* str){
	unsigned char i=0;
	do{
		str[i]=usart_recive_byte();
		i++	;	
	}while(str[i-1]!='#');
	str[i]='\0';
}
#include "uart.h"

#define UART0 *((volatile unsigned int* const )((unsigned int*)0x101f1000))

void UART0_String (unsigned char* str){
	while(*str !='\0'){
		UART0=(unsigned int)(*str);
		str++;
	}
}
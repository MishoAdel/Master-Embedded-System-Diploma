#include "uart.h"
unsigned char string[100]="Learn-In-Depth:<Michel>";

void main(void){
	UART0_String(string);
}
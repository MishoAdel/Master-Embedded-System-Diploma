
#include "stdint.h"
#include <util/delay.h>


#define PORTD_BASE 0x20
#define PORTA *(volatile uint8_t *)(PORTD_BASE + 0x1B)
#define DDRA *(volatile uint8_t *)(PORTD_BASE + 0x1A)


int main(void)
{
	DDRA = 0b11111111;
	int i;
    while (1) 
    {
		for(i=0;i<8;i++)
		{
			PORTA |= (1<<i);
			_delay_ms(500);
		}
		for(i=7;i>=0;i--)
		{
			PORTA &= ~(1<<i);
			_delay_ms(500);
		}
    }
}
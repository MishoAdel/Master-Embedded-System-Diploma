
#include "stdint.h"
#include <util/delay.h>


#define PORT_BASE 0x20
#define PORTA *(volatile uint8_t *)(PORT_BASE + 0x1B)
#define DDRA *(volatile uint8_t *)(PORT_BASE + 0x1A)
#define PORTC *(volatile uint8_t *)(PORT_BASE + 0x15)
#define DDRC *(volatile uint8_t *)(PORT_BASE + 0x14)
#define PINC *(volatile uint8_t *)(PORT_BASE + 0x13)

int main(void)
{
	DDRC &= ~(1<<0) ;
	PORTC=0;
	DDRA = 0b11111111;
	int i;
    while (1)
    {
	    if((PINC & 1)==0)
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
}
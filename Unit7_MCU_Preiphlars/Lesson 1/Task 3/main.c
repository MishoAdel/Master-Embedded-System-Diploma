
#include "stdint.h"
#include <util/delay.h>


#define PORTD_BASE 0x20
#define PORTD *(volatile uint8_t *)(PORTD_BASE + 0x12)
#define DDRD *(volatile uint8_t *)(PORTD_BASE + 0x11)


int main(void)
{
	DDRD |= (0b1111<<4);
    while (1) 
    {
		PORTD |= (1<<5);
		_delay_ms(1000);
		PORTD &= ~(1<<5);
		PORTD |= (1<<6);
		_delay_ms(1000);
		PORTD &= ~(1<<6);
		PORTD |= (1<<7);
		_delay_ms(1000);
		PORTD &= ~(1<<7);
		PORTD |= (1<<4);
		_delay_ms(1000);
		PORTD &= ~(1<<4);
    }
}
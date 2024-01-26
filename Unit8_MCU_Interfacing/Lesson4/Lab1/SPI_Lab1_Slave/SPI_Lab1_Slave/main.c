/*
 * main.c
 *
 * Created: 1/23/2024 11:31:58 PM
 *  Author: mesho
 */ 
#define F_CPU 1000000UL  
#include <avr/io.h>
#include "util/delay.h"

void SPI_Slave_Init(){
	DDRB &= ~(1<<4)|(1<<5)|(1<<7);
	DDRB |= (1<<6);
	SPCR |= (1<<SPE);
	}

unsigned char SPI_Slave_Recieve(unsigned char Sdata){
	SPDR=Sdata;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
	unsigned char i;
	SPI_Slave_Init();
	DDRA=0xFF;
   for(i=255;i>0;i--){
	   _delay_ms(1000);
	   PORTA=SPI_Slave_Recieve(i);
   }
   return 0;
}
/*
 * SPI.c
 *
 * Created: 1/27/2024 12:11:25 AM
 *  Author: mesho
 */ 

#include "SPI.h"

void SPI_init(void){
	#ifdef SPI_MODE_MASTER
		SPCR|=1<<MSTR;
		SPCR &=~(1<<CPOL);
		DDRB |= (1<<7)|(1<<5)|(1<<4);
		DDRB &=~(1<<6);
	#endif
	
	#ifdef SPI_MODE_SLAVE
		SPCR &=~(1<<MSTR);
		DDRB &=~((1<<7)|(1<<5)|(1<<4));
		DDRB |=(1<<6);
	#endif
	
	SPCR|=1<<SPE;
}

unsigned char SPI_send_receive(unsigned char data){
	SPDR=data;
	while(!((SPSR>>SPIF)&1));
	return SPDR;
}
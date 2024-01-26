/*
 * main.c
 *
 * Created: 1/24/2024 12:05:32 AM
 *  Author: mesho
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void SPI_Master_Init(){
	DDRB |= (1<<4)|(1<<5)|(1<<7);
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

unsigned char SPI_Master_Send(unsigned char Sdata){
	SPDR=Sdata;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void Segment_CTRL(unsigned char cmd, unsigned char data){
	PORTB &=~(1<<4);
	SPDR=cmd;
	while(!(SPSR & (1<<SPIF)));
	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
	PORTB |=(1<<4);
}

int main(void)
{
	SPI_Master_Init();
	Segment_CTRL(0x09,0xFF);
	Segment_CTRL(0x0B,0x07);
	Segment_CTRL(0x0A,0x0F);
	Segment_CTRL(0x0C,0x01);
	unsigned char digitnum;
	unsigned char counter=0;
    while(1)
    {
		for(digitnum=1;digitnum<9;digitnum++){
			Segment_CTRL(digitnum,counter++);
			_delay_ms(1000);
		}
    }
}
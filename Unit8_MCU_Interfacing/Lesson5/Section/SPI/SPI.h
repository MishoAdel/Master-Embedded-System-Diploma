/*
 * SPI.h
 *
 * Created: 1/27/2024 12:11:40 AM
 *  Author: mesho
 */ 


#ifndef SPI_H_
#define SPI_H_

#define F_CPU 8000000UL 

#include "avr/io.h"
#include "util/delay.h"
#define SPI_MODE_MASTER
//#define SPI_MODE_SLAVE



void SPI_init(void);
unsigned char SPI_send_receive(unsigned char data);


#endif /* SPI_H_ */
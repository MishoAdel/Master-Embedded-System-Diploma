/*
 * stm32f013c6_SPI_driver.h
 *
 *  Created on: Jan 25, 2024
 *      Author: mesho
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------

#include <stm32f103c6_RCC_driver.h>
#include "stm32f103xx.h"
#include "stm32f103c6_GPIO_driver.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------


struct S_IRQ_SRC{
	uint8_t TXE:1; 		//Transmitter buffer empty interrupt
	uint8_t RXNE:1;		//Receiver buffer not empty interrupt
	uint8_t ERRI:1;		//Error interrupt
	uint8_t Reserved:5;
};


enum Polling_mechanism_SPI{
	Polling_enable,
	Polling_disable
};

typedef struct{

	uint16_t Device_Mode;									//This parameter specifies mode master or slave
															//you can find the value of this parameter @ref SPI_Mode_define
	uint16_t Communication_Mode;							//This parameter specifies communication mode bidirctional,simplex,duplex
															//you can find the value of this parameter @ref SPI_Comm_Mode_define
	uint16_t DataSize;										//This parameter specifies data size 16 or 8
															//you can find the value of this parameter @ref SPI_Data_Size_define
	uint16_t DataFrame;										//This parameter specifies  to start with either LSB or MSB
															//you can find the value of this parameter @ref SPI_Data_Frame_define
	uint16_t CLK_Polarity;									//This parameter specifies  clock idle polarity high or low
															//you can find the value of this parameter @ref SPI_CLK_Polarity_define
	uint16_t CLK_Phase;										//This parameter specifies capturing of first or second edge
															//you can find the value of this parameter @ref SPI_CLK_Phase_define
	uint16_t NSS;											//This parameter specifies either NSS signal in controlled by software or hardware
															//you can find the value of this parameter @ref SPI_NSS_define
	uint16_t BaudRate_Prescaler;							//This parameter specifies the prescaler for clock
															// the clock for SPI1 is clk of APB2 and for SPI2 is ABP1
															//you can find the value of this parameter @ref SPI_Baud_Rate_Prescaler_define
	uint16_t IRQ_Enable;									//This parameter specifies interrupts to enable
															//you can find the value of this parameter @ref SPI_IRQ_Enable
	void (*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);		//This is the pointer to the call back function
}SPI_Config;


//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref SPI_Mode_define
#define SPI_Mode_Slave				((uint32_t)0x0)
#define SPI_Mode_Master				((uint32_t)(0x1<<2))

//@ref SPI_Comm_Mode_define
#define SPI_2_lines										((uint32_t) 0x0)
#define SPI_2_lines_RX_Only								((uint32_t)(0x1<<10))
#define SPI_1_line_RX_Only								((uint32_t)(0x1<<15))
#define SPI_1_line_TX_Only								((uint32_t)(0b11<<14))

//@ref SPI_Data_Size_define
#define SPI_Data_Size_8									((uint32_t)0x0)
#define SPI_Data_Size_16								((uint32_t)(0x1<<11))

//@ref SPI_Data_Frame_define
#define SPI_strt_MSB									((uint32_t)0x0)
#define SPI_strt_LSB									((uint32_t)(0x1<<7))

//@ref SPI_CLK_Polarity_define
#define SPI_CLK_Polarity_High							((uint32_t)(0x1<<1))
#define SPI_CLK_Polarity_Low							((uint32_t)0x0)

//@ref SPI_CLK_Phase_define
#define SPI_CLK_Phase_1st_edge							((uint32_t)0x0))
#define SPI_CLK_Phase_2nd_edge							((uint32_t)0x1<<0)

//@ref SPI_NSS_define
#define SPI_NSS_Hard_Slave								((uint32_t)0x0)
#define SPI_NSS_Hard_Master_SS_Output_Enable			((uint32_t)(0x1<<2))
#define SPI_NSS_Hard_Master_SS_Output_Disable			~((uint32_t)(0x1<<2))

#define SPI_NSS_Soft_Set								((uint32_t)(0x1<<9))
#define SPI_NSS_Soft_Reset								((uint32_t)0b11<<8)

//@ref SPI_Baud_Rate_Prescaler_define
#define SPI_Baud_Rate_Scale_2							((uint32_t)(0b000<<3))
#define SPI_Baud_Rate_Scale_4							((uint32_t)(0b001<<3))
#define SPI_Baud_Rate_Scale_8							((uint32_t)(0b010<<3))
#define SPI_Baud_Rate_Scale_16							((uint32_t)(0b011<<3))
#define SPI_Baud_Rate_Scale_32							((uint32_t)(0b100<<3))
#define SPI_Baud_Rate_Scale_64							((uint32_t)(0b101<<3))
#define SPI_Baud_Rate_Scale_128							((uint32_t)(0b110<<3))
#define SPI_Baud_Rate_Scale_256							((uint32_t)(0b111<<3))

//@ref SPI_IRQ_Enable
#define SPI_IRQ_Enable_None								((uint32_t)0x0)
#define SPI_IRQ_Enable_TXEIE							((uint32_t)(0x1<<7))
#define SPI_IRQ_Enable_RXNEIE							((uint32_t)(0x1<<6))
#define SPI_IRQ_Enable_ERRIE							((uint32_t)(0x1<<5))


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_SPI_Init(SPI_TypeDef* SPIx,SPI_Config* My_SPI_Config);
void MCAL_SPI_Deinit(SPI_TypeDef* SPIx);

void MCAL_SPI_Set_GPIO_Pins(SPI_TypeDef* SPIx);

void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State);
void MCAL_SPI_Recieve_Data(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State);
void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State);


#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */

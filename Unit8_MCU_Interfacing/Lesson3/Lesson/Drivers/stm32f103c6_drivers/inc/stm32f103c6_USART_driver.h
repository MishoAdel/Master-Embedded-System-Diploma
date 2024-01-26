/*
 * stm32f103c6_USART_driver.h
 *
 *  Created on: Nov 28, 2023
 *      Author: mesho
 */

#ifndef INC_STM32F103C6_USART_DRIVER_H_
#define INC_STM32F103C6_USART_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "stm32f103xx.h"
#include "stm32f10c6_RCC_driver.h"
#include "stm32f103c6_GPIO_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

//enum USART_IRQ_Event{
//	USART_IRQ_TXE,
//	USART_IRQ_TC,
//	USART_IRQ_RXNE,
//	USART_IRQ_OE,
//	USART_IRQ_PE
//};

enum Polling_mechanism{
	enable,
	disable
};

typedef struct{

	uint32_t USART_Mode;									//This specifies the transmitter and receiver mode
															//you can find the value of this parameter @ref USART_Mode_define
	uint32_t BaudRate;										//This specifies the baud rate
															//you can find the value of this parameter @ref USART_BaudRate_define
	uint32_t Payload_length;								//This specifies the payload length
															//you can find the value of this parameter @ref USART_payload_length_define
	uint32_t Parity;										//This specifies the parity
															//you can find the value of this parameter @ref USART_parity_define
	uint32_t Stopbits;										//This specifies the stop bits
															//you can find the value of this parameter @ref USART_stop_bits_define
	uint32_t HWFlowCTRL;									//This specifies the baud rate
															//you can find the value of this parameter @ref USART_HW_Flow_CTRL_define
	uint32_t IRQ_Enable;									//This specifies the baud rate
															//you can find the value of this parameter @ref USART_IRQ_Enable_define
	void (*P_IRQ_CallBack)(void);							//This is the pointer to the call back function
}USART_Config;

//There is 3 global in c file USARTx_config one for each USART
//Global USART_cofig
USART_Config USART1_Config;
USART_Config USART2_Config;
USART_Config USART3_Config;
//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref USART_Mode_define
#define USART_Mode_TX				((uint32_t)1<<3)
#define USART_Mode_RX				((uint32_t)1<<2)
#define USART_Mode_TX_RX			((uint32_t)(1<<3|1<<2))


//@ref USART_BaudRate_define
#define USART_BaudRate_2400			2400
#define USART_BaudRate_9600			9600
#define USART_BaudRate_19200		19200
#define USART_BaudRate_57600		57600
#define USART_BaudRate_115200		115200
#define USART_BaudRate_230400		230400
#define USART_BaudRate_460800		460800
#define USART_BaudRate_921600		921600
#define USART_BaudRate_921600		921600
#define USART_BaudRate_2250000		2250000
#define USART_BaudRate_4500000		4500000

//@ref USART_payload_length_define
#define USART_Payload_8bit			((uint32_t)0)
#define USART_Payload_9bit			((uint32_t)1>>12)

//@ref USART_parity_define
#define USART_No_Parity				((uint32_t)0)
#define USART_odd_Parity			((uint32_t)0b11<<9)
#define USART_even_Parity			((uint32_t)0b10<<9)

//@ref USART_stop_bits_define
#define USART_StopBit_1				((uint32_t)0)
#define USART_StopBit_half 			((uint32_t)0b01<<12)
#define USART_StopBit_2				((uint32_t)0b10<<12)
#define USART_StopBit_1_half 		((uint32_t)0b11<<12)

//@ref USART_HW_Flow_CTRL_define
#define USART_HWFlowCTRL_None		((uint32_t)0)
#define USART_HWFlowCTRL_CTS		((uint32_t)0b10<<8)
#define USART_HWFlowCTRL_RTS		((uint32_t)0b01<<8)
#define USART_HWFlowCTRL_CTS_RTS	((uint32_t)0b11<<8)

//@ref USART_IRQ_Enable_define
#define USART_IRQ_Enable_None		((uint32_t)0)
#define USART_IRQ_Enable_TXE		((uint32_t)1<<7) // Transmit data registry empty
#define USART_IRQ_Enable_TC			((uint32_t)1<<6) // Transmit complete
#define USART_IRQ_Enable_RXNE		((uint32_t)1<<5) // Received data ready to be read
#define USART_IRQ_Enable_PE			((uint32_t)1<<8) // Parity Error


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_USART_init(USART_Config* my_usart_config,USART_TypeDef* USARTx);
void MCAL_USART_deinit(USART_TypeDef* USARTx);

void MCAL_USART_GPIO_setpins(USART_TypeDef* USARTx);

void MCAL_USART_send_data(USART_TypeDef* USARTx,uint16_t* TX_Buffer,enum Polling_mechanism polling_en);
void MCAL_USART_recieve_data(USART_TypeDef* USARTx,uint16_t* RX_Buffer,enum Polling_mechanism polling_en);

void MCAL_USART_wait_TC(USART_TypeDef* USARTx);


#endif /* INC_STM32F103C6_USART_DRIVER_H_ */

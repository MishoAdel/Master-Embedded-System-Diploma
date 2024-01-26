/*
 * stm32f10c6_RCC_driver.h
 *
 *  Created on: Nov 28, 2023
 *      Author: mesho
 */

#ifndef INC_STM32F10C6_RCC_DRIVER_H_
#define INC_STM32F10C6_RCC_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103xx.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{

	uint32_t clock_source;		//This defines the source of the clock
								//you can find the value of this parameter @ref RCC_clock_source_define
	uint32_t AHB_prescaler;		//This defines the scaler for AHB clock
								//you can find the value of this parameter @ref RCC_AHB_prescaler_define
	uint32_t APB1_prescaler;		//This defines the scaler for APB1 clock
								//you can find the value of this parameter @ref RCC_APB1_prescaler_define
	uint32_t APB2_prescaler;		//This defines the scaler for APB2 clock
								//you can find the value of this parameter @ref RCC_APB2_prescaler-define
	uint32_t PLL_value;			//This defines if PLL works and it scale
								//You can find the value of this parameter @ref RCC_PLL_value_define
	uint32_t PLL_source;			//This defines PLL source
								//You can find the value of this parameter @ref RCC_PLL_source_define
	uint32_t clock_output;		//This defines the output clock
								//you can find the value of this parameter @ref RCC_clock_output_define
}RCC_clock_Config;


//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref RCC_clock_source_define
#define clock_source_HSI		((unint32_t)0) //predefined value
#define clock_source_HSE		((unint32_t)1)
#define clock_source_PLL		((unint32_t)2)

//@ref RCC_AHB_prescaler_define
#define AHB_prescaler_1			((unit32_t)0b0000<<4) //predefined value
#define AHB_prescaler_2			((unit32_t)0b1000<<4)
#define AHB_prescaler_4			((unit32_t)0b1001<<4)
#define AHB_prescaler_8			((unit32_t)0b1010<<4)
#define AHB_prescaler_16		((unit32_t)0b1011<<4)
#define AHB_prescaler_32		((unit32_t)0b1100<<4)
#define AHB_prescaler_64		((unit32_t)0b1101<<4)
#define AHB_prescaler_128		((unit32_t)0b1110<<4)
#define AHB_prescaler_256		((unit32_t)0b1111<<4)

//@ref RCC_APB1_prescaler_define
#define APB1_prescaler_1		((unit32_t)0b000<<8) //predefined value
#define APB1_prescaler_2		((unit32_t)0b100<<8)
#define APB1_prescaler_4		((unit32_t)0b101<<8)
#define APB1_prescaler_8		((unit32_t)0b110<<8)
#define APB1_prescaler_16		((unit32_t)0b111<<8)

//@ref RCC_APB2_prescaler_define
#define APB2_prescaler_1		((unit32_t)0b000<<11) //predefined value
#define APB2_prescaler_2		((unit32_t)0b100<<11)
#define APB2_prescaler_4		((unit32_t)0b101<<11)
#define APB2_prescaler_8		((unit32_t)0b110<<11)
#define APB2_prescaler_16		((unit32_t)0b111<<11)

//@ref RCC_PLL_value_define
#define PLL_NULL				((unit32_t)0b0000) //predefined value
#define PLL_prescaler_2			((unit32_t)0b0000<<18)
#define PLL_prescaler_3			((unit32_t)0b0001<<18)
#define PLL_prescaler_4			((unit32_t)0b0010<<18)
#define PLL_prescaler_5			((unit32_t)0b0011<<18)
#define PLL_prescaler_6			((unit32_t)0b0100<<18)
#define PLL_prescaler_7			((unit32_t)0b0101<<18)
#define PLL_prescaler_8			((unit32_t)0b0110<<18)
#define PLL_prescaler_9			((unit32_t)0b0111<<18)
#define PLL_prescaler_10		((unit32_t)0b1000<<18)
#define PLL_prescaler_11		((unit32_t)0b1001<<18)
#define PLL_prescaler_12		((unit32_t)0b1010<<18)
#define PLL_prescaler_13		((unit32_t)0b1011<<18)
#define PLL_prescaler_14		((unit32_t)0b1100<<18)
#define PLL_prescaler_15		((unit32_t)0b1101<<18)
#define PLL_prescaler_16		((unit32_t)0b1110<<18)

//@ref RCC_PLL_source_define
#define PLL_source_HSI			((uint32_t)0b00<<16)
#define PLL_source_HSI_2		((uint32_t)0b10<<16)
#define PLL_source_HSE			((uint32_t)0b01<<16)

//@ref RCC_clock_output_define
#define clock_out_none			((unit32_t)0b000<<24) //predefined value
#define clock_out_SYSCLK		((unit32_t)0b100<<24)
#define clock_out_HSI			((unit32_t)0b101<<24)
#define clock_out_HSE			((unit32_t)0b110<<24)
#define clock_out_PLL			((unit32_t)0b111<<24)


/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/



void MCAL_RCC_clock_update(RCC_clock_Config* clk_config);
//to do ADC and usb prescalers

uint32_t MCAL_RCC_get_system_clock();
uint32_t MCAL_RCC_get_AHB_clock();
uint32_t MCAL_RCC_get_APB1_clock();
uint32_t MCAL_RCC_get_APB2_clock();

//-----------------------------
// Clock Enable Macros
//-----------------------------



#define GPIOA_CLK_ENB	(RCC->APB2ENR)|=1<<2
#define GPIOB_CLK_ENB	(RCC->APB2ENR)|=1<<3
#define GPIOC_CLK_ENB	(RCC->APB2ENR)|=1<<4
#define GPIOD_CLK_ENB	(RCC->APB2ENR)|=1<<5
#define GPIOE_CLK_ENB	(RCC->APB2ENR)|=1<<6

#define AFIO_CLK_ENB	(RCC->APB2ENR)|=1<<0

#define USART1_CLK_ENB	(RCC->APB2ENR)|=1<<14
#define USART2_CLK_ENB	(RCC->APB1ENR)|=1<<17
#define USART3_CLK_ENB	(RCC->APB1ENR)|=1<<18


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripherals Reset Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#define USART1_RESET	(RCC->APB2RSTR)|=1<<14
#define USART2_RESET	(RCC->APB1RSTR)|=1<<17
#define USART3_RESET	(RCC->APB1RSTR)|=1<<18

//-----------------------------
// Genric  Macros
//-----------------------------
#define internal_clock ((uint32_t)8000000)
#define external_clock ((uint32_t)16000000)

#endif /* INC_STM32F10C6_RCC_DRIVER_H_ */

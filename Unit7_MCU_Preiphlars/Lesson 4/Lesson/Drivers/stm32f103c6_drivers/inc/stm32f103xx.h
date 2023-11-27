/*
 * stm32f103xx.h
 *
 *  Created on: Sep 17, 2023
 *      Author: mesho
 */

#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdint.h>



//-----------------------------
//Base addresses for Memories
//-----------------------------

#define SRAM_Base 						0x20000000UL
#define FLASH_Base 						0x08000000UL
#define PERIPHERALS_Base 				0x40000000UL
#define CORTEX_M3_PERIPHERALS_Base 		0xE0000000UL
#define PERIPHERALS_Base 				0x40000000UL
#define SYSTEM_MEMORy_Base 				0x1FFFF000UL



//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------


//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

//RCC
#define RCC_BASE 		0x40021000UL


//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//GPIO
// A&B fully included
#define GPIOA_BASE 		0x40010800UL
#define GPIOB_BASE 		0x40010c00UL
// C&D partially included
#define GPIOC_BASE 		0x40011000UL
#define GPIOD_BASE 		0x40011400UL
//E not included
#define GPIOE_BASE 		0x40011800UL

//EXTI
#define EXTI_BASE		0x40010400UL

//AFIO
#define AFIO_BASE		0x40010000UL

//NVIC
//NVIC Registers
#define NVIC_BASE						(uint32_t)(0xE000E100UL)
#define NVIC_ISER0						(*(uint32_t *)(NVIC_BASE + 0x00))
#define NVIC_ISER1						(*(uint32_t *)(NVIC_BASE + 0x04))
#define NVIC_ISER2						(*(uint32_t *)(NVIC_BASE + 0x08))
#define NVIC_ISER3						(*(uint32_t *)(NVIC_BASE + 0x0C))
#define NVIC_ISER4						(*(uint32_t *)(NVIC_BASE + 0x10))
#define NVIC_ISER5						(*(uint32_t *)(NVIC_BASE + 0x14))
#define NVIC_ISER6						(*(uint32_t *)(NVIC_BASE + 0x18))
#define NVIC_ISER7						(*(uint32_t *)(NVIC_BASE + 0x1C))
#define NVIC_ICER0						(*(uint32_t *)(NVIC_BASE + 0x80))
#define NVIC_ICER1						(*(uint32_t *)(NVIC_BASE + 0x84))
#define NVIC_ICER2						(*(uint32_t *)(NVIC_BASE + 0x88))
#define NVIC_ICER3						(*(uint32_t *)(NVIC_BASE + 0x8C))
#define NVIC_ICER4						(*(uint32_t *)(NVIC_BASE + 0x90))
#define NVIC_ICER5						(*(uint32_t *)(NVIC_BASE + 0x94))
#define NVIC_ICER6						(*(uint32_t *)(NVIC_BASE + 0x98))
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t AFIO_EXTICR[4];
			 uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA			((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef *)GPIOE_BASE)

#define RCC 			((RCC_TypeDef *)RCC_BASE)

#define AFIO	 		((AFIO_TypeDef *)AFIO_BASE)

#define EXTI 			((EXTI_TypeDef *)EXTI_BASE)
//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA_CLK_ENB	(RCC->APB2ENR)|=1<<2
#define GPIOB_CLK_ENB	(RCC->APB2ENR)|=1<<3
#define GPIOC_CLK_ENB	(RCC->APB2ENR)|=1<<4
#define GPIOD_CLK_ENB	(RCC->APB2ENR)|=1<<5
#define GPIOE_CLK_ENB	(RCC->APB2ENR)|=1<<6

#define AFIO_CLK_ENB	(RCC->APB2ENR)|=1<<0

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*




#endif /* INC_STM32F103XX_H_ */

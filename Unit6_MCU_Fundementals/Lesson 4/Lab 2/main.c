/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stdint.h"

#define EXTI_BASE 0x40010400
#define EXTI_IMR *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR *(volatile uint32_t *)(EXTI_BASE + 0x014)

#define NVIC_ISER0 *(volatile uint32_t *)(0xE000E100)

#define AFIO_BASE 0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

#define BASE_RCC 0x40021000
#define RCC_APB2ENR	*(volatile uint32_t *) (BASE_RCC + 0x18)

#define PortA_BASE 0x40010800
#define GPIO_CRH	*(volatile uint32_t *) (PortA_BASE + 0x04)
#define GPIO_ODR	*(volatile uint32_t *) (PortA_BASE + 0x0C)
#define GPIOx_CRL	*(volatile uint32_t *) (PortA_BASE + 0x00)

int main(void)
{

	RCC_APB2ENR |= 1<<2 ;
	RCC_APB2ENR |= 1<<0 ;

	GPIOx_CRL |=(1<<2);
	GPIO_CRH &= 0xff0fffff ;
	GPIO_CRH |= 0x00200000 ;


	AFIO_EXTICR1 =0x0;
	EXTI_IMR |=(1<<0); //Unmask interrupt 0
	EXTI_RTSR |=(1<<0);//enable rising edge for interrupt 0
	NVIC_ISER0 |=(1<<6);//Enable NVIC 6
	while(1);
}

void EXTI0_IRQHandler(void)
{
	GPIO_ODR |= 1<<13 ;
	EXTI_PR |=(1<<0);
}
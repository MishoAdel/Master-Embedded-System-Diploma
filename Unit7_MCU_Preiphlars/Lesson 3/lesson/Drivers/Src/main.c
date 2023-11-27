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


#include "stm32f103c6_GPIO_driver.h"

void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}


int main(void)
{
	GPIOA_CLK_ENB;
	GPIOB_CLK_ENB;

	GPIO_Pin_Config My_Config;
	My_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_Config.Pin_Num=GPIO_PIN1;
	My_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(GPIOA, &My_Config);

	My_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_Config.Pin_Num=GPIO_PIN13;
	My_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(GPIOA, &My_Config);

	My_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Config.Pin_Num=GPIO_PIN1;
	My_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_Config);

	My_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Config.Pin_Num=GPIO_PIN13;
	My_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_Config);


	while(1)
	{
		if (MCAL_GPIO_read_pin(GPIOA, 1)==0)
		{
			MCAL_GPIO_toggle_pin(GPIOB, 1);
			while (MCAL_GPIO_read_pin(GPIOA, 1) == 0);
		}
		if (MCAL_GPIO_read_pin(GPIOA, 13)== 1)
		{
			MCAL_GPIO_toggle_pin(GPIOB, 13);
		}
		wait_ms(500);
	}
}
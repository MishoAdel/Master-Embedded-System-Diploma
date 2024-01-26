/*
 * seven_seg.c
 *
 *  Created on: Sep 28, 2023
 *      Author: mesho
 */
#include "seven_seg.h"

void seven_segment_init(void)
{


	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN9;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN10;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN11;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN12;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN13;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN14;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);

	My_7seg_config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_7seg_config.Pin_Num=GPIO_PIN15;
	My_7seg_config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(GPIOB, &My_7seg_config);
}

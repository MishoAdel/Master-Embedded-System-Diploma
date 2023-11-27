/*
 * stm32f103c6_EXTI_driver.c
 *
 *  Created on: Oct 2, 2023
 *      Author: mesho
 */

#include "stm32f103c6_EXTI_driver.h"



void  (* ISR_Func [16])(void);



/**================================================================
 * @Fn-MCAL_EXTI_GPIO_Deinit
 * @brief - this function deinitializes(resets) the EXTI all
 * @param1 [in] - none
 * @retval - none
 */
void MCAL_EXTI_GPIO_Deinit()
{
	EXTI->EMR	=0x00000000;
	EXTI->FTSR	=0x00000000;
	EXTI->IMR	=0x00000000;
	EXTI->PR	=0xFFFFFFFF;
	EXTI->RTSR	=0x00000000;
	EXTI->SWIER	=0x00000000;

	NVIC_disable_EXTI0;
	NVIC_disable_EXTI1;
	NVIC_disable_EXTI2;
	NVIC_disable_EXTI3;
	NVIC_disable_EXTI4;
	NVIC_disable_EXTI5_9;
	NVIC_disable_EXTI10_15;
}

/**================================================================
 * @Fn-MCAL_GPIO_init
 * @brief - this function enables NVIC for one line
 * @param1 [in] - line_num defines line number
 * @retval - none
 */
void MCAL_NVIC_Enable(uint8_t line_num)
{
	switch(line_num)
	{
	case EXTI_0:
		NVIC_enable_EXTI0;
		break;
	case EXTI_1:
		NVIC_enable_EXTI1;
		break;
	case EXTI_2:
		NVIC_enable_EXTI2;
		break;
	case EXTI_3:
		NVIC_enable_EXTI3;
		break;
	case EXTI_4:
		NVIC_enable_EXTI4;
		break;
	case EXTI_5:
	case EXTI_6:
	case EXTI_7:
	case EXTI_8:
	case EXTI_9:
		NVIC_enable_EXTI5_9;
		break;
	case EXTI_10:
	case EXTI_11:
	case EXTI_12:
	case EXTI_13:
	case EXTI_14:
	case EXTI_15:
		NVIC_enable_EXTI10_15;
		break;
	}
}


/**================================================================
 * @Fn-MCAL_GPIO_init
 * @brief - this function disables NVIC for one line
 * @param1 [in] - line_num defines line number
 * @retval - none
 */
void MCAL_NVIC_Disable(uint8_t line_num)
{
	switch(line_num)
	{
	case EXTI_0:
		NVIC_disable_EXTI0;
		break;
	case EXTI_1:
		NVIC_disable_EXTI1;
		break;
	case EXTI_2:
		NVIC_disable_EXTI2;
		break;
	case EXTI_3:
		NVIC_disable_EXTI3;
		break;
	case EXTI_4:
		NVIC_disable_EXTI4;
		break;
	case EXTI_5:
	case EXTI_6:
	case EXTI_7:
	case EXTI_8:
	case EXTI_9:
		NVIC_disable_EXTI5_9;
		break;
	case EXTI_10:
	case EXTI_11:
	case EXTI_12:
	case EXTI_13:
	case EXTI_14:
	case EXTI_15:
		NVIC_disable_EXTI10_15;
		break;
	}
}


/**================================================================
 * @Fn-MCAL_EXTI_GPIO_Init
 * @brief - this function initializes the GPIO port or pin for EXTI
 * @param1 [in] - My_EXTI_Config struct having EXTI configuration {	GPIO port and pin and EXTI l  @ref GPIO_EXTI_define
 * 																	, rising or falling @ref EXTI_trigger_define
 * 																	, enable or disable @ref EXTI_state_define
 * 																	, Pointer to Interrupt handler function }
 * @retval - none
 */

void MCAL_EXTI_GPIO_Init(EXTI_Config* My_EXTI_Config)
{
	MCAL_EXTI_GPIO_Update(My_EXTI_Config);
}


/**================================================================
 * @Fn-MCAL_EXTI_GPIO_Update
 * @brief - this function updates the GPIO port or pin for EXTI
 * @param1 [in] - My_EXTI_Config struct having EXTI configuration {	GPIO port and pin and EXTI l  @ref GPIO_EXTI_define
 * 																	, rising or falling @ref EXTI_trigger_define
 * 																	, enable or disable @ref EXTI_state_define
 * 																	, Pointer to Interrupt handler function }
 * @retval - none
 */

void MCAL_EXTI_GPIO_Update(EXTI_Config* My_EXTI_Config)
{
	// GPIO pin configuration
	GPIO_Pin_Config My_GPIO_EXTI;
	My_GPIO_EXTI.Pin_Mode=GPIO_MODE_Input_floating;
	My_GPIO_EXTI.Pin_Num=My_EXTI_Config->My_EXTI_pin.EXTI_GPIO_PINnum;
	My_GPIO_EXTI.Pin_Out_speed=0;
	MCAL_GPIO_init(My_EXTI_Config->My_EXTI_pin.EXTI_Port, &My_GPIO_EXTI);

	// AFIO configuration
	uint8_t EXTICR_position =My_EXTI_Config->My_EXTI_pin.EXTI_line_num/4 ;
	uint8_t EXTICR_offset =(My_EXTI_Config->My_EXTI_pin.EXTI_line_num%4)*4 ;
	uint8_t EXTICR_value;

	if(My_EXTI_Config->My_EXTI_pin.EXTI_Port==GPIOA)
	{
		EXTICR_value=0b0000;
	}else if(My_EXTI_Config->My_EXTI_pin.EXTI_Port==GPIOB)
	{
		EXTICR_value=0b0001;
	}
	else if(My_EXTI_Config->My_EXTI_pin.EXTI_Port==GPIOC)
	{
		EXTICR_value=0b0010;
	}
	else if(My_EXTI_Config->My_EXTI_pin.EXTI_Port==GPIOD)
	{
		EXTICR_value=0b0011;
	}

	//Define rising or falling edge trigger
	AFIO->AFIO_EXTICR[EXTICR_position] &=~(0xF << (EXTICR_offset));
	AFIO->AFIO_EXTICR[EXTICR_position] |=EXTICR_value << (EXTICR_offset);

	EXTI->RTSR &= ~(1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num);
	EXTI->FTSR &= ~(1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num);

	switch (My_EXTI_Config->EXTI_trigger)
	{
	case EXTI_Rising:
		EXTI->RTSR |= 1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num;
		break;
	case EXTI_falling:
		EXTI->FTSR |= 1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num;
		break;
	case EXTI_Rising_Falling:
		EXTI->RTSR |= 1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num;
		EXTI->FTSR |= 1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num;
		break;
	}

	// Setting interrupt service routine function
	ISR_Func[My_EXTI_Config->My_EXTI_pin.EXTI_line_num]=My_EXTI_Config->ISR_func;

	//NVIC and interrupt mask enable or disable
	if(My_EXTI_Config->EXTI_state==EXTI_enable)
	{
		MCAL_NVIC_Enable(My_EXTI_Config->My_EXTI_pin.EXTI_line_num);
		EXTI->IMR |= 1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num;
	}
	else if(My_EXTI_Config->EXTI_state==EXTI_disable)
	{
		MCAL_NVIC_Disable(My_EXTI_Config->My_EXTI_pin.EXTI_line_num);
		EXTI->IMR &= ~(1<< My_EXTI_Config->My_EXTI_pin.EXTI_line_num);
	}

}


//-----------------------------
//Interrupt service routine functions
//-----------------------------

void EXTI0_IRQHandler(void)
{
	EXTI->PR |= 1<<0;
	ISR_Func[0]();

}

void EXTI1_IRQHandler(void)
{
	EXTI->PR |= 1<<1;
	ISR_Func[1]();
}

void EXTI2_IRQHandler(void)
{
	EXTI->PR |= 1<<2;
	ISR_Func[2]();
}

void EXTI3_IRQHandler(void)
{
	EXTI->PR |= 1<<3;
	ISR_Func[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI->PR |= 1<<4;
	ISR_Func[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1<<5){EXTI->PR |= 1<<5; ISR_Func[5](); }
	if(EXTI->PR & 1<<6){EXTI->PR |= 1<<6; ISR_Func[6](); }
	if(EXTI->PR & 1<<7){EXTI->PR |= 1<<7; ISR_Func[7](); }
	if(EXTI->PR & 1<<8){EXTI->PR |= 1<<8; ISR_Func[8](); }
	if(EXTI->PR & 1<<9){EXTI->PR |= 1<<9; ISR_Func[9](); }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10){EXTI->PR |= 1<<10; ISR_Func[10](); }
	if(EXTI->PR & 1<<11){EXTI->PR |= 1<<11; ISR_Func[11](); }
	if(EXTI->PR & 1<<12){EXTI->PR |= 1<<12; ISR_Func[12](); }
	if(EXTI->PR & 1<<13){EXTI->PR |= 1<<13; ISR_Func[13](); }
	if(EXTI->PR & 1<<14){EXTI->PR |= 1<<14; ISR_Func[14](); }
	if(EXTI->PR & 1<<15){EXTI->PR |= 1<<15; ISR_Func[15](); }
}

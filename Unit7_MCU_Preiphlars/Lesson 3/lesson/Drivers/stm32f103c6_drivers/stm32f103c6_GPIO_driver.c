/*
 * stm32f103c6_GPIO_driver.c
 *
 *  Created on: Sep 17, 2023
 *      Author: mesho
 */

#include "stm32f103c6_GPIO_driver.h"

/**================================================================
 * @Fn-MCAL_GPIO_init
 * @brief - this function initializes the GPIO port or pin
 * @param1 [in] - GPIOx: has port address
 * @param2 [in] - GPIO_Type_Def: has port or pin configuration (pin number, mode ,  output speed)
 * @retval - none
 */
void MCAL_GPIO_init(GPIO_TypeDef * GPIOx, GPIO_Pin_Config* MyPin_Config){
	uint32_t setting;
	if(MyPin_Config->Pin_Mode<=3) //Input
	{
		switch (MyPin_Config->Pin_Mode) //define Mode and CNF
		{
		case GPIO_MODE_Input_analog:
			setting=0b0000;
			break;
		case GPIO_MODE_Input_floating:
			setting=0b0100;
			break;
		case GPIO_MODE_Input_pull_up:
			setting=0b1000;
			GPIOx->ODR |=(1<<MyPin_Config->Pin_Num);      //make it pull up
			break;
		case GPIO_MODE_Input_Pull_down:
			setting=0b1000;
			GPIOx->ODR&=~(1<<MyPin_Config->Pin_Num);	 //make it pull down
			break;
		}
	}
	else if(MyPin_Config->Pin_Mode>3 && MyPin_Config->Pin_Mode <8) // output
	{
		switch (MyPin_Config->Pin_Mode) //define Mode and CNF
		{
		case GPIO_MODE_Output_push_pull:
			setting=((0b00<<2) | MyPin_Config->Pin_Out_speed);
			break;
		case GPIO_MODE_Output_open_drain:
			setting=((0b01<<2) | MyPin_Config->Pin_Out_speed);
			break;
		case GPIO_MODE_Output_AFIO_push_pull:
			setting=((0b10<<2) | MyPin_Config->Pin_Out_speed);
			break;
		case GPIO_MODE_Output_AFIO_open_drain:
			setting=((0b11<<2) | MyPin_Config->Pin_Out_speed);
			break;
		}
	}

	if(MyPin_Config->Pin_Num<8) // writing on register
	{
		GPIOx->CRL &= ~(0xF << (MyPin_Config->Pin_Num)*4 );
		GPIOx->CRL |=(setting <<( (MyPin_Config->Pin_Num)*4 ) );
	}
	else if(MyPin_Config->Pin_Num==16)
	{
		GPIOx->CRL=(setting | setting<<4 | setting<<8 | setting<<12 | setting<<16 | setting<<20 | setting <<24 | setting<<28);
		GPIOx->CRH=(setting | setting<<4 | setting<<8 | setting<<12 | setting<<16 | setting<<20 | setting <<24 | setting<<28);
	}
	else if(MyPin_Config->Pin_Num<16)
	{
		GPIOx->CRH &= ~(0xF << (MyPin_Config->Pin_Num-8) *4 );
		GPIOx->CRH |=( setting<<( (MyPin_Config->Pin_Num-8) *4 ) );
	}
}

/**================================================================
 * @Fn-MCAL_GPIO_deinit
 * @brief - this function resets GPIO
 * @param1 [in] - GPIOx: has port address
 * @retval - none
 */
void MCAL_GPIO_deinit(GPIO_TypeDef * GPIOx)
{
	if(GPIOx ==GPIOA)
	{
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}
	else if(GPIOx==GPIOE)
	{
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}
}
/**================================================================
 * @Fn-MCAL_GPIO_write_port
 * @brief - this function is used to write on a port
 * @param1 [in] - GPIOx: has port address
 * @param2 [in] - Data: the data to be written on the port (16 bit)
 * @retval - none
 */
void MCAL_GPIO_write_port(uint16_t Data,GPIO_TypeDef * GPIOx)
{
	GPIOx->ODR=(uint32_t)Data;
}

/**================================================================
 * @Fn-MCAL_GPIO_write_pin
 * @brief - this function is used to write on a pin
 * @param1 [in] - Data: the data to be written on the pin @ref GPIO_pin_state
 * @param2 [in] - GPIOx: has port address
 * @param3 [in] - PinNumber : defines pin number from 0 to 15
 * @retval - none
 */
void MCAL_GPIO_write_pin(uint8_t Data,GPIO_TypeDef * GPIOx,uint8_t PinNumber)
{
	if(Data==GPIO_Pin_Low)
		GPIOx->ODR &= ~(1<<PinNumber);
	else if(Data==GPIO_Pin_High)
		GPIOx->ODR |= 1<<PinNumber;
}


/**================================================================
 * @Fn-MCAL_GPIO_read_port
 * @brief - this function is used to read a port
 * @param1 [in] - GPIOx: has port address
 * @retval - port value
 */
uint16_t MCAL_GPIO_read_port(GPIO_TypeDef * GPIOx)
{
	return (uint16_t)(GPIOx->IDR);
}

/**================================================================
 * @Fn-MCAL_GPIO_read_pin
 * @brief - this function is used to read a pin
 * @param1 [in] - GPIOx: has port address
 * @param2 [in] - PinNumber : defines pin number from 0 to 15
 * @retval - pin value
 */
uint8_t MCAL_GPIO_read_pin(GPIO_TypeDef * GPIOx ,uint8_t PinMumber)
{
	 if((GPIOx->IDR & (1<<PinMumber))==0)
		 return 0;
	 else
		 return 1;
}

/**================================================================
 * @Fn-MCAL_GPIO_toggle_pin
 * @brief - this function is used to toggle a port
 * @param1 [in] - GPIOx: has port address
 * @param2 [in] - PinNumber : defines pin number from 0 to 15
 * @retval - none
 */
void MCAL_GPIO_toggle_pin(GPIO_TypeDef * GPIOx ,uint8_t PinMumber)
{
	GPIOx->ODR ^= 1<<PinMumber;
}

/**================================================================
 * @Fn-MCAL_GPIO_lock_pin
 * @brief - this function is used to lock a port
 * @param1 [in] - GPIOx: has port address
 * @param2 [in] - PinNumber : defines pin number from 0 to 15
 * @retval - state either locked happened or not @ref GPIO_LOCK_return
 */
uint8_t MCAL_GPIO_lock_pin(GPIO_TypeDef * GPIOx ,uint8_t PinMumber)
{
	uint32_t MyStat=0;
	GPIOx->LCKR |= 1<<PinMumber;
	GPIOx->LCKR |= 1<<16;
	GPIOx->LCKR &= ~(1<<16);
	GPIOx->LCKR |= 1<<16;
	MyStat= (GPIOx->LCKR & (1<<16));
	if((GPIOx->LCKR & (1<<16))==0)
		return GPIO_PIN_NOT_LOCKED;
	else
		return GPIO_PIN_LOCKED;
}

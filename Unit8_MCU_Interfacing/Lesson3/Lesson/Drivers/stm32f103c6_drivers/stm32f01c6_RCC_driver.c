/*
 * stm32f01c6_RCC_driver.c
 *
 *  Created on: Nov 28, 2023
 *      Author: mesho
 */
#include "stm32f10c6_RCC_driver.h"
/**================================================================
 * @Fn-MCAL_RCC_clock_update
 * @brief - this function updates the clock values and setting
 * @param1 [in] - *clk_config : configuration of clock setting
 * @retval - none
 */
void MCAL_RCC_clock_update(RCC_clock_Config* clk_config){

	RCC->CFGR &=~(0b11);
	RCC->CFGR |=clk_config->clock_source;

	RCC->CFGR &=~(0b1111<<4);
	RCC->CFGR |=clk_config->AHB_prescaler;

	RCC->CFGR &=~(0b111<<8);
	RCC->CFGR |=clk_config->APB1_prescaler;

	RCC->CFGR &=~(0b111<<11);
	RCC->CFGR |=clk_config->APB2_prescaler;


	if(clk_config->PLL_value){
		RCC->CFGR &=~(0b1111<<18);
		RCC->CFGR |=clk_config->PLL_value;

		RCC->CFGR &=~(0b11<<16);
		RCC->CFGR |=clk_config->PLL_source;
	}

	RCC->CFGR &=~(0b111<<24);
	RCC->CFGR |=clk_config->clock_output;

}
//to do ADC and usb prescalers


/**================================================================
 * @Fn-MCAL_RCC_get_system_clock
 * @brief - this function gets system clock
 * @retval - system clock
 */
uint32_t MCAL_RCC_get_system_clock(){
	uint32_t pll;
	switch((RCC->CFGR>>2)&0b11){

	case 0:
		return(internal_clock);
		break;
	case 1:
		return(external_clock);
		break;
	case 2:
		if((RCC->CFGR>>16)&1){
			pll=external_clock *( ( ( RCC->CFGR >>18 ) & 0b1111 ) + 1 );
		}else{
			if((RCC->CFGR>>17)&1){
				pll= (internal_clock/2)*( ( ( RCC->CFGR >>18 ) & 0b1111 ) + 1 );
			}else{
				pll= (internal_clock)*( ( ( RCC->CFGR >>18 ) & 0b1111 ) + 1 );
			}
		}
		return(pll);
		break;

	};
}


/**================================================================
 * @Fn-MCAL_RCC_get_AHB_clock
 * @brief - this function gets AHB clock
 * @retval - AHB clock
 */
uint8_t AHBprescaler[]={0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8};
uint8_t APBprescaler[]={0,0,0,0,1,2,3,4};

uint32_t MCAL_RCC_get_AHB_clock(){

	return((MCAL_RCC_get_system_clock())>>(AHBprescaler[(((RCC->CFGR)>>4)&0b1111)]));

}

/**================================================================
 * @Fn-MCAL_RCC_get_APB1_clock
 * @brief - this function gets APB1 clock
 * @retval - APB1 clock
 */
uint32_t MCAL_RCC_get_APB1_clock(){

	return((MCAL_RCC_get_AHB_clock()) >> (APBprescaler[(((RCC->CFGR)>>8)&0b111)]));

}

/**================================================================
 * @Fn-MCAL_RCC_get_APB2_clock
 * @brief - this function gets APB2 clock
 * @retval - APB2 clock
 */
uint32_t MCAL_RCC_get_APB2_clock(){

	return((MCAL_RCC_get_AHB_clock())>>(APBprescaler[(((RCC->CFGR)>>11)&0b111)]));

}

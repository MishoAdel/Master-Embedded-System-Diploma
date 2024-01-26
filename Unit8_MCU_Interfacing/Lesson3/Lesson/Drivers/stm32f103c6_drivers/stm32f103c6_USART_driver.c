/*
 * stm32f103c6_USART_driver.c
 *
 *  Created on: Nov 28, 2023
 *      Author: mesho
 */

#include "stm32f103c6_USART_driver.h"






//Macros to calculate baud rate
#define USARTDIV(_PCLK_, _BAUD_)			((uint32_t)(_PCLK_/(16 * _BAUD_)))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)		((uint32_t)((25 * _PCLK_) / (4 * _BAUD_)))
#define Mantissa_MUL100(_PCLK_, _BAUD_)		((uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100))
#define Mantissa(_PCLK_, _BAUD_)			((uint32_t)(USARTDIV(_PCLK_, _BAUD_)))
#define DIV_Fraction(_PCLK_, _BAUD_)		((uint32_t)((((USARTDIV_MUL100(_PCLK_, _BAUD_)) - (Mantissa_MUL100(_PCLK_, _BAUD_))) * 16) / 100) )
#define USART_BRR_REGISTER(_PCLK_, _BAUD_)	( (Mantissa(_PCLK_, _BAUD_) << 4 ) | (DIV_Fraction(_PCLK_, _BAUD_) & 0xF) )


/**================================================================
 * @Fn-MCAL_USART_init
 * @brief - this function initializes the USART
 * @param1 [in] - USART_TypeDef: has USART configuration (Mode, Baud Rate,  Payload Length, Parity, Stop Bits, HW Flow CTRL,Interrupt Enable,Interrupt call back function)
 * @param2 [in] - GPIOx: has USART address
 * @retval - none
 */
void MCAL_USART_init(USART_Config* my_usart_config,USART_TypeDef* USARTx){
	uint32_t BBR_var;
	uint32_t pclk;
	//Enable Clock
	if(USARTx==USART1)
		USART1_CLK_ENB;
	else if(USARTx==USART2)
		USART2_CLK_ENB;
	else
		USART3_CLK_ENB;


	//Enable USART
	USARTx->CR1 &=~(1<<13);
	USARTx->CR1 |=1<<13;

	//Set Payload Length
	USARTx->CR1 &=~(1<<12);
	USARTx->CR1 |= my_usart_config->Payload_length;

	//Set Parity
	USARTx->CR1 &=~(0b11<<8);
	USARTx->CR1 |= my_usart_config->Parity;

	//Set stop bits
	USARTx->CR2 &=~(0b11<<12);
	USARTx->CR2 |=my_usart_config->Stopbits;

	//Set HW Flow CTR
	USARTx->CR3 &=~(0b11<<8);
	USARTx->CR3 |=my_usart_config->HWFlowCTRL;

	//Baud Rate
	if(USARTx==USART1){
		pclk=MCAL_RCC_get_APB2_clock();
		BBR_var=USART_BRR_REGISTER(pclk,my_usart_config->BaudRate);
	}else{
		pclk=MCAL_RCC_get_APB1_clock();
		BBR_var=USART_BRR_REGISTER(pclk,my_usart_config->BaudRate);
	}

	USARTx->BRR=BBR_var;

	//Enable TX RX
	USARTx->CR1 &=~(0b11<<2);
	USARTx->CR1 |= my_usart_config->USART_Mode;

	//Enable interrupts
	if(my_usart_config->IRQ_Enable!=USART_IRQ_Enable_None){
		USARTx->CR1 |= my_usart_config->IRQ_Enable;

		if(USARTx==USART1)
			NVIC_enable_USART1;
		else if(USARTx==USART2)
			NVIC_enable_USART2;
		else
			NVIC_enable_USART3;

	}


}




/**================================================================
 * @Fn-MCAL_USART_deinit
 * @brief - this function deinitializes the USART
 * @param1 [in] - GPIOx: has USART address
 * @retval - none
 */
void MCAL_USART_deinit(USART_TypeDef* USARTx){

	if(USARTx==USART1){
		USART1_RESET;
		NVIC_disable_USART1;
	}else if(USARTx==USART2){
		NVIC_disable_USART2;
		USART2_RESET;
	}else{
		NVIC_disable_USART3;
		USART3_RESET;
	}
}

void MCAL_USART_GPIO_setpins(USART_TypeDef* USARTx){

	GPIO_Pin_Config my_pin_config;
	if(USARTx==USART1){
		if(USART1_Config.USART_Mode==USART_Mode_TX){
			my_pin_config.Pin_Num=GPIO_PIN9;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);

		}else if(USART1_Config.USART_Mode==USART_Mode_RX){
			my_pin_config.Pin_Num=GPIO_PIN10;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART1_Config.USART_Mode==USART_Mode_TX_RX){
			my_pin_config.Pin_Num=GPIO_PIN9;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
			my_pin_config.Pin_Num=GPIO_PIN10;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}

		if(USART1_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS){
			my_pin_config.Pin_Num=GPIO_PIN11;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART1_Config.HWFlowCTRL==USART_HWFlowCTRL_RTS){
			my_pin_config.Pin_Num=GPIO_PIN12;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART1_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS_RTS){
			my_pin_config.Pin_Num=GPIO_PIN11;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
			my_pin_config.Pin_Num=GPIO_PIN12;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}

	}else if(USARTx==USART2){
		if(USART2_Config.USART_Mode==USART_Mode_TX){
			my_pin_config.Pin_Num=GPIO_PIN2;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);

		}else if(USART2_Config.USART_Mode==USART_Mode_RX){
			my_pin_config.Pin_Num=GPIO_PIN3;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART2_Config.USART_Mode==USART_Mode_TX_RX){
			my_pin_config.Pin_Num=GPIO_PIN2;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
			my_pin_config.Pin_Num=GPIO_PIN3;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}

		if(USART2_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS){
			my_pin_config.Pin_Num=GPIO_PIN0;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART2_Config.HWFlowCTRL==USART_HWFlowCTRL_RTS){
			my_pin_config.Pin_Num=GPIO_PIN1;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}else if(USART2_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS_RTS){
			my_pin_config.Pin_Num=GPIO_PIN0;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
			my_pin_config.Pin_Num=GPIO_PIN1;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_pin_config);
		}
	}else{
		if(USART3_Config.USART_Mode==USART_Mode_TX){
			my_pin_config.Pin_Num=GPIO_PIN10;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOB, &my_pin_config);
		}else if(USART3_Config.USART_Mode==USART_Mode_RX){
			my_pin_config.Pin_Num=GPIO_PIN11;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOB, &my_pin_config);
		}else if(USART3_Config.USART_Mode==USART_Mode_TX_RX){
			my_pin_config.Pin_Num=GPIO_PIN10;
			my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOB, &my_pin_config);
			my_pin_config.Pin_Num=GPIO_PIN11;
			my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
			my_pin_config.Pin_Out_speed=0;
			MCAL_GPIO_init(GPIOB, &my_pin_config);
		}
	}

	if(USART3_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS){
		my_pin_config.Pin_Num=GPIO_PIN13;
		my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
		my_pin_config.Pin_Out_speed=0;
		MCAL_GPIO_init(GPIOB, &my_pin_config);
	}else if(USART3_Config.HWFlowCTRL==USART_HWFlowCTRL_RTS){
		my_pin_config.Pin_Num=GPIO_PIN14;
		my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
		my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(GPIOB, &my_pin_config);
	}else if(USART1_Config.HWFlowCTRL==USART_HWFlowCTRL_CTS_RTS){
		my_pin_config.Pin_Num=GPIO_PIN13;
		my_pin_config.Pin_Mode=GPIO_MODE_Input_floating;
		my_pin_config.Pin_Out_speed=0;
		MCAL_GPIO_init(GPIOB, &my_pin_config);
		my_pin_config.Pin_Num=GPIO_PIN14;
		my_pin_config.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
		my_pin_config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(GPIOB, &my_pin_config);
	}

}

void MCAL_USART_send_data(USART_TypeDef* USARTx,uint16_t* TX_Buffer,enum Polling_mechanism polling_en){

	if(polling_en== enable){
		while(!((USARTx->SR)>>7));
	}

	if(USARTx==USART1){
		if(USART1_Config.Payload_length==USART_Payload_9bit){
			USARTx->DR = (*TX_Buffer & (uint16_t)0x1FF);
		}else{
			USARTx->DR = (*TX_Buffer & (uint8_t)0xFF);
		}
	}else if(USARTx==USART2){
		if(USART2_Config.Payload_length==USART_Payload_9bit){
			USARTx->DR = (*TX_Buffer & (uint16_t)0x1FF);
		}else{
			USARTx->DR = (*TX_Buffer & (uint8_t)0xFF);
		}
	}else{
		if(USART3_Config.Payload_length==USART_Payload_9bit){
			USARTx->DR = (*TX_Buffer & (uint16_t)0x1FF);
		}else{
			USARTx->DR = (*TX_Buffer & (uint8_t)0xFF);
		}
	}
}


void MCAL_USART_recieve_data(USART_TypeDef* USARTx,uint16_t* RX_Buffer,enum Polling_mechanism polling_en){
	if(polling_en== enable){
		while(!((USARTx->SR) & 1<<5 ));
	}

	if(USARTx==USART1){
		if(USART1_Config.Payload_length==USART_Payload_9bit){
			if(USART1_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=USARTx->DR;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
		}else{
			if(USART1_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0x7F) ;
			}
		}
	}else if(USARTx==USART2){
		if(USART2_Config.Payload_length==USART_Payload_9bit){
			if(USART2_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=USARTx->DR;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
		}else{
			if(USART2_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0x7F) ;
			}
		}
	}else{

		if(USART3_Config.Payload_length==USART_Payload_9bit){
			if(USART3_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=USARTx->DR;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
		}else{
			if(USART3_Config.Parity == USART_No_Parity){
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0xFF) ;
			}
			else{
				*((uint16_t*)RX_Buffer)=(USARTx->DR & (uint8_t)0x7F) ;
			}
		}


	}
}

void MCAL_USART_wait_TC(USART_TypeDef* USARTx){
	while(!(USARTx->SR & 1<<6));
}


void USART1_IRQHandler (){
	USART1_Config.P_IRQ_CallBack();
}

void USART2_IRQHandler (){
	USART2_Config.P_IRQ_CallBack();
}

void USART3_IRQHandler (){
	USART3_Config.P_IRQ_CallBack();
}

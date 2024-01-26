/*
 * stm32f013c6_SPI_driver.c
 *
 *  Created on: Jan 25, 2024
 *      Author: mesho
 */
#include <stm32f103c6_SPI_driver.h>

//-----------------------------
//Generic variables
//-----------------------------
SPI_Config* Global_SPI_Config[2];

//-----------------------------
//Generic Macros
//-----------------------------
#define SPI1_Index		0
#define SPI2_Index		1


#define SPI_SR_TXE		((uint8_t)0x2)
#define SPI_SR_RXNE		((uint8_t)0x1)

/**================================================================
 * @Fn-MCAL_SPI_init
 * @brief - this function initializes the USART
 * @param1 [in] - USART_TypeDef: has SPI configuration (Mode,Communication mode,Data size,Data Frame,Clock Polarity,Clock Phase,NSS control,Baud Rate Prescaler,Interrupt Enable,Interrupt call back function)
 * @param2 [in] - GPIOx: has USART address
 * @retval - none
 */
void MCAL_SPI_Init(SPI_TypeDef* SPIx,SPI_Config* My_SPI_Config){
	uint16_t tempCR1=0;
	uint16_t tempCR2=0;

	if(SPIx==SPI1){
		Global_SPI_Config[SPI1_Index]=My_SPI_Config;
		SPI1_ClK_ENB;
	}else if(SPIx==SPI2){
		Global_SPI_Config[SPI2_Index]=My_SPI_Config;
		SPI2_ClK_ENB;
	}
	tempCR1|=(1<<6);
	tempCR1|=My_SPI_Config->Device_Mode;
	tempCR1|=My_SPI_Config->Communication_Mode;
	tempCR1|=My_SPI_Config->DataFrame;
	tempCR1|=My_SPI_Config->DataSize;
	tempCR1|=My_SPI_Config->CLK_Polarity;
	tempCR1|=My_SPI_Config->CLK_Phase;

	if(My_SPI_Config->NSS==SPI_NSS_Hard_Master_SS_Output_Enable){
		tempCR2|=My_SPI_Config->NSS;
	}else if(My_SPI_Config->NSS==SPI_NSS_Hard_Master_SS_Output_Disable){
		tempCR2&=My_SPI_Config->NSS;
	}else{
		tempCR1|=My_SPI_Config->NSS;
	}

	tempCR1|=My_SPI_Config->BaudRate_Prescaler;

	if(My_SPI_Config->IRQ_Enable!=SPI_IRQ_Enable_None){

		tempCR2|=My_SPI_Config->IRQ_Enable;
		if(SPIx==SPI1){
			NVIC_enable_SPI1;

		}else if(SPIx==SPI2){
			NVIC_enable_SPI2;
		}
	}

	SPIx->CR1=tempCR1;
	SPIx->CR2=tempCR2;

}



/**================================================================
 * @Fn-MCAL_SPI_deinit
 * @brief - this function deinitializes the SPI and resets the prephilar
 * @param1 [in] - SPIx: has SPI address
 * @retval - none
 */
void MCAL_SPI_Deinit(SPI_TypeDef* SPIx){

	if(SPIx==SPI1){
		NVIC_disable_SPI1;
		SPI1_RESET;
	}else if(SPIx==SPI2){
		NVIC_disable_SPI2;
		SPI2_RESET;
	}

}



/**================================================================
 * @Fn-MCAL_USART_GPIO_setpins
 * @brief - this function sets the pins for the usart using the preferred types
 * @param1 [in] - USARTx: has USART address
 * @retval - none
 */
void MCAL_SPI_Set_GPIO_Pins(SPI_TypeDef* SPIx){
	GPIO_Pin_Config my_spi_pin;
	if(SPIx==SPI1){
		//NSS PA4
		if(Global_SPI_Config[SPI1_Index]->Device_Mode==SPI_Mode_Master){
			switch(Global_SPI_Config[SPI1_Index]->NSS){
			case SPI_NSS_Hard_Master_SS_Output_Enable:
				my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
				my_spi_pin.Pin_Num=GPIO_PIN4;
				MCAL_GPIO_init(GPIOA, &my_spi_pin);
				break;
			case SPI_NSS_Hard_Master_SS_Output_Disable :
				my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
				my_spi_pin.Pin_Num=GPIO_PIN4;
				my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
				MCAL_GPIO_init(GPIOA, &my_spi_pin);
				break;
			}
			//CLK PA5
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN5;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);
			//MOSI PA7
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN7;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);
			//MISO PA6
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN6;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);

		}else{
			//NSS PA4
			if(Global_SPI_Config[SPI1_Index]->NSS==SPI_NSS_Hard_Slave){
				my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
				my_spi_pin.Pin_Num=GPIO_PIN4;
				MCAL_GPIO_init(GPIOA, &my_spi_pin);
			}
			//CLK PA5
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN5;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);
			//MOSI PA7
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN7;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);
			//MISO PA6
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN6;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOA, &my_spi_pin);
		}


	}else if(SPIx==SPI2){


		//NSS PB12
		if(Global_SPI_Config[SPI1_Index]->Device_Mode==SPI_Mode_Master){
			switch(Global_SPI_Config[SPI1_Index]->NSS){
			case SPI_NSS_Hard_Master_SS_Output_Enable:
				my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
				my_spi_pin.Pin_Num=GPIO_PIN12;
				MCAL_GPIO_init(GPIOB, &my_spi_pin);
				break;
			case SPI_NSS_Hard_Master_SS_Output_Disable:
				my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
				my_spi_pin.Pin_Num=GPIO_PIN12;
				my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
				MCAL_GPIO_init(GPIOB, &my_spi_pin);
				break;
			}
			//CLK PB13
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN13;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);
			//MOSI PB15
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN15;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);
			//MISO PB14
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN14;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);

		}else{
			//NSS PB12
			if(Global_SPI_Config[SPI1_Index]->NSS==SPI_NSS_Hard_Slave){
				my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
				my_spi_pin.Pin_Num=GPIO_PIN12;
				MCAL_GPIO_init(GPIOB, &my_spi_pin);
			}
			//CLK PB13
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN13;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);
			//MOSI PA15
			my_spi_pin.Pin_Mode=GPIO_MODE_Input_floating;
			my_spi_pin.Pin_Num=GPIO_PIN15;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);
			//MISO PA6
			my_spi_pin.Pin_Mode=GPIO_MODE_Output_AFIO_push_pull;
			my_spi_pin.Pin_Num=GPIO_PIN14;
			my_spi_pin.Pin_Out_speed=GPIO_Speed_10MHZ;
			MCAL_GPIO_init(GPIOB, &my_spi_pin);
		}
	}
}



/**================================================================
 * @Fn-MCAL_SPI_Send_Data
 * @brief - this function sends data though SPI
 * @param1 [in] - SPIx: has SPI address
 * @param2 [in] - buffer: buffer variable to store data to be transmitted
 * @param3 [in] - Polling_mechanism: defines if we use polling or not
 * @retval - none
 */
void MCAL_SPI_Send_Data(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State){

	//todo check for mode of communication
	if(Polling_State==Polling_enable)
		while(!(SPIx->SR  & SPI_SR_TXE));
	SPIx->DR=*buffer;

}
/**================================================================
 * @Fn-MCAL_SPI_Receive_Data
 * @brief - this function receives data though SPI
 * @param1 [in] - SPIx: has SPI address
 * @param2 [in] - buffer: buffer variable to store data to be received
 * @param3 [in] - Polling_mechanism: defines if we use polling or not
 * @retval - none
 */
void MCAL_SPI_Recieve_Data(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State){

	//todo check for mode of communication
	if(Polling_State==Polling_enable)
		while(!(SPIx->SR  & SPI_SR_RXNE));
	*buffer=SPIx->DR;

}

/**================================================================
 * @Fn-MCAL_SPI_Receive_Data
 * @brief - this function sends and receives data though SPI
 * @param1 [in] - SPIx: has SPI address
 * @param2 [in] - buffer: buffer variable to store data to be transmitted and store received data
 * @param3 [in] - Polling_mechanism: defines if we use polling or not
 * @retval - none
 */
void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx,uint16_t* buffer,enum Polling_mechanism_SPI Polling_State){
	//todo check for mode of communication
	if(Polling_State==Polling_enable)
		while(!(SPIx->SR  & SPI_SR_TXE));
	SPIx->DR=*buffer;
	if(Polling_State==Polling_enable)
		while(!(SPIx->SR  & SPI_SR_RXNE));
	*buffer=SPIx->DR;
}


//-----------------------------
//IRQ
//-----------------------------

void SPI1_IRQHandler(struct S_IRQ_SRC irq_src){

	irq_src.TXE=((SPI1->SR &(1<<1))>>1);
	irq_src.RXNE=((SPI1->SR &(1<<0))>>0);
	irq_src.ERRI=((SPI1->SR &(1<<4))>>4);

	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);

}

void SPI2_IRQHandler(struct S_IRQ_SRC irq_src){

	irq_src.TXE=((SPI2->SR &(1<<1))>>1);
	irq_src.RXNE=((SPI2->SR &(1<<0))>>0);
	irq_src.ERRI=((SPI2->SR &(1<<4))>>4);

	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);

}

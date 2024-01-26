/*
 * stm32f103c6_EXTI_driver.h
 *
 *  Created on: Oct 2, 2023
 *      Author: mesho
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103xx.h"
#include "stm32f103c6_GPIO_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

//configration structure
typedef struct{

	uint8_t EXTI_line_num;
	GPIO_TypeDef* EXTI_Port;
	uint8_t EXTI_GPIO_PINnum;
	uint8_t EXTI_IRQ_num;


}EXTI_GPIO_Config;

typedef struct{

	EXTI_GPIO_Config My_EXTI_pin;			//This defines the GPIO for EXTI with port and pin
											//you can find the value of this parameter @ref GPIO_EXTI_define
	uint8_t EXTI_trigger;					//This defines the EXTI trigger method
											//you can find the value of this parameter @ref EXTI_trigger_define
	uint8_t EXTI_state;						//This defines the EXTI enable or disable method
											//you can find the value of this parameter @ref EXTI_state_define
	void (*ISR_func)(void);					//This defines the Interrupt service routine

}EXTI_Config;

//-----------------------------
//Macros Configuration References
//-----------------------------
// @ref GPIO_EXTI_define

#define EXTI0PA0		(EXTI_GPIO_Config){EXTI_0,GPIOA,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PB0		(EXTI_GPIO_Config){EXTI_0,GPIOB,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PC0		(EXTI_GPIO_Config){EXTI_0,GPIOC,GPIO_PIN0,EXTI0_IRQ}
#define EXTI0PD0		(EXTI_GPIO_Config){EXTI_0,GPIOD,GPIO_PIN0,EXTI0_IRQ}

#define EXTI1PA1		(EXTI_GPIO_Config){EXTI_1,GPIOA,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PB1		(EXTI_GPIO_Config){EXTI_1,GPIOB,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PC1		(EXTI_GPIO_Config){EXTI_1,GPIOC,GPIO_PIN1,EXTI1_IRQ}
#define EXTI1PD1		(EXTI_GPIO_Config){EXTI_1,GPIOD,GPIO_PIN1,EXTI1_IRQ}

#define EXTI2PA2		(EXTI_GPIO_Config){EXTI_2,GPIOA,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PB2		(EXTI_GPIO_Config){EXTI_2,GPIOB,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PC2		(EXTI_GPIO_Config){EXTI_2,GPIOC,GPIO_PIN2,EXTI2_IRQ}
#define EXTI2PD2		(EXTI_GPIO_Config){EXTI_2,GPIOD,GPIO_PIN2,EXTI2_IRQ}

#define EXTI3PA3		(EXTI_GPIO_Config){EXTI_3,GPIOA,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PB3		(EXTI_GPIO_Config){EXTI_3,GPIOB,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PC3		(EXTI_GPIO_Config){EXTI_3,GPIOC,GPIO_PIN3,EXTI3_IRQ}
#define EXTI3PD3		(EXTI_GPIO_Config){EXTI_3,GPIOD,GPIO_PIN3,EXTI3_IRQ}

#define EXTI4PA4		(EXTI_GPIO_Config){EXTI_4,GPIOA,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PB4		(EXTI_GPIO_Config){EXTI_4,GPIOB,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PC4		(EXTI_GPIO_Config){EXTI_4,GPIOC,GPIO_PIN4,EXTI4_IRQ}
#define EXTI4PD4		(EXTI_GPIO_Config){EXTI_4,GPIOD,GPIO_PIN4,EXTI4_IRQ}

#define EXTI5PA5		(EXTI_GPIO_Config){EXTI_5,GPIOA,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PB5		(EXTI_GPIO_Config){EXTI_5,GPIOB,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PC5		(EXTI_GPIO_Config){EXTI_5,GPIOC,GPIO_PIN5,EXTI5_IRQ}
#define EXTI5PD5		(EXTI_GPIO_Config){EXTI_5,GPIOD,GPIO_PIN5,EXTI5_IRQ}

#define EXTI6PA6		(EXTI_GPIO_Config){EXTI_6,GPIOA,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PB6		(EXTI_GPIO_Config){EXTI_6,GPIOB,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PC6		(EXTI_GPIO_Config){EXTI_6,GPIOC,GPIO_PIN6,EXTI6_IRQ}
#define EXTI6PD6		(EXTI_GPIO_Config){EXTI_6,GPIOD,GPIO_PIN6,EXTI6_IRQ}

#define EXTI7PA7		(EXTI_GPIO_Config){EXTI_7,GPIOA,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PB7		(EXTI_GPIO_Config){EXTI_7,GPIOB,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PC7		(EXTI_GPIO_Config){EXTI_7,GPIOC,GPIO_PIN7,EXTI7_IRQ}
#define EXTI7PD7		(EXTI_GPIO_Config){EXTI_7,GPIOD,GPIO_PIN7,EXTI7_IRQ}

#define EXTI8PA8		(EXTI_GPIO_Config){EXTI_8,GPIOA,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PB8		(EXTI_GPIO_Config){EXTI_8,GPIOB,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PC8		(EXTI_GPIO_Config){EXTI_8,GPIOC,GPIO_PIN8,EXTI8_IRQ}
#define EXTI8PD8		(EXTI_GPIO_Config){EXTI_8,GPIOD,GPIO_PIN8,EXTI8_IRQ}

#define EXTI9PA9		(EXTI_GPIO_Config){EXTI_9,GPIOA,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PB9		(EXTI_GPIO_Config){EXTI_9,GPIOB,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PC9		(EXTI_GPIO_Config){EXTI_9,GPIOC,GPIO_PIN9,EXTI9_IRQ}
#define EXTI9PD9		(EXTI_GPIO_Config){EXTI_9,GPIOD,GPIO_PIN9,EXTI9_IRQ}

#define EXTI10PA10		(EXTI_GPIO_Config){EXTI_10,GPIOA,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PB10		(EXTI_GPIO_Config){EXTI_10,GPIOB,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PC10		(EXTI_GPIO_Config){EXTI_10,GPIOC,GPIO_PIN10,EXTI10_IRQ}
#define EXTI10PD10		(EXTI_GPIO_Config){EXTI_10,GPIOD,GPIO_PIN10,EXTI10_IRQ}

#define EXTI11PA11		(EXTI_GPIO_Config){EXTI_11,GPIOA,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PB11		(EXTI_GPIO_Config){EXTI_11,GPIOB,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PC11		(EXTI_GPIO_Config){EXTI_11,GPIOC,GPIO_PIN11,EXTI11_IRQ}
#define EXTI11PD11		(EXTI_GPIO_Config){EXTI_11,GPIOD,GPIO_PIN11,EXTI11_IRQ}

#define EXTI12PA12		(EXTI_GPIO_Config){EXTI_12,GPIOA,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PB12		(EXTI_GPIO_Config){EXTI_12,GPIOB,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PC12		(EXTI_GPIO_Config){EXTI_12,GPIOC,GPIO_PIN12,EXTI12_IRQ}
#define EXTI12PD12		(EXTI_GPIO_Config){EXTI_12,GPIOD,GPIO_PIN12,EXTI12_IRQ}

#define EXTI13PA13		(EXTI_GPIO_Config){EXTI_13,GPIOA,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PB13		(EXTI_GPIO_Config){EXTI_13,GPIOB,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PC13		(EXTI_GPIO_Config){EXTI_13,GPIOC,GPIO_PIN13,EXTI13_IRQ}
#define EXTI13PD13		(EXTI_GPIO_Config){EXTI_13,GPIOD,GPIO_PIN13,EXTI13_IRQ}

#define EXTI14PA14		(EXTI_GPIO_Config){EXTI_14,GPIOA,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PB14		(EXTI_GPIO_Config){EXTI_14,GPIOB,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PC14		(EXTI_GPIO_Config){EXTI_14,GPIOC,GPIO_PIN14,EXTI14_IRQ}
#define EXTI14PD14		(EXTI_GPIO_Config){EXTI_14,GPIOD,GPIO_PIN14,EXTI14_IRQ}

#define EXTI15PA15		(EXTI_GPIO_Config){EXTI_15,GPIOA,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PB15		(EXTI_GPIO_Config){EXTI_15,GPIOB,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PC15		(EXTI_GPIO_Config){EXTI_15,GPIOC,GPIO_PIN15,EXTI15_IRQ}
#define EXTI15PD15		(EXTI_GPIO_Config){EXTI_15,GPIOD,GPIO_PIN15,EXTI15_IRQ}


//@ref EXTI_trigger_define
#define EXTI_Rising 				0
#define EXTI_falling 				1
#define EXTI_Rising_Falling 		2


//@ref EXTI_state_define
#define EXTI_enable					1
#define EXTI_disable				0
//EXTI line number
#define EXTI_0			0
#define EXTI_1			1
#define EXTI_2			2
#define EXTI_3			3
#define EXTI_4			4
#define EXTI_5			5
#define EXTI_6			6
#define EXTI_7			7
#define EXTI_8			8
#define EXTI_9			9
#define EXTI_10			10
#define EXTI_11			11
#define EXTI_12			12
#define EXTI_13			13
#define EXTI_14			14
#define EXTI_15			15




/*
* ===============================================
* APIs Supported by "MCAL EXTI DRIVER"
* ===============================================
*/

void MCAL_NVIC_Enable(uint8_t line_num);
void MCAL_NVIC_Disable(uint8_t line_num);

void MCAL_EXTI_GPIO_Init(EXTI_Config* My_EXTI_Config);
void MCAL_EXTI_GPIO_Deinit();
void MCAL_EXTI_GPIO_Update(EXTI_Config* My_EXTI_Config);



#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */

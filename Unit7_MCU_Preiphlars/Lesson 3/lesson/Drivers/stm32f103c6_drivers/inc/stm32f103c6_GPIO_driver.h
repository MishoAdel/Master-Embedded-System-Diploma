/*
 * stm32f103c6_GPIO_driver.h
 *
 *  Created on: Sep 17, 2023
 *      Author: mesho
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103xx.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------

//configration structure
typedef struct {
	uint16_t Pin_Num;				//This defines the GPIO pin number
									//you can find the value of this parameter @ref GPIO_pin_number_define
	uint8_t Pin_Mode;				//This defines the GPIO pin number
									//you can find the value of this parameter @ref GPIO_pin_mode_define
	uint8_t Pin_Out_speed;			//This defines the GPIO pin number
									//you can find the value of this parameter @ref GPIO_pin_output_speed_define
}GPIO_Pin_Config;

//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref GPIO_pin_number_define
 * Here are the values of the pins numbers from 0 to 15
*/
#define GPIO_PIN0					0
#define GPIO_PIN1					1
#define GPIO_PIN2					2
#define GPIO_PIN3					3
#define GPIO_PIN4					4
#define GPIO_PIN5					5
#define GPIO_PIN6					6
#define GPIO_PIN7					7
#define GPIO_PIN8					8
#define GPIO_PIN9					9
#define GPIO_PIN10					10
#define GPIO_PIN11					11
#define GPIO_PIN12					12
#define GPIO_PIN13					13
#define GPIO_PIN14					14
#define GPIO_PIN15					15
#define GPIO_PIN_ALL				16

/*@ref GPIO_pin_mode_define
 * Here are the values of the pin mode
 * 0:Input analog
 * 1:Input floating
 * 2:Input pull up
 * 3:Input pull down
 * 4:Output push pull
 * 5:Output Open drain
 * 6:Alternate function output push pull
 * 7:Alternate function output open drain
*/
#define GPIO_MODE_Input_analog 				0
#define GPIO_MODE_Input_floating 			1
#define GPIO_MODE_Input_pull_up 			2
#define GPIO_MODE_Input_Pull_down 			3
#define GPIO_MODE_Output_push_pull			4
#define GPIO_MODE_Output_open_drain			5
#define GPIO_MODE_Output_AFIO_push_pull		6
#define GPIO_MODE_Output_AFIO_open_drain	7

/*@ref GPIO_pin_output_speed_define
 * Here are the values of the pins output speed
 * 0: None
 * 1: 10MHZ
 * 2: 2MHZ
 * 3: 50MHZ
*/
#define GPIO_Speed_10MHZ					0b01
#define GPIO_Speed_2MHZ						0b10
#define GPIO_Speed_50MHZ					0b11

/*@ref GPIO_pin_state
 *  Here are the value of pins
 */
#define GPIO_Pin_High						1
#define GPIO_Pin_Low						0


/*@ref GPIO_LOCK_return
 *  Here are the value of pins
 */
#define GPIO_PIN_LOCKED						1
#define GPIO_PIN_NOT_LOCKED					0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_init(GPIO_TypeDef * GPIOx, GPIO_Pin_Config* MyPin_Config);
void MCAL_GPIO_deinit(GPIO_TypeDef * GPIOx);

void MCAL_GPIO_write_port(uint16_t Data,GPIO_TypeDef * GPIOx);
void MCAL_GPIO_write_pin(uint8_t Data,GPIO_TypeDef * GPIOx,uint8_t PinNumber);

uint16_t MCAL_GPIO_read_port(GPIO_TypeDef * GPIOx);
uint8_t MCAL_GPIO_read_pin(GPIO_TypeDef * GPIOx ,uint8_t PinNumber);

void MCAL_GPIO_toggle_pin(GPIO_TypeDef * GPIOx ,uint8_t PinMumber);

uint8_t MCAL_GPIO_lock_pin(GPIO_TypeDef * GPIOx ,uint8_t PinMumber);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */

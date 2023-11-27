/*
 * lcd.h
 *
 * Created: 9/6/2023 1:27:15 PM
 *  Author:  Michel Adel
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL
#include "stm32f103c6_GPIO_driver.h"

//LCD Commands
#define LCD_8_BIT_1_LINE			(0x30)
#define LCD_8_BIT_2_LINES			(0x38)
#define LCD_4_BIT_1_LINE			(0x20)
#define LCD_4_BIT_2_LINES			(0x28)
#define LCD_ENTRY_MODE				(0x06)
#define LCD_DISPLAY_OFF				(0X08)
#define LCD_CURSOR_ON				(0X0E)
#define LCD_CURSOR_OFF_DISPLAY_ON	(0X0C)
#define LCD_CURSOR_BLINKING_ON		(0X0F)
#define LCD_SHILFT_LEFT				(0X18)
#define LCD_SHIFT_RIGHT				(0X1C)
#define LCD_CURSOR_LEFT				(0X10)
#define LCD_CURSOR_RIGHT			(0X14)
#define LCD_CLEAR_SCREEN			(0X01)
#define LCD_CURSOR_FIRST_LINE		(0X80)
#define LCD_CURSOR_SECOND_LINE		(0XC0)
#define LCD_DISP_ON_BLINK   		(0x0D)
#define LCD_ENTRY_DEC   			(0x04)
#define LCD_ENTRY_DEC_SHIFT   		(0x05)
#define LCD_ENTRY_INC_   			(0x06)
#define LCD_ENTRY_INC_SHIFT   		(0x07)

//LCD Connected ports
#define LCD_DATA_PORT GPIOA
#define LCD_CTRL_PORT GPIOA
//#define LCD_DATA_DIRECTION DDRA
//#define LCD_CTRL_DRICETION DDRB

//LCD Pins
#define LCD_RS_PIN 			GPIO_PIN8
#define	LCD_READ_WRITE_PIN 	GPIO_PIN9
#define LCD_ENABLE_PIN 		GPIO_PIN10
#define LCD_BUSY_PIN 		GPIO_PIN7


//LCD Mode
#define LCD_8_BIT_MODE
//#define LCD_4_BIT_MODE
#define DATA_SHIFT 0


//LCD Functions
void lcd_kick(void);
void lcd_init(void);
void lcd_goto_XY(unsigned char line,unsigned char offset);
void lcd_busy(void);
void lcd_write_char(unsigned char my_char);
void lcd_write_string(char* my_char);
void lcd_write_command(unsigned char my_command);
void lcd_clear_screen (void);

#endif /* LCD_H_ */

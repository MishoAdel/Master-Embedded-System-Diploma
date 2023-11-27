/*
 * lcd_keypad.c
 *
 * Created: 9/6/2023 1:24:33 PM
 * Author :  Michel Adel
 */ 



#include "lcd_driver/lcd.h"
#include "keypad_driver/keypad.h"
#include "USART/usart.h"

int main(void)
{
    usart_init();
	lcd_init();
	_delay_ms(50);
	lcd_write_string("Learn in depth : Michel Adel");
	lcd_clear_screen();
	char xy;
	while(1){
		xy=usart_recive_byte();
		lcd_write_char(xy);
	}
}


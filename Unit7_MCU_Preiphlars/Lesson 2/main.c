/*
 * lcd_keypad.c
 *
 * Created: 9/6/2023 1:24:33 PM
 * Author :  Michel Adel
 */ 



#include "lcd_driver/lcd.h"
#include "keypad_driver/keypad.h"


int main(void)
{
    lcd_init();
	Keypad_init();
	_delay_ms(50);
	lcd_write_string("Learn in depth. LCD driver made by Michel Adel");
	unsigned char key_pressed;
	while(1){
		key_pressed = keypad_getchar();
		switch(key_pressed){
			case 'A':
			break;
			case '?':
			lcd_clear_screen();
			break;
			default:
			lcd_write_char(key_pressed);
			break;
		}
	}
}


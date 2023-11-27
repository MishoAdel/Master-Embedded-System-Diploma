/*
 * lcd.c
 *
 * Created: 9/6/2023 1:27:03 PM
 *  Author: Michel Adel 
 */ 

#include "lcd.h"

int count;

void lcd_kick()
{
	LCD_CTRL_PORT |=(1<<LCD_ENABLE_PIN);
	_delay_ms(50);
	LCD_CTRL_PORT &=~(1<<LCD_ENABLE_PIN);
}

void lcd_init(void)
{
	count =0;
	_delay_ms(20);
	LCD_CTRL_DRICETION |= ((1<<LCD_RS_PIN)|(1<<LCD_READ_WRITE_PIN)|(1<<LCD_ENABLE_PIN));
	LCD_CTRL_PORT &= ~((1<<LCD_RS_PIN)|(1<<LCD_READ_WRITE_PIN)|(1<<LCD_ENABLE_PIN));
	LCD_DATA_DIRECTION = 0xFF;
	_delay_ms(15);
	lcd_write_command(LCD_CLEAR_SCREEN);
	#ifdef LCD_8_BIT_MODE
		lcd_write_command(LCD_8_BIT_2_LINES);
	#endif
	#ifdef LCD_4_BIT_MODE
		lcd_write_command(0x02);
		lcd_write_command(LCD_4_BIT_2_LINES);
	#endif
	lcd_write_command(LCD_ENTRY_MODE);
	lcd_write_command(LCD_CURSOR_FIRST_LINE);
	lcd_write_command(LCD_CURSOR_BLINKING_ON);
}

void lcd_goto_XY(unsigned char line,unsigned char offset)
{
	if (line == 1)
	{
		if (offset < 16 && offset >= 0)
		{
			lcd_write_command(LCD_CURSOR_FIRST_LINE+offset);
		}
	}
	if (line == 2)
	{
		if (offset < 16 && offset >= 0)
		{
			lcd_write_command(LCD_CURSOR_SECOND_LINE+offset);
		}
	}
}


void lcd_busy(void)
{
	LCD_DATA_DIRECTION &=~(0xff<<DATA_SHIFT);
	LCD_CTRL_PORT |= (1<<LCD_READ_WRITE_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);
	//while(LCD_DATA_PORT >= 0x80){
		lcd_kick();	
	//}
	LCD_DATA_DIRECTION = (0xFF<<DATA_SHIFT);
	LCD_CTRL_PORT &= ~(1<<LCD_READ_WRITE_PIN);
}

void lcd_write_char(unsigned char my_char)
{
	if(count == 16)
	{
		lcd_goto_XY(2,0);
	}
	else if(count==32)
	{
		lcd_write_command(LCD_CLEAR_SCREEN);
		lcd_goto_XY(1,0);
		count =0;
	}
	count++;
	#ifdef LCD_8_BIT_MODE
	lcd_busy();
	LCD_CTRL_PORT |=(1<<LCD_RS_PIN); 
	LCD_DATA_PORT =(my_char<<DATA_SHIFT);
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	lcd_kick();
	#endif
	
	#ifdef LCD_4_BIT_MODE
	lcd_busy();
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_char & 0xF0);
	LCD_CTRL_PORT |=(1<<LCD_RS_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	lcd_kick();
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_char << DATA_SHIFT);
	LCD_CTRL_PORT |=(1<<LCD_RS_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	lcd_kick();
	#endif
}

void lcd_write_string(char* my_char)
{
	while((*(my_char)) != '\0')
	{
		lcd_write_char(*my_char);
		if(count == 16)
		{
			lcd_goto_XY(2,0);
		}
		else if(count==32)
		{
			lcd_write_command(LCD_CLEAR_SCREEN);
			lcd_goto_XY(1,0);
			count =0;
		}
		my_char++;
	}
}
void lcd_write_command(unsigned char my_command)
{
	#ifdef LCD_8_BIT_MODE
	lcd_busy();
	LCD_DATA_PORT =my_command;
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);
	lcd_kick();
	#endif
	
	#ifdef LCD_4_BIT_MODE
	lcd_busy();
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_command & 0xF0);
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);
	lcd_kick();
	LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_command << DATA_SHIFT);
	LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);
	LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);
	lcd_kick();
	#endif
}
void lcd_clear_screen (void)
{
	lcd_write_command(LCD_CLEAR_SCREEN);
}

/*
 * lcd.c
 *
 * Created: 9/6/2023 1:27:03 PM
 *  Author: Michel Adel 
 */ 

#include "lcd.h"

int count;
GPIO_Pin_Config My_LCD_Config;

void lcd_gpio_init()
{
		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=LCD_RS_PIN;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=LCD_READ_WRITE_PIN;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=LCD_ENABLE_PIN;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);
		//LCD_CTRL_DRICETION |= ((1<<LCD_RS_PIN)|(1<<LCD_READ_WRITE_PIN)|(1<<LCD_ENABLE_PIN));


		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN0;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN1;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN2;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN3;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN4;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN5;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN6;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

		My_LCD_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
		My_LCD_Config.Pin_Num=GPIO_PIN7;
		My_LCD_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
		MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);
		//LCD_DATA_DIRECTION = 0xFF;

		MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_ENABLE_PIN);
		MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_RS_PIN);
		MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN);
		//LCD_CTRL_PORT &= ~((1<<LCD_RS_PIN)|(1<<LCD_READ_WRITE_PIN)|(1<<LCD_ENABLE_PIN));
}

void lcd_clear_screen (void)
{
	lcd_write_command(LCD_CLEAR_SCREEN);
}


void lcd_kick()
{
	MCAL_GPIO_write_pin(GPIO_Pin_High, LCD_CTRL_PORT, LCD_ENABLE_PIN);
	//LCD_CTRL_PORT |=(1<<LCD_ENABLE_PIN);
	wait_ms(50);
	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_ENABLE_PIN);
	//LCD_CTRL_PORT &=~(1<<LCD_ENABLE_PIN);
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

void lcd_init(void)
{
	count =0;
	wait_ms(20);

	lcd_gpio_init();

	wait_ms(15);
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

void lcd_busy(void)
{

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN0;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN1;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN2;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN3;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN4;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN5;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN6;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);

	My_LCD_Config.Pin_Mode=GPIO_MODE_Input_floating;
	My_LCD_Config.Pin_Num=GPIO_PIN7;
	My_LCD_Config.Pin_Out_speed=0;
	MCAL_GPIO_init(LCD_CTRL_PORT, &My_LCD_Config);
	//LCD_DATA_DIRECTION &=~(0xff<<DATA_SHIFT);


	MCAL_GPIO_write_pin(GPIO_Pin_High, LCD_CTRL_PORT, LCD_READ_WRITE_PIN);
	//LCD_CTRL_PORT |= (1<<LCD_READ_WRITE_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_RS_PIN);
	//LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);
	//while(LCD_DATA_PORT >= 0x80){
	lcd_kick();
	//}

	//LCD_DATA_DIRECTION = (0xFF<<DATA_SHIFT);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN);
	//LCD_CTRL_PORT &= ~(1<<LCD_READ_WRITE_PIN);
}

void lcd_write_command(unsigned char my_command)
{
#ifdef LCD_8_BIT_MODE
	//lcd_busy();

	MCAL_GPIO_write_port(my_command, LCD_DATA_PORT);
	//LCD_DATA_PORT =my_command;

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_RS_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);

	wait_ms(1);
	lcd_kick();
#endif

#ifdef LCD_4_BIT_MODE

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_RS_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);

	MCAL_GPIO_write_port(my_command & 0xF0 , LCD_DATA_PORT );

	//LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_command & 0xF0);
	lcd_kick();

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_RS_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_RS_PIN);

	MCAL_GPIO_write_port( (my_command  << DATA_SHIFT) , LCD_DATA_PORT );
	//LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_command << DATA_SHIFT);

	lcd_kick();

#endif

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

	MCAL_GPIO_write_port(my_char, LCD_DATA_PORT);
	//LCD_DATA_PORT =(my_char<<DATA_SHIFT);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN);
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_High, LCD_CTRL_PORT, LCD_RS_PIN);
	//LCD_CTRL_PORT |=(1<<LCD_RS_PIN);

	wait_ms(1);

	lcd_kick();
#endif

#ifdef LCD_4_BIT_MODE

	lcd_busy();

	MCAL_GPIO_write_port(my_char & 0xF0 , LCD_DATA_PORT );
	//LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_char & 0xF0);

	MCAL_GPIO_write_pin(GPIO_Pin_High, LCD_CTRL_PORT, LCD_RS_PIN );
	//LCD_CTRL_PORT |=(1<<LCD_RS_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

	lcd_kick();

	MCAL_GPIO_write_port((my_char & << DATA_SHIFT) & 0X0F , LCD_DATA_PORT );
	//LCD_DATA_PORT =(LCD_DATA_PORT & 0x0F) | (my_char << DATA_SHIFT);

	MCAL_GPIO_write_pin(GPIO_Pin_High, LCD_CTRL_PORT, LCD_RS_PIN );
	//LCD_CTRL_PORT |=(1<<LCD_RS_PIN);

	MCAL_GPIO_write_pin(GPIO_Pin_Low, LCD_CTRL_PORT, LCD_READ_WRITE_PIN );
	//LCD_CTRL_PORT &=~(1<<LCD_READ_WRITE_PIN);

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


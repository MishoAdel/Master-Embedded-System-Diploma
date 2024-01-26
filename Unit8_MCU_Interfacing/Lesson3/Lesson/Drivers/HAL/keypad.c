/*
 * keypad.c
 *
 * Created: 9/6/2023 6:05:26 PM
 *  Author: Michel Adel
 */ 

#include "keypad.h"


int Key_padRow[] = {R0_PIN, R1_PIN, R2_PIN, R3_PIN}; 
int Key_padCol[] = {C0_PIN, C1_PIN, C2_PIN, C3_PIN};

void Keypad_init(){

	GPIO_Pin_Config My_Keypad_Config;

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=R0_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=R1_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=R2_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=R3_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);
	//KEPAD_DIRECTION &= ~((1 << R0_PIN) | (1 << R1_PIN) | (1 << R2_PIN) | (1 << R3_PIN));


	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=C0_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=C1_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=C2_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);

	My_Keypad_Config.Pin_Mode=GPIO_MODE_Output_push_pull;
	My_Keypad_Config.Pin_Num=C3_PIN;
	My_Keypad_Config.Pin_Out_speed=GPIO_Speed_10MHZ;
	MCAL_GPIO_init(KEYPAD_PORT, &My_Keypad_Config);
	//KEPAD_DIRECTION |= ((1 << C0_PIN) | (1 << C1_PIN) | (1 << C2_PIN) | (1 << C3_PIN));

	MCAL_GPIO_write_port(0xFF, KEYPAD_PORT);
	//KEYPAD_PORT = 0xFF;
}

char keypad_getchar(){
	int i,j;
	for (i = 0; i < 4; i++){

		MCAL_GPIO_write_pin(GPIO_Pin_High, KEYPAD_PORT, Key_padCol[0] );
		MCAL_GPIO_write_pin(GPIO_Pin_High, KEYPAD_PORT, Key_padCol[1] );
		MCAL_GPIO_write_pin(GPIO_Pin_High, KEYPAD_PORT, Key_padCol[2] );
		MCAL_GPIO_write_pin(GPIO_Pin_High, KEYPAD_PORT, Key_padCol[3] );
		//KEYPAD_PORT |= ((1<<Key_padCol[0]) | (1<<Key_padCol[1]) | (1<<Key_padCol[2]) | (1<<Key_padCol[3]));

		MCAL_GPIO_write_pin(GPIO_Pin_Low, KEYPAD_PORT, Key_padCol[i] );
		//KEYPAD_PORT &= ~(1<<Key_padCol[i]);
		for(j = 0; j < 4; j++){
			if (MCAL_GPIO_read_pin(KEYPAD_PORT, Key_padRow[j] )==0)
			{
				while(MCAL_GPIO_read_pin(KEYPAD_PORT, Key_padRow[j] )==0);
				switch(i){
				case 0:
													if (j == 0) return '7';
													else if (j == 1) return '4';
													else if (j == 2) return '1';
													else if (j == 3) return '?';
													break;
				case 1:
													if (j == 0) return '8';
													else if (j == 1) return '5';
													else if (j == 2) return '2';
													else if (j == 3) return '0';
													break;
				case 2:
													if (j == 0) return '9';
													else if (j == 1) return '6';
													else if (j == 2) return '3';
													else if (j == 3) return '=';
													break;
				case 3:
													if (j == 0) return '/';
													else if (j == 1) return '*';
													else if (j == 2) return '-';
													else if (j == 3) return '+';
													break;
				}
			}
		}
	}
	return 'A';
}

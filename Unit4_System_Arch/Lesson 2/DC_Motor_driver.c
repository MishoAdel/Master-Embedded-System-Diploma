/*
 * DC_Motor_driver.c
 *
 *  Created on: Jul 28, 2023
 *      Author: mesho
 */


#include"DC_Motor_driver.h"
#include"state.h"
\
static int DC_speed =0;

void (* DC_P_state)();

void DC_init(){
	printf("DC_init\n");
}

void DC_motor(int s){
	DC_speed=s;
	DC_P_state =STATE(DC_busy);
	printf("CA -> -> -> DC DC_motor() \n");
}

STATE_define(DC_idle)
{
	DC_state=DC_idle_state;
	DC_P_state=STATE(DC_idle);
	printf("DC_idle state : speed %d \n \n \n",DC_speed);
}

STATE_define(DC_busy)
{
	DC_state=DC_busy_state;
	DC_P_state=STATE(DC_idle);
	printf("DC_busy state : speed %d \n \n \n",DC_speed);
}

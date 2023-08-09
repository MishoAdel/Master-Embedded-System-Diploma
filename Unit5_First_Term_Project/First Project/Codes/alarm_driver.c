/*
 * alarm_driver.c
 *
 *  Created on: Aug 4, 2023
 *      Author: mesho
 */

#include "alarm_driver.h"

int alarm_state;

void timer_state(){
	alarm_state=high_pressure_detect();
	Set_Alarm_actuator(alarm_state);
	Delay(10000);
	Set_Alarm_actuator(1);

}

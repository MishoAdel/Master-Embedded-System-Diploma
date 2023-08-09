/*
 * main.c
 *
 *  Created on: Aug 4, 2023
 *      Author: mesho
 */
#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "high_pressure_detector.h"
#include "alarm_driver.h"
#include "sensor_driver.h"


int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
		pressure_sensor_read();
		read_from_sensor();
		timer_state();
	}
	return 0;
}



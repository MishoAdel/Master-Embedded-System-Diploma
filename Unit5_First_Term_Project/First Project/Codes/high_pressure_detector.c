/*
 * high_pressure_detector.c
 *
 *  Created on: Aug 4, 2023
 *      Author: mesho
 */

#include "high_pressure_detector.h"
#include "sensor_driver.h"


int sys_pressure=0;
int limit=50;
extern int pressure_val;

void read_from_sensor(){
	sys_pressure=pressure_val;
}

int high_pressure_detect(){
	if(sys_pressure<=limit)
		return 1;
	else
		return 0;
}



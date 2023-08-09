/*
 * sensor_driver.c
 *
 *  Created on: Aug 4, 2023
 *      Author: mesho
 */

#include "sensor_driver.h"

int pressure_val;

void pressure_sensor_read(){
	pressure_val=getPressureVal();
}

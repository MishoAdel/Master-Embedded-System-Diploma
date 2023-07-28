/*
 * DC_Motor_driver.h
 *
 *  Created on: Jul 28, 2023
 *      Author: mesho
 */

#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_

#include "state.h"

enum{
	DC_idle_state,
	DC_busy_state
}DC_state;


STATE_define(DC_idle);

STATE_define(DC_busy);

void DC_init();
extern void (*DC_P_state)();

#endif /* DC_MOTOR_DRIVER_H_ */

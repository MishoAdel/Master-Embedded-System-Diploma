/*
 * state.h
 *
 *  Created on: Jul 28, 2023
 *      Author: mesho
 */

#ifndef STATE_H_
#define STATE_H_

#include"stdio.h"
#include"stdlib.h"

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()

#define STATE(_stateFunc_) ST_##_stateFunc_

#include<stdio.h>
#include<stdlib.h>

void US_distance_set(int dist);
void DC_motor(int s);

#endif /* STATE_H_ */

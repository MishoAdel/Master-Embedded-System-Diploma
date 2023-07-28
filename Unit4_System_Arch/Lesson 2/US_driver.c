/*
 * US_driver.c
 *
 *  Created on: Jul 28, 2023
 *      Author: mesho
 */
#include "US_driver.h"
#include"state.h"

extern void (* US_P_state)();
unsigned int US_distance=0;

int randomnum(int l,int r,int count)
{
	int i,x;
	for(i=0;i<count;i++){
		x=(rand()% (r-l+1))+l;
	}
		return x;
}

void US_init()
{
	printf("US_init");
}
STATE_define(US_busy)
{
	US_state=US_busy_state;
	US_distance=randomnum(45,55,1);
	printf("US Sensor busy state -> distance = %d\n",US_distance);
	US_distance_set(US_distance);
	US_P_state=STATE(US_busy);

}

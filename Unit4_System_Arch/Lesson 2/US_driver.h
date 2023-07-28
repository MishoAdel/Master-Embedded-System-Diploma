
#ifndef US_DRIVER_H_
#define US_DRIVER_H_

enum{
	US_busy_state
}US_state;

void US_init();

STATE_define(US_busy);

int randomnum(int l,int r,int count);

void (* US_P_state)();


#endif /* US_DRIVER_H_ */

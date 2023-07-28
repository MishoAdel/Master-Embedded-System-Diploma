
#ifndef CA_H_
#define CA_H_

#include"state.h"

enum{
	CA_waiting_state,
	CA_driving_state
}CA_state;

STATE_define(CA_waiting);
STATE_define(CA_driving);


void (* CA_P_state)();


#endif /* CA_H_ */

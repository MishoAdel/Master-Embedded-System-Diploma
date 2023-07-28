#include "CA.h"
#include "state.h"

static int CA_distance=0;
static int CA_speed=0;
static int CA_limit=50;

void (* CA_P_state)();

void US_distance_set(int dist){
	CA_distance=dist;
	(CA_distance<=CA_limit)?(CA_P_state=STATE(CA_waiting)):(CA_P_state=STATE(CA_driving));
}

STATE_define(CA_waiting)
{
	CA_state=CA_waiting_state;
		CA_speed=0;
	printf("CA waiting state-------Distance =%d--------> speed=%d\n",CA_distance,CA_speed);
		DC_motor(CA_speed);
}
STATE_define(CA_driving)
{
	CA_state=CA_driving_state;
	CA_speed=30;
	printf("CA driving state-------Distance =%d--------> speed=%d\n",CA_distance,CA_speed);
	DC_motor(CA_speed);
}

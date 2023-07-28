# include "CA.h"
# include "US_driver.h"
# include "DC_Motor_driver.h"
#include"state.h"

void setup(){
	US_init();
	DC_init();
	printf("\n");

	US_P_state=STATE(US_busy);
	CA_P_state=STATE(CA_waiting);
	DC_P_state=STATE(DC_idle);
}

int main(){
	setup();
	int n=15;

	while(n--){
		US_P_state();
		CA_P_state();
		DC_P_state();
	}
}

#include "stdint.h"
#define STACK_POINTER 0x20001000
extern int main(void);
void Rest_Handler(void){
	main();
}
void NMI_Handeler(void){
	Rest_Handler();
}
void H_Fault_Handler(void){
	Rest_Handler();
}
void MM_Fault_Handler(void){
	Rest_Handler();
}
void Bus_Fault(void){
	Rest_Handler();
}
void Usage_Fault_Handler(void){
	Rest_Handler();
}


uint32_t vectors[] __attribute__((section(".vectors")))  = {
	STACK_POINTER,
	(uint32_t) &Rest_Handler,
	(uint32_t) &NMI_Handeler ,
	(uint32_t) &H_Fault_Handler ,
	(uint32_t) &MM_Fault_Handler ,
	(uint32_t) &Bus_Fault ,
	(uint32_t) &Usage_Fault_Handler
};
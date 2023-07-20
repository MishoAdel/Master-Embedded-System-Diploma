#include "stdint.h"
#define STACK_POINTER 0x20001000

void Rest_Handler(void);
extern int main(void);

void Default_Handler()
{
	Rest_Handler();
}
void NMI_Handeler()__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void MM_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault()__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;

static unsigned long Stack_size[256];

void (* const Arr_Pn_tFun [])()__attribute__((section(".vectors")))=
{
	(void (*)())((unsigned long)Stack_size+ sizeof(Stack_size)),
	&Rest_Handler,
	&NMI_Handeler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler
};

extern unsigned int _E_text ;
extern unsigned int _S_Data ;
extern unsigned int _E_Data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Rest_Handler(){
	unsigned int Data_Size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data ;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_Data ;
	for(int i=0; i<Data_Size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	
	unsigned int bss_Size = (unsigned char*)_E_bss - (unsigned char*) _S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(int i=0; i<Data_Size;i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	main();
}
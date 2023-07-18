#include <stdint.h>

#define BASE_RCC 0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR	*(volatile uint32_t *) (BASE_RCC + 0x18)
#define GPIO_CRH	*(volatile uint32_t *) (PortA_BASE + 0x04)
#define GPIO_ODR	*(volatile uint32_t *) (PortA_BASE + 0x0C)

int i;
int main(void)
{
	RCC_APB2ENR |= 1<<2 ;
	GPIO_CRH &= 0xff0fffff ;
	GPIO_CRH |= 0x00200000 ;
	while(1)
	{
		GPIO_ODR |= 1<<13 ;
		for(i=0;i<5000;i++);
		GPIO_ODR &= ~(1<<13) ;
		for(i=0;i<5000;i++);
	}
	return 0;
}

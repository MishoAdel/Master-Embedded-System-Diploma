#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stdint.h"

#define RCC_BASE 0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

#define GPIOA_BASE 0x40010800
#define GPIOA_CRL *(volatile uint32_t *)( GPIOA_BASE + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)( GPIOA_BASE + 0x04)
#define GPIOA_IDR *(volatile uint32_t *)( GPIOA_BASE + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)( GPIOA_BASE + 0x0C)

#define GPIOB_BASE 0x40010C00
#define GPIOB_CRL *(volatile uint32_t *)( GPIOB_BASE + 0x00)
#define GPIOB_CRH *(volatile uint32_t *)( GPIOB_BASE + 0x04)
#define GPIOB_IDR *(volatile uint32_t *)( GPIOB_BASE + 0x08)
#define GPIOB_ODR *(volatile uint32_t *)( GPIOB_BASE + 0x0C)


void clock_init()
{
	RCC_APB2ENR |=(1<<2);
	RCC_APB2ENR |=(1<<3);
}

void gpio_init()
{
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_ODR = 0;

	GPIOA_CRL &= ~(0b11<<4);
	GPIOA_CRL |= (0b01<<6);

	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);

	GPIOB_CRL = 0;
	GPIOB_CRH = 0;
	GPIOB_ODR = 0;

	GPIOB_CRL |=(0b01<<4);
	GPIOB_CRL &= ~(0b11<<6);

	GPIOB_CRH |=(0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);
}

void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}

int main(void)
{
	clock_init();
	gpio_init();
	while(1)
	{
		if (((GPIOA_IDR & (1<<1)) >> 1)==0)
		{
			GPIOB_ODR ^= 1<<1;
			while (((GPIOA_IDR & (1<<1)) >> 1 == 0));
		}
		if (((GPIOA_IDR & (1<<13)) >> 13) == 1)
		{
			GPIOB_ODR ^= 1<<13;
		}
		wait_ms(50);
	}
}

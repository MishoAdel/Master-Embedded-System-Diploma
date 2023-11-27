/*
 * seven_seg.h
 *
 *  Created on: Sep 28, 2023
 *      Author: mesho
 */

#ifndef INC_SEVEN_SEG_H_
#define INC_SEVEN_SEG_H_

#include "stm32f103c6_GPIO_driver.h"
#include "stm32f103xx.h"

GPIO_Pin_Config My_7seg_config;

#define ZERO 	0x01
#define ONE 	0x79
#define TWO 	0x24
#define THREE 	0x30
#define FOUR 	0x4C
#define FIVE 	0x12
#define SIX 	0x02
#define SEVEN 	0x19
#define EIGHT 	0x00
#define NINE 	0x10

/* ============= Functions Prototypes ============ */
void seven_segment_init(void);

#endif /* INC_SEVEN_SEG_H_ */

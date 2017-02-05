/*
 * Joistick.h
 *
 *  Created on: 5 февр. 2017 г.
 *      Author: gray
 */

#ifndef JOISTICK_H_
#define JOISTICK_H_

#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_adc.h"

void AdcInit(void);
uint16_t JoystickGetX(void);

#endif /* JOISTICK_H_ */

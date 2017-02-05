/*
 * LedPwm.h
 *
 *  Created on: 5 февр. 2017 г.
 *      Author: gray
 */

#ifndef LEDPWM_H_
#define LEDPWM_H_

#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_tim.h"

void LedPwmInit(void);
void SetPwmFreq(int freq);
void OffPwm(void);

#endif /* LEDPWM_H_ */

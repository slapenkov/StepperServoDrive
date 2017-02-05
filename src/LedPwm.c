/*
 * LedPwm.c
 *
 *  Created on: 5 февр. 2017 г.
 *      Author: gray
 */

#include "LedPwm.h"

/*
 * Led PWM initialization
 * */
void LedPwmInit() {

	//GPIO init
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitTypeDef gpioStructure;
	gpioStructure.GPIO_Pin = GPIO_Pin_5;
	gpioStructure.GPIO_Mode = GPIO_Mode_AF;
	gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
	gpioStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &gpioStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_2);

	//Timer init
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef timerInitStructure;
	timerInitStructure.TIM_Prescaler = (uint16_t) ((SystemCoreClock / 200000))
			- 1;
	timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	timerInitStructure.TIM_Period = 200;
	timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//timerInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &timerInitStructure);

	//pwm channels init
	TIM_OCInitTypeDef outputChannelInit;
	outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
	outputChannelInit.TIM_Pulse = 0;
	outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
	outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM2, &outputChannelInit);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_Cmd(TIM2, ENABLE);

}

/*
 * Set PWM Frequency in Hz
 * */
void SetPwmFreq(int freq) {
	TIM_PrescalerConfig(TIM2, (uint16_t) ((SystemCoreClock /(200* freq))) - 1,
	TIM_PSCReloadMode_Immediate);
	TIM2->CCR1 = 100;

}

/*
 * Off PWM
 * */
void OffPwm() {
	TIM2->CCR1 = 0;
}

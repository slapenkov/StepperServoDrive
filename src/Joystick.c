/*
 * Joistick.c
 *
 *  Created on: 5 февр. 2017 г.
 *      Author: gray
 */

#include "Joystick.h"

/*
 * Initialize adc
 * */
void AdcInit() {
	/* GPIOC Periph clock enable */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

	GPIO_InitTypeDef gpioStructure;
	gpioStructure.GPIO_Pin = GPIO_Pin_1;
	gpioStructure.GPIO_Mode = GPIO_Mode_AN;
	gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
	gpioStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &gpioStructure);

	ADC_InitTypeDef ADC_InitStructure;

	/* ADC1 Peripheral clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* ADCs DeInit */
	ADC_DeInit(ADC1);

	/* Initialize ADC structure */
	ADC_StructInit(&ADC_InitStructure);

	/* Configure the ADC1 in continuous mode with a resolution equal to 12 bits  */
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge =
	ADC_ExternalTrigConvEdge_Rising;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC4;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
	ADC_Init(ADC1, &ADC_InitStructure);

	/* Convert the ADC1 Channel 11 with 239.5 Cycles as sampling time */
	ADC_ChannelConfig(ADC1, ADC_Channel_1, ADC_SampleTime_1_5Cycles);

	/* ADC Calibration */
	ADC_GetCalibrationFactor(ADC1);

	/* Enable the ADC peripheral */
	ADC_Cmd(ADC1, ENABLE);

	/* Wait the ADRDY flag */
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY))
		;

	/* ADC1 regular Software Start Conv */
	ADC_StartOfConversion(ADC1);
}

/*
 *
 * */
uint16_t JoystickGetX() {

	/* Test EOC flag */
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
		;

	/* Get ADC1 converted data */

	return ADC_GetConversionValue(ADC1);
}

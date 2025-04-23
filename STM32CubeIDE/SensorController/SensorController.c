/*
 * SensorController.c
 *
 *  Created on: Apr 16, 2025
 *      Author: user
 */

#include "SensorController.h"



stSensorController_t* sensorController_getInstance(void);
static void sensorController_init(stSensorController_t*me);

stSensorController_t* sensorController_init(void)
{
	stSensorController_t* me = sensorController_getInstance();

    me->reedSwitchState         = SENSOR_STATE_OFF;
    me->motionSensorState       = SENSOR_STATE_OFF;
    me->panicButtonState        = SENSOR_STATE_OFF;
    me->rainSensorDigitalState  = SENSOR_STATE_OFF;
    me->gasSensorAnalogValue    = 0;
    me->rainSensorAnalogValue   = 0;
    me->temperature             = 0;
    me->humidity                = 0;
    me->sensorUpdateTimer       = HAL_GetTick();
    me->sensorUpdateFlag        = false;
}


void sensorController_eventloop(stSensorController_t* me)
{
    if ((HAL_GetTick() - me->sensorUpdateTimer) >= 1000)
    {
        me->sensorUpdateTimer = HAL_GetTick();
        me->sensorUpdateFlag = true;

        me->reedSwitchState        = readDigitalSensor(REED_SWITCH_GPIO_Port, REED_SWITCH_Pin);
        me->motionSensorState      = readDigitalSensor(MOTION_SENSOR_GPIO_Port,MOTION_SENSOR_Pin );
        me->panicButtonState       = readDigitalSensor(PANIC_BUTTON_GPIO_Port, PANIC_BUTTON_Pin);
        me->rainSensorDigitalState = readDigitalSensor(RAIN_SENSOR_D_GPIO_Port, RAIN_SENSOR_D_Pin);

       /* me->gasSensorAnalogValue   = readAnalogSensor(&hadc1, ADC_CHANNEL_4);
        me->rainSensorAnalogValue  = readAnalogSensor(&hadc1, ADC_CHANNEL_5);
   */ }
    else
    {
        me->sensorUpdateFlag = false;
    }
}

eSensorState_t readDigitalSensor(GPIO_TypeDef* port, uint16_t pin)
{
	if (HAL_GPIO_ReadPin(port,pin) == GPIO_PIN_SET)
		return SENSOR_STATE_ON;
	else
		return SENSOR_STATE_OFF;
}

/*
uint16_t readAnalogSensor(ADC_HandleTypeDef* hadc, uint32_t channel)
{
	  ADC_ChannelConfTypeDef sConfig = {0};

	    sConfig.Channel = channel;
	    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
	    sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;

	    HAL_ADC_ConfigChannel(hadc, &sConfig);

	    HAL_ADC_Start(hadc);
	    HAL_ADC_PollForConversion(hadc, 10);
	    uint16_t value = HAL_ADC_GetValue(hadc);
	    HAL_ADC_Stop(hadc);
}
*/

stSensorController_t* sensorController_getInstance(void)
{
	static stSensorController_t sensorInstance;
	static stSensorController_t* me = NULL;
	if(NULL == me){

    return &sensorInstance;
	}
}

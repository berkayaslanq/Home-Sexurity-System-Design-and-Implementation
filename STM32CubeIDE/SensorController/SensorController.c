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

        me->gasSensorAnalogValue   = readAnalogSensor(&hadc1, ADC_CHANNEL_4);
        me->rainSensorAnalogValue  = readAnalogSensor(&hadc1, ADC_CHANNEL_5);
    }
    else
    {
        me->sensorUpdateFlag = false;
    }
}

stSensorController_t* sensorController_getInstance(void)
{
	static stSensorController_t sensorInstance;
	static stSensorController_t* me = NULL;
	if(NULL == me){

    return &sensorInstance;
	}
}

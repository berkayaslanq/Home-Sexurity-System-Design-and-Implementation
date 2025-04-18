/*
 * SensorController.h
 *
 *  Created on: Apr 16, 2025
 *      Author: user
 */

#ifndef SENSORCONTROLLER_SENSORCONTROLLER_H_
#define SENSORCONTROLLER_SENSORCONTROLLER_H_

#include "main.h"

typedef struct
{
    eSensorState_t reedSwitchState;
    eSensorState_t motionSensorState;
    eSensorState_t panicButtonState;
    eSensorState_t rainSensorDigitalState;

    uint16_t gasSensorAnalogValue;
    uint16_t rainSensorAnalogValue;

    uint8_t temperature;
    uint8_t humidity;

    uint32_t sensorUpdateTimer;
    _Bool sensorUpdateFlag;

} stSensorController_t;

stSensorController_t* sensorController_init(void);
void sensorController_eventloop(stSensorController_t* me);

#endif

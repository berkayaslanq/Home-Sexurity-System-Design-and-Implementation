/*
 * RS485Controller.h
 *
 *  Created on: Apr 22, 2025
 *      Author: user
 */

#ifndef RS485CONTROLLER_RS485CONTROLLER_H_
#define RS485CONTROLLER_RS485CONTROLLER_H_

#include "main.h"

void RS485Controller_init(void);
void RS485Controller_send(uint8_t* data, uint16_t size);

typedef struct
{
    uint8_t header;
    uint8_t reedSwitch;
    uint8_t motionSensor;
    uint8_t panicButton;
    uint8_t rainDigital;
    uint16_t gasAnalog;
    uint16_t rainAnalog;
    uint8_t checksum;
    uint8_t footer;
} __attribute__((packed)) SensorPacket_t;

void RS485Controller_init(void);
void RS485Controller_send(uint8_t* data, uint16_t size);
void RS485Controller_sendSensorPacket(SensorPacket_t* packet);


#endif /* RS485CONTROLLER_RS485CONTROLLER_H_ */

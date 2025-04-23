/*
 * RS485Controller.c
 *
 *  Created on: Apr 22, 2025
 *      Author: user
 */
#include "RS485Controller.h"



uint8_t calculateChecksum(uint8_t* data, uint8_t size)
{
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < size; i++)
    {
        checksum ^= data[i];
    }
    return checksum;
}

void RS485Controller_sendSensorPacket(SensorPacket_t* packet)
{
    packet->header = 0xAA;
    packet->footer = 0x55;

    packet->checksum = calculateChecksum((uint8_t*)packet, sizeof(SensorPacket_t) - 2);

    RS485Controller_send((uint8_t*)packet, sizeof(SensorPacket_t));
}

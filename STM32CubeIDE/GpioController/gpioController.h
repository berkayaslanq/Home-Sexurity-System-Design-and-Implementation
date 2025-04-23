/*
 * gpioController.h
 *
 *  Created on: Apr 17, 2025
 *      Author: user
 */

#ifndef GPIOCONTROLLER_GPIOCONTROLLER_H_
#define GPIOCONTROLLER_GPIOCONTROLLER_H_
/*
void gpioController_setPin(GPIO_TypeDef* port, uint16_t pin);
void gpioController_resetPin(GPIO_TypeDef* port, uint16_t pin);
void gpioController_togglePin(GPIO_TypeDef* port, uint16_t pin);
GPIO_PinState gpioController_readPin(GPIO_TypeDef* port, uint16_t pin);
*/
//?????? YUKARIDAKİ KISIMDAN HİÇ Mİ HİÇ EMİN DEĞİLİM

typedef struct
{
	I2C_HandleTypeDef* i2cGpio;
	uint16_t address;

	//uint8_t gpioOutputA;
	//uint8_t gpioOutputB;
	//BURADAN DA EMİN DEĞİLİM?????

	HAL_StatusTypeDef errFlg1;
	HAL_StatusTypeDef errFlg2;


} stGpioController_t;

stGpioController_t* gpioController_init(I2C_HandleTypeDef* i2cGpio);
void gpioController_eventloop(stGpioController_t* me);

#endif /* GPIOCONTROLLER_GPIOCONTROLLER_H_ */

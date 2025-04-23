/*
 * gpioController.c
 *
 *  Created on: Apr 17, 2025
 *      Author: user
 */
#include "gpioController.h"
static stGpioController_t gpioInstance;

stGpioController_t* gpioController_init()
{

}

void gpioController_eventloop(stGpioController_t* me)
{


}
/*
void gpioController_setPin(GPIO_TypeDef* port, uint16_t pin){

	HAL_GPIO_WritePin(port, GPIO_PIN_SET);
}

void gpioController_resetPin(GPIO_TypeDef* port, uint16_t pin)
{
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
}

void gpioController_togglePin(GPIO_TypeDef* port, uint16_t pin)
{
    HAL_GPIO_TogglePin(port, pin);
}

GPIO_PinState gpioController_readPin(GPIO_TypeDef* port, uint16_t pin)
{
    return HAL_GPIO_ReadPin(port, pin);
}
*/


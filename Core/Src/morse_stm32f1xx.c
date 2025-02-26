#include "morse.h"
#include "stm32f1xx_hal.h"

/* Implementation Specific */
void morse_led_on(){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}

void morse_led_off(){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}

void morse_delay(int delay_time_ms){
    HAL_Delay(delay_time_ms);
}

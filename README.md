For STMCUBE IDE

Workaround for SD Card Initialization. Forces Reset after first failure.

Based on [this post](https://microcontrollerslab.com/microsd-card-module-stm32-blue-pill-stm32cubeide/)

Pinout:

| SD Card | STM32 Blue PIll |
| ------- |:---------------:|
| CS      | PA4 (GPIO)      |
| MOSI    | PA7(SPI1_MOSI)  |
| SCK     | PA6(SPI1_SCK)   |
| MISO    | PA6(SPI1_MISO)  |

# ARM Drivers

This repository contains a collection of drivers for the STM32F401 microcontroller. These drivers provide an abstraction layer to interact with various peripherals and functionalities of the STM32F401.

## Introduction
The STM32F401 Driver Library is designed to simplify the development process for projects based on the STM32F401 microcontroller. It provides a set of drivers that encapsulate the low-level details of interacting with various peripherals, allowing developers to focus on higher-level functionality.
![D_NQ_NP_649840-MLM44508862342_012021-O](https://github.com/Islam-Alabassy/ARM_Drivers/assets/149616454/0ae0d989-2f34-47c9-82f2-87cc7280d6e3)
*STM32F401 MCU*
## Supported Peripherals
The STM32F401 Drivers Repo currently supports the following peripherals:

#### In MCAL Layer :
-  GPIO (General Purpose Input/Output)
- RCC
- UART (Universal Asynchronous Receiver/Transmitter)
- FMI 
- NVIC
- ADC (Analog-to-Digital Converter)
- STK
#### LIB Layer
- STD_TYPES
- BIT_MATH
### In SERVICE Layer :
- Hex Parser
- Bootloader Services


Each **peripheral driver** provides functions to initialize, configure, and utilize the corresponding peripheral.

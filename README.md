#  STM32F030RTC6 API (Mechatronic Sytems API)
### INSPIRED BY RETIRING [MBED API](https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html)


## Table of Contents
- [Overview](#Overview)
- [Prerequisites](#Prerequisites)
- [Installation](#Installation)
- [Configuration](#Configuration)
- [API-Usage-Examples](#API Usage Examples)
- [Collaboration](#Collaboration)
- [License](#License)

  ## Overview
  This repository (mechasys) provides an abstraction layer for the STM32F030RTC6 microcontroller,
  simplifying hardware interaction for undergraduate students for learning embedded systems.
  The API includes modules for digital I/O, analog input, and other peripherals, abstracting away
  low-level hardware details.

  ## Prerequisites
  Before using this API, ensure you have the following installed and succesfully configured:
  ### Software Requirements
  - [Embedded Studio](https://www.segger.com/downloads/embedded-studio/) from Segger(Recommended IDE).
  - [J-Link Software](https://www.segger.com/downloads/jlink/) (For ST-Link debugger support).
  - STM32CubeMX (Optional, for peripheral configuration)
  - Git (For repository cloning)
 
  ### Hardware Requirements
  - STM32FO30RTC6 microcontroller development board.
  - ST-Link/V2 debugger (or compatible J-Link debugger)
  - USB cables for power and debugging.
 

  ## Installation
  1. Clone this repository to your local machine:
     `git clone https://github.com/ayamEdwin/mechasys.git`
  2. Open the project in Sergger Embedded Studio:
     - Launch Sergger Embedded Studio
     - Select "File" -> "Open Solution"
     - Navigate to the cloned repository and
       select the .emProject file.

  ## Configuration
  ### J-Link Setup for ST-Link Debugger
  1. Install the latest [J-Link Software](https://www.segger.com/downloads/jlink/)
  2. Connect your ST-Link debugger to both your computer and the target board
  3. In Segger Embedded Studio:
    - Go to "Tools" -> "Options" -> "Debugger"
    - Select "J-Link" as the debugger
    - Configure the following settings:
      - Interface: SWD
      - Device: STM32F030RC
      - Speed: 1000 kHz (adjust if needed)
      
  ### Embedded Studio Settings
  1. Project Configuration:
     - Set the target device to STM32F030RTC6
     - Will be updated (Video will soon be out)
  2. Build Configuration:
     - Ensure optimization level is set appropriately for your needs
     - Verify include paths are correctly set for all headers
     - Video will soon be out for further help
    
  ## API-Usage-Examples
  '''
      // This example code illustrate the use of DigitalOut to blink an on board LED
      // connected to pin "PD2".
    
      #include "mechatron.h"
  
      #ifdef __cplusplus
      extern "C" {
      #endif
      
      #include "System Configration.h"
      #include "stm32f0xx_ll_system.h"
      
      #ifdef __cplusplus
      }
      #endif
  
  
      int main(){
        //set up code
        SystemClock_Config(); // configures system clock
        DigitalOut ON_BOARD_LED(PD2); // Creates a DigitalOut object on PD2
    
        while(1){
              ON_BOARD_LED.write(0); // Turns on board LED off
              ThisThread::sleep_for(100000); // delays for unknown number of seconds
              ON_BOARD_LED.write(1); // Turns on board LED on
              hisThread::sleep_for(100000); // delays for unknown number of seconds
          }
      }
  '''

  ## Collaboration
  I welcome contributions to this project. If you would like
  to collaborate:
  1. Fork the repository
  2. Create a new branch for your feature or bugfix
  3. Submit  a pull request
 
  For more substantial contributions or questions, please contact me
  via email [setsoafiaedwin7@gmail.com].

  Please include detailed information about your proposed changes
  or questions## License

## License
MIT License

Copyright (c) [2025] [Edwin Setsoafia]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

[Full MIT License Text Here]
 about the API implementation.
 
  
        
  
  

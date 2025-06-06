# STM32F0x0 API (Mechatronic Sytems API)
### INSPIRED BY RETIRING [MBED API](https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html)


## Table of Contents
- [Overview](#Overview)
- [Prerequisites](#Prerequisites)
- [Installation](#Installation)
- [Configuration](#Configuration)
- [API Usage Examples](#API-Usage-Examples)
- [Collaboration](#Collaboration)
- [License](#License)

  ## Overview
  This repository (mechasys) provides an abstraction layer for the STM32F030x4/x6/x8/xC and STM32F070x6/xB
  advanced Arm®-based 32-bit MCUs,
  simplifying hardware interaction for undergraduate students for learning embedded systems.
  The API includes modules for digital I/O, analog input, and other peripherals, abstracting away
  low-level hardware details.
  For the purpose of this documentation, STM32F030x4/x6/x8/xC and STM32F070x6/xB
  microcontrollers are referred to as STM32F0x0.
  The STM32F0x0 is a family of microcontrollers with different memory sizes, packages and
  peripherals.
  For ordering information, mechanical and electrical device characteristics, please refer to
  the corresponding datasheet.

  ## Prerequisites
  Before using this API, ensure you have the following installed and succesfully configured:
  ### Software Requirements
  - [Embedded Studio](https://www.segger.com/downloads/embedded-studio/) from Segger(Recommended IDE).
  - [J-Link Software](https://www.segger.com/downloads/jlink/) (For ST-Link debugger support).
  - STM32CubeMX (Optional, for peripheral configuration)
  - Git (For repository cloning)
 
  ### Hardware Requirements
  - STM32FO30RTC6 microcontroller development board - to order, contact +233205346998.
  - ST-Link/V2 debugger (or compatible J-Link debugger)
  - USB cables for power and debugging.
 

  ## Installation
  1. Clone this repository to your local machine:
     ```bash
     git clone https://github.com/ayamEdwin/mechasys.git
     ```
  3. Open the project in Sergger Embedded Studio:
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
  ```cpp
      // This example code illustrate the use of DigitalOut to blink an on board LED
      // connected to pin "PD2".
    
      #include "mechatron.h"
  
  
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
  ```

  ## Collaboration
  I welcome contributions to this project. If you would like
  to collaborate:
  1. Fork the repository
  2. Create a new branch for your feature or bugfix
  3. Submit  a pull request
 
  For more substantial contributions or questions, please contact me
  via email [Contact me via email](https://www.setsoafiaedwin7@gmail.com).

  Please include detailed information about your proposed changes
  or questions.

## License
[MIT LICENSE](https://github.com/ayamEdwin/mechasys/blob/main/LICENSE)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/license/mit/)
 
  
        
  
  

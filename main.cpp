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

    // This example code illustrate the use of DigitalOut to blink an on board LED
    // connected to pin "PD2".
  
    #include "mechatron.h"


    int main(){
      //set up code
      SystemClock_Config(); // configures system clock
      DigitalOut ON_BOARD_LED(PD2); // Creates a DigitalOut object on PD2
  
      while(1){
            ON_BOARD_LED.write(0); // Turns on board LED off
            ThisThread::sleep_for(1000000); // delays for unknown number of seconds
            ON_BOARD_LED.write(1); // Turns on board LED on
            hisThread::sleep_for(1000000); // delays for unknown number of seconds
        }
    }

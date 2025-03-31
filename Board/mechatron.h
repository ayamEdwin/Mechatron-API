#ifndef MECHATRON_DIGITAL_OUT_H
#define MECHATRON_DIGITAL_OUT_H
#include "stm32f030xc.h"
#include <stdint.h>
#include <stdio.h>


typedef enum{
  // PORT A
  PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8,
  PA9, PA10, PA11, PA12, PA13, PA14, PA15,

  // PORT B
  PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8,
  PB9, PB10, PB11, PB12, PB13, PB14, PB15,

  // PORT C
  PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8,
  PC9, PC10, PC11, PC12, PC13, PC14, PC15,

  // PORT D
  PD2 = 50,

} PinName;

// mode for input pins
typedef enum{
        PullNone, // No pull-up or pull-down (external resistor)
        PullUp, // pull-up
        PullDown, // pull-down
        //uint32_t OpenDrain;
} PinMode;


namespace mechatron {
        // Digital Out class
        class DigitalOut{
              private:
                    uint32_t portNum;
                    uint32_t pinNum;
              public:
                    // constructor to initialize gpio output pins 
                    DigitalOut(PinName pin);

                    // writes to specified pin
                    void write(int value);
    
                    //return state of output pin
                    bool read();

                    ////Getter for port number
                    //uint32_t get_port_number();

                    ////Getter for port number
                    //uint32_t get_pin_number();
        };


        //Digital In class
        class DigitalIn {
              private:
                    uint32_t portNum;
                    uint32_t pinNum;
                    PinName user_pin;
              public:
                    // constructor for initialising GPIO input pin
                    DigitalIn(PinName pin);

                    //// Getter for pin number
                    //uint32_t get_pin_num();

                    // reads the input represented as zero(0) or one(1)
                    bool read();

                    // returns the mode settings
                    void mode(PinMode pull);
    
        };


}


namespace rtos {
      // Wait class
      class ThisThread{
            public:
                  static void sleep_for(uint32_t time);
      };
}


// Brings the mechatron namespace into global scope
using namespace mechatron;

// Brings the ThisThread namespace into global scope
using namespace rtos;


#endif

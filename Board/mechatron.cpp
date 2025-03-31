#include "mechatron.h"


namespace mechatron {
          // constructor implementation for digital out
          DigitalOut::DigitalOut(PinName pin) {
                      // EXTRACTS PORT AND PIN NUMBER FROM PinName
                      portNum = (pin >> 4) & 0xF;  // performs a right bit shift and masks result to keep only lower 4 bits
                      pinNum = (pin & 0xF); // isolates pin number by masking lower 4 bits

                      switch (portNum){
                          // user is using port A
                          case 0:
                                // configures GPIOA port as output and sets speed to medium
                                RCC -> AHBENR |= (0x1 << 17); // enabling clock for GPIOA peripheral
                                GPIOA -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits 
                                GPIOA -> MODER |= (0x1 << (pinNum * 2)); // setting pin mode to ouput
                                GPIOA -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                break;
                          // user is using port B
                          case 1:
                                // configures GPIOB port as output and sets speed to medium
                                RCC -> AHBENR |= (0x1 << 18); // enabling clock for GPIOB peripheral
                                GPIOB -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits 
                                GPIOB -> MODER |= (0x1 << (pinNum * 2)); // setting pin mode to ouput                                
                                GPIOB -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                break;

                          // user is using port C
                          case 2:
                                // configures GPIOC port as output and sets speed to medium
                                RCC -> AHBENR |= (0x1 << 19); // enabling clock for GPIOC peripheral
                                GPIOC -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits 
                                GPIOC -> MODER |= (0x1 << (pinNum * 2)); // setting pin mode to ouput
                                GPIOC -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                break;

                          // user is using port D
                          case 3:
                                // configures GPIOD port as output and sets speed to medium
                                RCC -> AHBENR |= (0x1 << 20); // enabling clock for GPIOD peripheral
                                GPIOD -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits 
                                GPIOD -> MODER |= (0x1 << (pinNum * 2)); // setting pin mode to ouput
                                GPIOD -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                break;

                          // user is using port F
                          case 4:
                                // configures GPIOF port as output and sets speed to medium
                                RCC -> AHBENR |= (0x1 << 22); // enabling clock for GPIOF peripheral
                                GPIOF -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits 
                                GPIOF -> MODER |= (0x1 << (pinNum * 2)); // setting pin mode to ouput
                                GPIOF -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                break;
                          default:
                                // check pin validity
                                printf("Invalid Pin Name!");
                                break;
                      }
          }


          // write function
          void DigitalOut::write(int value){
                            switch (portNum) {
                                // user is using port A
                                case 0:
                                      if (value == 1){
                                         //printf("%i", pinNum);
                                         GPIOA -> BSRR |= (0x1 << pinNum); // sets the ODRA Bit
                                      }
                                      else if (value == 0){
                                         GPIOA -> BSRR |= (0x1 << (pinNum + 16)); // resets the ODRA bit
                                      }
                                      else{
                                         printf("Incorrect write value. You can only write 0 or 1");
                                      }
                                      break;

                                 // user is using port B
                                case 1:
                                      if (value == 1){
                                         GPIOB -> BSRR |= (0x1 << pinNum); // sets the ODRB Bit
                                      }
                                      else if (value == 0){
                                         GPIOB -> BSRR |= (0x1 << (pinNum + 16)); // resets the ODRB bit
                                      }
                                      else{
                                         printf("Incorrect write value. You can only write 0 or 1");
                                      }
                                      break;

                                 // user is using port C
                                case 2:
                                      if (value == 1){
                                         GPIOC -> BSRR |= (0x1 << pinNum); // sets the ODRC Bit
                                      }
                                      else if (value == 0){
                                         GPIOC -> BSRR |= (0x1 << (pinNum + 16)); // resets the ODRC bit
                                      }
                                      else{
                                         printf("Incorrect write value. You can only write 0 or 1");
                                      }
                                      break;

                                 // user is using port D
                                case 3:
                                      if (value == 1){
                                         GPIOD -> BSRR |= (0x1 << pinNum); // sets the ODRD Bit
                                      }
                                      else if (value == 0){
                                         GPIOD -> BSRR |= (0x1 << (pinNum + 16)); // resets the ODRD bit
                                      }
                                      else{
                                         printf("Incorrect write value. You can only write 0 or 1");
                                      }
                                      break;

                                 // user is using port F
                                case 4:
                                      if (value == 1){
                                         GPIOF -> BSRR |= (0x1 << pinNum); // sets the ODRF Bit
                                      }
                                      else if (value == 0){
                                         GPIOF -> BSRR |= (0x1 << (pinNum + 16)); // resets the ODRF bit
                                      }
                                      else{
                                         printf("Incorrect write value. You can only write 0 or 1");
                                      }
                                      break;
                                default:
                                      // check pin validity
                                      printf("Invalid Pin Name!");
                                      break;
  
                            }
         }


         // constructor implementation for digital in
         DigitalIn::DigitalIn(PinName pin) {
                      // EXTRACTS PORT AND PIN NUMBER FROM PinName
                      portNum = (pin >> 4) & 0xF;  // performs a right bit shift and masks result to keep only lower 4 bits
                      pinNum = (pin & 0xF); // isolates pin number by masking lower 4 bits
                      user_pin = pin;

                      switch (portNum) {
                            // user is using port A
                            case 0:
                                  // configures GPIOA port as output and sets speed to medium
                                  RCC -> AHBENR |= (0x1 << 17); // enabling clock for GPIOA peripheral
                                  GPIOA -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits to input
                                  GPIOA -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                  GPIOA -> PUPDR |= (0x1 << (pinNum * 2)); // sets default mode to pull-up
                                  //GPIOA -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                  break;
                            // user is using port B
                            case 1:
                                  // configures GPIOB port as output and sets speed to medium
                                  RCC -> AHBENR |= (0x1 << 18); // enabling clock for GPIOB peripheral
                                  GPIOB -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits to input
                                  GPIOB -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                  GPIOB -> PUPDR |= (0x1 << (pinNum * 2)); // sets default mode to pull-up                                
                                  //GPIOB -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                  break;

                            // user is using port C
                            case 2:
                                  // configures GPIOC port as output and sets speed to medium
                                  RCC -> AHBENR |= (0x1 << 19); // enabling clock for GPIOC peripheral
                                  GPIOC -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits to input
                                  GPIOC -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                  GPIOC -> PUPDR |= (0x1 << (pinNum * 2)); // sets default mode to pull-up
                                  //GPIOC -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                  break;

                            // user is using port D
                            case 3:
                                  // configures GPIOD port as output and sets speed to medium
                                  RCC -> AHBENR |= (0x1 << 20); // enabling clock for GPIOD peripheral
                                  GPIOD -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits to input
                                  GPIOD -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                  GPIOD -> PUPDR |= (0x1 << (pinNum * 2)); // sets default mode to pull-up
                                  //GPIOD -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                  break;

                            // user is using port F
                            case 4:
                                  // configures GPIOF port as output and sets speed to medium
                                  RCC -> AHBENR |= (0x1 << 22); // enabling clock for GPIOF peripheral
                                  GPIOF -> MODER &= ~(0x3 << (pinNum * 2)); // resetting bits to input
                                  GPIOF -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                  GPIOF -> PUPDR |= (0x1 << (pinNum * 2)); // sets default mode to pull-up
                                  //GPIOF -> OSPEEDR |= (0x1 << (pinNum * 2)); // sets default speed of selected pin to medium
                                  break;
                            default:
                                  // check pin validity
                                  printf("Invalid Pin Name!");
                                  break;
                      }
                    
         }


         // DigitalIn read
         bool DigitalIn::read() {
                    switch(portNum){
                          // port A
                          case 0:
                                // returns pin state using IDR
                                return (GPIOA ->IDR & (0x1 << pinNum)) ? 1 : 0;
                                break;

                          case 1:
                                // returns pin state using IDR
                                return (GPIOB ->IDR & (0x1 << pinNum)) ? 1 : 0;
                                break;
                          case 2:
                                // returns pin state using IDR
                               return (GPIOC ->IDR & (0x1 << pinNum)) ? 1 : 0;
                                break;
                          case 3:
                                // returns pin state using IDR
                                return (GPIOD ->IDR & (0x1 << pinNum)) ? 1 : 0;
                                break;
                          case 4:
                                // returns pin state using IDR
                               return (GPIOF ->IDR & (0x1 << pinNum)) ? 1 : 0;
                                break;
                          default:
                                  // check pin validity
                                printf("Invalid Pin Name!");
                                break;
                          
                    }
         }


         // Mode for input pins (defaulted to pull up)
         void DigitalIn::mode(PinMode pull) {
              // EXTRACTS PORT AND PIN NUMBER FROM PinName
              portNum = (user_pin >> 4) & 0xF;  // performs a right bit shift and masks result to keep only lower 4 bits
              pinNum = (user_pin & 0xF); // isolates pin number by masking lower 4 bits

              switch (portNum) {
                      // if port A
                      case 0:
                            // if selected mode is pull-none
                            if (pull == 0){
                                //sets mode to PullNone (External resistor required)
                                GPIOA -> PUPDR &= ~(0x3 << (pinNum * 2));    
                            }
                            // if selected mode is pull-up
                            else if (pull == 1) {
                                    //sets mode to pull-up
                                    GPIOA -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOA -> PUPDR |= (0x1 << (pinNum * 2)); // sets mode to pull-up
                            }
                            // if selected mode is pull-down
                            else if (pull == 2) {
                                    //sets mode to pull-up
                                    GPIOA -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOA -> PUPDR |= (0x2 << (pinNum * 2)); // sets mode to pull-down
                            }
                            else {
                                printf("Invalid Mode! Available Modes: PullNone, PullUp, PullDown");
                            }
                            break;
                            
                        // if port B
                      case 1:
                            // if selected mode is pull-none
                            if (pull == 0){
                                //sets mode to PullNone (External resistor required)
                                GPIOB -> PUPDR &= ~(0x3 << (pinNum * 2));    
                            }
                            // if selected mode is pull-up
                            else if (pull == 1) {
                                    //sets mode to pull-up
                                    GPIOB -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOB -> PUPDR |= (0x1 << (pinNum * 2)); // sets mode to pull-up
                            }
                            // if selected mode is pull-down
                            else if (pull == 2) {
                                    //sets mode to pull-up
                                    GPIOB -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOB -> PUPDR |= (0x2 << (pinNum * 2)); // sets mode to pull-down
                            }
                            else {
                                printf("Invalid Mode! Available Modes: PullNone, PullUp, PullDown");
                            }
                            break;
                        // if port C
                      case 2:
                            // if selected mode is pull-none
                            if (pull == 0){
                                //sets mode to PullNone (External resistor required)
                                GPIOC -> PUPDR &= ~(0x3 << (pinNum * 2));    
                            }
                            // if selected mode is pull-up
                            else if (pull == 1) {
                                    //sets mode to pull-up
                                    GPIOC -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOC -> PUPDR |= (0x1 << (pinNum * 2)); // sets mode to pull-up
                            }
                            // if selected mode is pull-down
                            else if (pull == 2) {
                                    //sets mode to pull-up
                                    GPIOC -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOC -> PUPDR |= (0x2 << (pinNum * 2)); // sets mode to pull-down
                            }
                            else {
                                printf("Invalid Mode! Available Modes: PullNone, PullUp, PullDown");
                            }
                            break;
                       // if port D
                      case 3:
                            // if selected mode is pull-none
                            if (pull == 0){
                                //sets mode to PullNone (External resistor required)
                                GPIOD -> PUPDR &= ~(0x3 << (pinNum * 2));    
                            }
                            // if selected mode is pull-up
                            else if (pull == 1) {
                                    //sets mode to pull-up
                                    GPIOD -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOD -> PUPDR |= (0x1 << (pinNum * 2)); // sets mode to pull-up
                            }
                            // if selected mode is pull-down
                            else if (pull == 2) {
                                    //sets mode to pull-up
                                    GPIOD -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOD -> PUPDR |= (0x2 << (pinNum * 2)); // sets mode to pull-down
                            }
                            else {
                                printf("Invalid Mode! Available Modes: PullNone, PullUp, PullDown");
                            }
                            break;
                       // if port F
                      case 4:
                            // if selected mode is pull-none
                            if (pull == 0){
                                //sets mode to PullNone (External resistor required)
                                GPIOF -> PUPDR &= ~(0x3 << (pinNum * 2));    
                            }
                            // if selected mode is pull-up
                            else if (pull == 1) {
                                    //sets mode to pull-up
                                    GPIOF -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOF -> PUPDR |= (0x1 << (pinNum * 2)); // sets mode to pull-up
                            }
                            // if selected mode is pull-down
                            else if (pull == 2) {
                                    //sets mode to pull-up
                                    GPIOF -> PUPDR &= ~(0x3 << (pinNum * 2)); // clears bits for existing mode
                                    GPIOF -> PUPDR |= (0x2 << (pinNum * 2)); // sets mode to pull-down
                            }
                            else {
                                printf("Invalid Mode! Available Modes: PullNone, PullUp, PullDown");
                            }
                            break;
                      default:
                              // check pin validity
                              printf("Invalid Pin Name!");
                              break;
              }
         }



}


namespace rtos {
            // Dummy wait function
         void ThisThread::sleep_for(uint32_t time){
              for (volatile uint32_t i=0; i<time; i++){
                // wastes time
              }
         }
}

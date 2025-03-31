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
//set up
  SystemClock_Config();
  DigitalOut ON_BOARD_LED(PD2);
  DigitalOut EXTERNAL_LED(PA3);
  DigitalIn button(PA0);

  // simulates code flashing
  for (int pulse = 0; pulse<=10; pulse++){
    ON_BOARD_LED.write(0);
    ThisThread::sleep_for(100000);
    ON_BOARD_LED.write(1);
    ThisThread::sleep_for(100000);
  }

  // power indicator
  ON_BOARD_LED.write(1);
  button.mode(PullDown);


  for(;;){
  if (button.read() == 1){
       EXTERNAL_LED.write(1);
       ON_BOARD_LED.write(0);
  }
  else{
      // printf("%i", button.read());
      EXTERNAL_LED.write(0);
      ON_BOARD_LED.write(1);
  }
      
  }

}
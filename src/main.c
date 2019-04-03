#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "platform.h"

int main (void){
    clock_setup();
    while(1){};
    
    return 0;
    
}
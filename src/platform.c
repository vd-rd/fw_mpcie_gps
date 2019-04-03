#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "platform.h"

static void clock_setup(void){
    rcc_clock_setup_in_hsi_out_48mhz();
    
}
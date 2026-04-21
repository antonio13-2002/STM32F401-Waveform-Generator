#include <stdint.h>
#include "tim.h"

void tim2_pa5_PWM_input_mode(void){
	SET_BIT(RCC->AHB1ENR);

}


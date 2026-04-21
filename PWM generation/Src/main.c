#include <stdint.h>
#include "stm32f4xx.h"
#include "tim.h"

int main(void)
{
	tim2_pa5_PWM_mode();
	while(1){
		;//do nothing
	}
}

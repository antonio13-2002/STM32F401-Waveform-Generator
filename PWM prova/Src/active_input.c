#include <stdint.h>
#include "active_input.h"
#include "stm32f4xx.h"

void active_input_N_channel(uint32_t n){
	switch (n){
	case 1:
		MODIFY_REG(TIM2->CCMR1,TIM_CCMR1_CC1S,1U<<(TIM_CCMR1_CC1S_Pos));
		/*selecting the active polarity for TI1FP1*/
		CLEAR_BIT(TIM2->CCER,TIM_CCER_CC1P);
		CLEAR_BIT(TIM2->CCER,TIM_CCER_CC1NP);
		break;

	case 2:
		MODIFY_REG(TIM2->CCMR1,TIM_CCMR1_CC2S,2U<<(TIM_CCMR1_CC2S_Pos));
		/*selecting the active polarity for TI1FP2*/
		SET_BIT(TIM2->CCER,TIM_CCER_CC2P);
		CLEAR_BIT(TIM2->CCER,TIM_CCER_CC2NP);
		break;
	}
}


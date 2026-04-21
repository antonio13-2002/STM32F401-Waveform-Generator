#include <stdint.h>
#include "dma.h"
#include "stm32f4xx.h"
#include "sin.h"

//we have to transfer a samples vector from the memory to the CCR1 register with DMA
void dma_settings(uint32_t samples[]){
	/*enabling dma1 clock*/
	SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_DMA1EN);
	/*if any stream is enabled, we have to disable it°*/
	CLEAR_BIT(DMA1_Stream4->CR,DMA_SxCR_EN);
	while(DMA1_Stream2->CR & DMA_SxCR_EN); //do nothing until DMA is disabled, because clearing the bit is not immediately
	/*peripheral port register address selection*/
	DMA1_Stream2->PAR = (uint32_t)&TIM2->CCR1;
	/*memory address selection*/
	DMA1_Stream2->M0AR = (uint32_t)samples;
	/*setting the number of data items*/
	DMA1_Stream2->NDTR = SIZE;
	/*selecting the channel*/
	MODIFY_REG(DMA1_Stream2->CR,DMA_SxCR_CHSEL,5U<<(DMA_SxCR_CHSEL_Pos));
	/*setting the priority of the stream to very high*/
	MODIFY_REG(DMA1_Stream2->CR,DMA_SxCR_PL,3U<<(DMA_SxCR_PL_Pos));
	/*Setting memory-to-peripheral stream*/
	MODIFY_REG(DMA1_Stream2->CR,DMA_SxCR_DIR,1U<<(DMA_SxCR_DIR_Pos));
	/*setting the width of the memory and peripheral data*/
	MODIFY_REG(DMA1_Stream2->CR,DMA_SxCR_PSIZE,2U<<(DMA_SxCR_PSIZE_Pos));
	MODIFY_REG(DMA1_Stream2->CR,DMA_SxCR_MSIZE,2U<<(DMA_SxCR_MSIZE_Pos));
	/*enabling the circular mode*/
	SET_BIT(DMA1_Stream2->CR,DMA_SxCR_CIRC);
	/*memory increment mode*/
	SET_BIT(DMA1_Stream2->CR,DMA_SxCR_MINC); //it will increment the pointer value according to the MSIZE value
	/*enabling the DMA transfer*/
	SET_BIT(TIM3->DIER,TIM_DIER_UDE);
	SET_BIT(DMA1_Stream2->CR, DMA_SxCR_EN);
}



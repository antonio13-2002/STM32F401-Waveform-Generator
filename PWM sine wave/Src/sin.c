#include "sin.h"
#include <stdint.h>
#include "stm32f4xx.h"
#include <math.h>
#include <stdio.h>



void sin_generation(uint32_t vet[]){
	printf("Entering sin generation\n");
	/*samples generation*/
	float F = 1.0/(float)SIZE; //bit rate
	for (int i=0;i<SIZE;i++){
		float sample_value = (1.0+sin(2.0 * PI * F *i))*50.0; /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin generation\n");
}

//triangular waveform
void tri_generation (uint32_t vet[]){
	printf("Entering tri generation\n");
	/*samples generation*/
	float F = 1.0/(float)SIZE;
	for (int i=0; i<SIZE; i++){
		if(i<SIZE/2){
			float sample_value = 200.0* F * i;
			vet[i] = (uint32_t)sample_value;
		}else{
			float sample_value = (100.0* SIZE - 200.0 * i)*F +100.0;
			vet[i] = (uint32_t)sample_value;
		}
	}
}

void sawt_generation (uint32_t vet[]){
	printf("Entering sawt generation\n");
	/*samples generation*/
	float F = 1.0/(float)SIZE;
	for (int i=0; i<SIZE; i++){
		float sample_value = 100.0 * F * i;
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sawt generation\n");
}

void step_generation (uint32_t vet[]){
	uint32_t sample_value = 0;
	for (int i=0; i<=SIZE; i++){
		vet[i] = sample_value;
		if((i % 142)==0){
			sample_value +=10;
		}
	}
}

void dc_generation(uint32_t vet[]){
	printf("Entering dc generation\n");
	for (int i=0; i<SIZE; i++){
		vet[i]= 50; //50% duty cycle
	}
	printf("Exiting dc generation\n");
}

void sin2_generation(uint32_t vet[]){
	printf("Entering sin generation\n");
	/*samples generation*/
	float F = 1.0/(float)SIZE; //bit rate
	for (int i=0;i<SIZE;i++){
		float sample_value = (1.8+sin(2.0 * PI * F *i)+sin(4.0*PI*F*i))*25.0; /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin2 generation\n");
}

void atan_generation(uint32_t vet[]){
	printf("Entering sin generation\n");
	float a = 5.0;
	/*samples generation*/
	for (int i=0;i<SIZE;i++){
		float sample_value = ((100.0/(2.0*PI))*(atan(a/(float)SIZE*i-a/2)+PI)); /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin2 generation\n");
}

void pol_generation(uint32_t vet[]){
	printf("Entering pol generation\n");
	float a = 4.0;
	for (int i=0; i<SIZE; i++){
		float t = a / (float)SIZE * i - a / 2.0;
		float sample_value = fabs(10.0 * pow(t,4) + 5.0 * pow(t,3) -4.0 * pow(t, 2) - 2.0* t ) * 100.0;
		vet[i] = (uint32_t)sample_value;
	}
}


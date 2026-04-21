#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "signals.h"
#include "stm32f4xx.h"

float max_duty = 100.0;
float T_pwm = 0.0001;


uint32_t sin_generation(uint32_t vet[],float f){
	printf("Entering sin generation\n");
	ns = 1/(T_pwm*f);
	/*samples generation*/
	float F = 1.0/(float)ns; //bit rate
	for (int i=0;i<ns;i++){
		float sample_value = ((1.0+sin(2.0 * PI * F *i))*50.0); /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin generation\n");
	return ns;
}

//triangular waveform
uint32_t tri_generation (uint32_t vet[],float f){
	printf("Entering tri generation\n");
	ns = 1/(T_pwm*f);
	/*samples generation*/
	float F = 1.0/(float)ns;
	for (int i=0; i<ns; i++){
		if(i<ns/2){
			float sample_value = 200.0* F * i;
			vet[i] = (uint32_t)sample_value;
		}else{
			float sample_value = (100.0* ns - 200.0 * i)*F +100.0;
			vet[i] = (uint32_t)sample_value;
		}
	}
	printf("Exiting tri generation\n");
	return ns;
}

//sawtooth waveform
uint32_t sawt_generation (uint32_t vet[],float f){
	printf("Entering sawt generation\n");
	ns = 1/(T_pwm*f);
	/*samples generation*/
	float F = 1.0/(float)ns;
	for (int i=0; i<ns; i++){
		float sample_value = 100.0 * F * i;
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sawt generation\n");
	return ns;
}

//step signal
uint32_t step_generation (uint32_t vet[],float f,uint16_t N){
	printf("Entering step generation\n");
	ns = 1/(T_pwm*f);
	step_sample= ns/N;
	ns=step_sample*N;
	uint32_t sample_value = 0;
	for (int i=0; i<=ns; i++){
		vet[i] = sample_value;
		if((i % 100)==0){
			sample_value += 10;
		}
	}
	printf("Exiting step generation\n");
	return ns;
}

uint32_t dc_generation(uint32_t vet[],float size_value){
	printf("Entering dc generation\n");
	uint32_t duty_dc = (uint32_t)((size_value/5.0)*100.0);
	for (int i=0; i<SIZE; i++){
		vet[i]= duty_dc; //50% duty cycle
	}
	printf("Exiting dc generation\n");
	return ns;
}

uint32_t sin2_generation(uint32_t vet[],float f){
	printf("Entering sin generation\n");
	ns = 1/(T_pwm*f);
	/*samples generation*/
	float F = 1.0/(float)ns; //bit rate
	for (int i=0;i<ns;i++){
		float sample_value = (1.8+sin(2.0 * PI * F *i)+sin(4.0*PI*F*i))*25.0; /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin2 generation\n");
	return ns;
}

uint32_t atan_generation(uint32_t vet[], float f){
	printf("Entering sin generation\n");
	ns = 1/(T_pwm*f);
	float a = 5.0;
	/*samples generation*/
	for (int i=0;i<ns;i++){
		float sample_value = ((100.0/(2.0*PI))*(atan(a/(float)ns*i-a/2)+PI)); /*samples normalization*/
		vet[i] = (uint32_t)sample_value;
	}
	printf("Exiting sin2 generation\n");
	return ns;
}

uint32_t pol_generation(uint32_t vet[], float f){
	printf("Entering pol generation\n");
	ns = 1/(T_pwm*f);
	float a = 4.0;
	for (int i=0; i<ns; i++){
		float t = a / (float)ns * i - a / 2.0;
		float sample_value = fabs(10.0 * pow(t,4) + 5.0 * pow(t,3) -4.0 * pow(t, 2) - 2.0* t ) * 100.0;
		vet[i] = (uint32_t)sample_value;
	}
	return ns;
}

#include <stdint.h>
#include <stdio.h>
#include "choice.h"
#include "signals.h"

extern uint32_t vet[SIZE];

uint32_t signal_sample_generation(uint16_t opz){
	uint32_t new_size = 0;
	do{
	switch (opz){
		case 1:
			float f;
			printf("Insert the value of frequency: \n");
			scanf("%f",&f);
			new_size=sin_generation(vet,f);
			break;

		case 2:
			float f;
			printf("Insert the value of frequency: \n");
			scanf("%f",&f);
			new_size=tri_generation(vet,f);
			break;

		case 3:
			float f;
			printf("Insert the value of frequency: \n");
			scanf("%f",&f);
			new_size=sawt_generation(vet,f);
			break;

		case 4:
			float f;
			uint16_t N;
			printf("Insert the value of frequency and the number of steps: \n");
			scanf("%f %hu",&f,&N);
			new_size=step_generation(vet,f,N);
			break;

		case 5:
			float dc_value;
			printf("Insert the value you want to obtain: \n");
			scanf("%f",&dc_value);
			new_size=dc_generation(vet,dc_value);//continuous signal generation function
			break;

		default:
			printf("There is no option for number %d, please retry",opz);
			break;
		}
	}while(opz<1 || opz >5);
	return new_size;
}

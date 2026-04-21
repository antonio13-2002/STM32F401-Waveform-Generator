#ifndef SIGNALS_H_
#define SIGNALS_H_

#include <stdint.h>

#define PI 				3.14159265358
#define SIZE	 		1000

void sin_generation(uint32_t vet[],float f);
void tri_generation(uint32_t vet[],float f);
void sawt_generation(uint32_t vet[],float f);
void step_generation (uint32_t vet[],float f,uint16_t N);
void dc_generation (uint32_t vet[],float size_value);
void sin2_generation (uint32_t vet[],float f);
void atan_generation (uint32_t vet[],float f);
void pol_generation (uint32_t vet[],float f);

#endif /* SIGNALS_H_ */

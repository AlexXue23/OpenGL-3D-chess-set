#ifndef MATHEMATICAL_H_INCLUDED
#define MATHEMATICAL_H_INCLUDED
#include <math.h>
//Contains functions useful for mathematical, particularly vector operations

void crossproduct3f(float* first, float* second, float* wheretoreturn)
{
	*wheretoreturn = *(first + 1) * (*(second + 2)) - *(first + 2) * (*(second + 1));
	*(wheretoreturn + 1) = *first * (*(second + 2)) - *(first + 2) * (*second);
	*(wheretoreturn + 2) = *first * (*(second + 1)) - *(first + 1) * (*second);
}

void subtract3f(float* first, float* second, float* whereto)
{
	*whereto = *first - *second;
	*(whereto + 1) = *(first + 1) - *(second + 1);
	*(whereto + 2) = *(first + 2) - *(second + 2);
}
void rescalenormals(float* array)
{
	float factor = sqrt(pow(*array, 2) + pow(*(array + 1), 2) + pow(*(array + 2), 2));
	*array = *array / factor;
	*(array + 1) = *(array + 1) / factor;
	*(array + 2) = *(array + 2) / factor;
}
#endif // MATHEMATICAL_H_INCLUDED

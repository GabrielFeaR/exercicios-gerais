#include "esfera_utils.h"
#include <stdio.h>

int main()
{
	float Raio, Volume, Area;
	scanf("%f", &Raio);
	Volume = calcula_volume(Raio);
	Area = calcula_area(Raio);
	printf("Area: %.2f\n", Area);
	printf("Volume: %.2f\n", Volume);
	return 0;
}
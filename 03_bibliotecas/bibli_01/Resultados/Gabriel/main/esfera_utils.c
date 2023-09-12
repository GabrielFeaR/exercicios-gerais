#include "esfera_utils.h"
#include <math.h>

float calcula_volume(float R)
{
	float volume;
	volume = (4*PI*pow(R, 3))/3;
	return volume;
}

float calcula_area(float R)
{
	float area;
	area = 4*PI*pow(R, 2);
	return area;
}
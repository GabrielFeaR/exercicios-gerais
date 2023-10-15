#include <stdio.h>
#include <math.h>
#include "esfera_utils.h"

void CalculaVolume (float R, float *volume)
{
	*volume = (4*(PI*(pow(R,3))))/3;
}

void CalculaArea (float R, float *area)
{
	*area =	(4*(PI*(pow(R,2))));
}
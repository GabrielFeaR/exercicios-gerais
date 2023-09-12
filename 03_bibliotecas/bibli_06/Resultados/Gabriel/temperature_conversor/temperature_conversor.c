#include <stdio.h>
#include "temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature)
{
	temperature = temperature + 273.15;
	return temperature;
}

float convert_celsius_to_fahrenheit(float temperature)
{
	temperature = temperature * 9/5 + 32;
	return temperature;
}

float convert_kelvin_to_celsius(float temperature)
{
	temperature = temperature - 273.15;
	return temperature;
}

float convert_kelvin_to_fahrenheit(float temperature)
{
	temperature = (temperature-273.15) * 9/5 + 32;
	return temperature;
}

float convert_fahrenheit_to_celsius(float temperature)
{
	temperature = (temperature-32) * 5/9;
	return temperature;
}

float convert_fahrenheit_to_kelvin(float temperature)
{
	temperature = (temperature-32) * 5/9 + 273.15;
	return temperature;
}

float convert_temperature(float temperature, float convert_func(float temperature))
{
	float temperaturefinal;
	temperaturefinal = convert_func(temperature);
	return temperaturefinal;
}

#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    float temp, tempfinal;
    char origem, final;
    scanf("%f %c %c", &temp, &origem, &final);
    if (origem == 'c')
    {
        if (final == 'k')
        {
            tempfinal = convert_temperature(temp, convert_celsius_to_kelvin);
        }
        else if (final == 'f')
        {
            tempfinal = convert_temperature(temp, convert_celsius_to_fahrenheit);
        }
    }
    if (origem == 'k')
    {
        if (final == 'c')
        {
            tempfinal = convert_temperature(temp, convert_kelvin_to_celsius);
        }
        if (final == 'f')
        {
            tempfinal = convert_temperature(temp, convert_kelvin_to_fahrenheit);
        }
    }
    if (origem == 'f')
    {
        if (final == 'c')
        {
            tempfinal = convert_temperature(temp, convert_fahrenheit_to_celsius);
        }
        if (final == 'k')
        {
            tempfinal = convert_temperature(temp, convert_fahrenheit_to_kelvin);
        }
    }
    final = final-32; //(transformar em maiúsculo)
    printf("Temperature: %.02f%c", tempfinal, final);
    if (final != 'K')
    {
        printf("º\n");
    }
    else
    {
        printf("\n");
    }
    return 0;
}
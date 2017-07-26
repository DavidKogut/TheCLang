/*
 *  Write the temperature conversion program with functions.
 *  I've already been using functions, so it's just a re-write of 1-3.
 */ 

#include <stdio.h>

float fahrToCelsius(float fahr);
void printTemps(int lower, int upper, int step);
void printHeader();

main()
{
    printHeader();
    printTemps(0, 300, 20);
}

void printHeader()
{
    printf(" \260F\t\260C\n");
}

void printTemps(int lower, int upper, int step)
{
    float fahr;

    for (fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        printf("%3.0f\t%6.1f\n", fahr, fahrToCelsius(fahr));
    }
}

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}

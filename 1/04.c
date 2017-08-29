#include <stdio.h>                                                                                                              

void printHeader();
void printCelToFahr(int lower, int upper, int step);

main()
{
    printHeader();
    printCelToFahr(-40, 40, 5);

    return 0;
}

//octal escape \260 is the DEGREE sign. Requires an extended UTF-8 encoding to display correctly. eg. ISO 8859-1
void printHeader()
{
    printf(" \260C\t\260F\n");
}

void printCelToFahr(int lower, int upper, int step)
{
    float fahr, celsius;

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}

#include <stdio.h>

void printHeader();
void printFahrToCel(int lower, int upper, int step);

main()
{
    printHeader();
    printFahrToCel(0, 300, 20);
    
    return 0;
}

//octal escape \260 is the DEGREE sign. Requires an extended UTF-8 encoding to display correctly. eg. ISO 8859-1
void printHeader()
{
    printf(" \260F\t\260C\n");
}

void printFahrToCel(int lower, int upper, int step)
{
    float fahr, celsius;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

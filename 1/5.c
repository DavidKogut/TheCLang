#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void printHeader();
void printFahrToCel(int lower, int upper, int step);

main()
{
    printHeader();
    printFahrToCel(LOWER, UPPER, STEP);
    
    return 0;
}

//octal escape \260 is the DEGREE sign. Requires an extended UTF-8 encoding to display correctly. eg. ISO 8859-1
void printHeader()
{
    printf(" \260F\t\260C\n");
}

void printFahrToCel(int lower, int upper, int step)
{
    int fahr;
    
    for(fahr = upper; fahr >= lower; fahr -= step) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
    }
}

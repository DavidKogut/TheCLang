#include <stdio.h>

main() 
{
    int c, lastc;

    lastc = '\0';
    
    while ((c = getchar()) != EOF)
    {
        if (!(lastc == ' ' && c == ' '))
        {
            putchar(c);
        }
        lastc = c;
    }

    return 0;
}


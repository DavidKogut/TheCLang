/*
 * Strip trailing spaces and tabs from the end of a line before printing it.
 * Do not print empty lines.
 */

#include <stdio.h>

#define MAX     1000

int getLine(int lim);

int main()
{
    while (getLine(MAX)); // Loop until return is false
}

int getLine(int lim)
{
    int c, i, lastChar;
    char line[MAX];

    i = 0;
    lastChar = -1;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n' && i < lim-1) // keep track of last non-whitesapce character.
            lastChar = i;
        
        if (i < lim-1) // Save character if under limit.
        {
            line[i] = c;
        }

        i++;

        if (c == '\n')            
            break;
    }

    if (lastChar > -1 ) //Don't print empty lines.
    {
        line[++lastChar] = '*'; //Instead of '\n' we'll append a * so we can tell if the whitespace was stripped or not.
        line[++lastChar] = '\0';
        printf("%s\n", line);
    }

    return c != EOF;
}

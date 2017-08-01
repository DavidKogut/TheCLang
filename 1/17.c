/*
 * Print all input lines longer than 80 characters long.
 * We'll use our getLine function from 1-16 so we properly read each individual line.
 */

#include <stdio.h>

#define MAXLINE     1000
#define THRESHOLD     80

int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > THRESHOLD)
        {
            printf("\n%s\n", line);
        } 
    }
    return 0;    
}

int getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;

    while ((c = getchar()) != EOF)
    {
        if (i < lim-1)
            s[i] = c;
        
        i++;
        
        if (c == '\n')
            break;

    }
    
    if (i >= lim)
        s[lim-1] = '\0';
    else
        s[i] = '\0';

    return i;
}

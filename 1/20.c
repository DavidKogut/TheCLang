/*
 * This program reads input lines and turns any tab into the appropriate amount of spaces.
 */
#include <stdio.h>

#define TABSTOP 8     //tab size
#define MAX     1000  //max line size

int getLine(char s[], int lim);
int detab(char s[], int index, int lim);

int main()
{
    char line[MAX];

    while (getLine(line, MAX))
    {
        printf("%s", line);
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
        {
            if (c == '\t')
                i = detab(s, i, lim);
            else
                s[i++] = c;
        }
        if (c == '\n')
            break;
    }
    s[i] = '\0';

    return i;
}

int detab(char s[], int index, int lim)
{
    int i;

    for (i = index % TABSTOP; i < TABSTOP && index < lim-1; i++)
    {
        s[index++] = ' ';
    }

    return index;
}

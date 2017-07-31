/*
 * Here we've updated the given codde in 1.9 to correctly store the value of the length of the line
 * instead of capping out at our max length. That way we can keep track of the true longest line,
 * but in order to properly save the string we had to remove some of the end loop logic from the loop itself,
 * and instead break out of the loop on a newline char. Since we're also going well past the array limit,
 * we have to ensure the null char is the last element in the array if we did.
 */


#include <stdio.h>

#define MAXLINE 10

int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("Length:%d\n%s\n", max, longest);
    
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    i = 0;

    while ((c = getchar())!=EOF)
    {
        if (i < lim)
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}

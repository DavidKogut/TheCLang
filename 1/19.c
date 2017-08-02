/*
 * Write a function that reverses a supplied string.
 */

#include <stdio.h>

#define MAX 1000

int getLine(char s[], int lim);
void reverse(char s[], int fullLen);

int main()
{
    int len;
    char line[MAX];

    while ((len = getLine(line, MAX)) > 0)
    {
        if (len > 1)
            reverse(line, len);
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
            s[i] = c;
            i++;
        }
        if (c == '\n')
            break;
    }
    s[i] = '\0';

    return i;
}

/*
 * The question seems to imply that we are only supposed to pass the line to be reversed.
 * Instead of having to loop through the line to find the null char, we'll save time by just passing the length.
 */
void reverse(char s[], int fullLen)
{
    char temp;
    int i, len;

    len = fullLen-2; //skip '\0' and '\n' chars

    for (i = len; i > len/2; i--)
    {
        temp = s[i];
        s[i] = s[len-i];
        s[len-i] = temp;
    }
}

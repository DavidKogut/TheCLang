/*
 * This program breaks long lines of input into multiple lines.
 */
#include <stdio.h>

#define MAX         1000
#define LINE_LENGTH 50

int getLine(char s[]);
int isWhitespace(int c);

int main()
{
    char input[MAX];

    while(getLine(input))
    {
        printf("%s", input);
    }
    return 0;
}

int getLine(char s[])
{
    int i, c, col, lastSpace, print;
    
    i = lastSpace = col = 0;

    while ((c = getchar()) != EOF)
    {
        print = 1;

        if (i < MAX-1)
        {
            if (isWhitespace(c))
                lastSpace = i;

            if (col == LINE_LENGTH-1)
            {
                if (lastSpace > 0) //turn previous whitespace into a newline
                {
                    s[lastSpace] = '\n';
                    col = i-(lastSpace + 1);

                    //If the current input is whitespace, we already replaced it as a newline, so don't print it.
                    if (col == 0)
                    {
                        i++;
                        print = 0;
                    }

                    lastSpace = 0;
                }
                else //split the word
                {
                    s[i++] = '-';
                    s[i++] = '\n';
                    col = 0;
                }
            }
            if (print)
            {
                s[i++] = c;
                col++;
            }
        }
        if (c == '\n')
            break;
    }
    s[i] = '\0';

    return i;
}

int isWhitespace(int c) { return c == ' ' || c == '\t'; }

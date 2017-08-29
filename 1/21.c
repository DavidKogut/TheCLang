/*
 * This program reads input lines and turns spaces into the appropriate amount of tabs.
 */
#include <stdio.h>

#define TABSTOP 8     //tab size
#define MAX     1000  //max line size

int getLine(char s[], int lim);
int incrementCol(int col);
int atTabStop(int s, int c);

int main()
{
    char line[MAX];

    while (getLine(line, MAX))
    {
        printf("%s", line);
    }
    return 0;
}

/* 
 * Since we can only return one variable at a time in functions; we're limited in breaking down
 * this function.
 * We have built a state machine keeping track of the amount of spaces we've inputted in a row, 
 * and the current tabstop column position.
 */
int getLine(char s[], int lim)
{
    int c, i, col, spaceCount, printChar;

    i = col = spaceCount = 0;

    while ((c = getchar()) != EOF)
    {
        if (i < lim)
        {
/*
 * Space event: check how many spaces have been input, if a tab can be inerted do so, and reset the space count.
 */
            if (c == ' ') 
            {
                spaceCount++;
            
                if (atTabStop(spaceCount, col))
                {
                    s[i++] = '\t';
                    spaceCount = 0;
                    col = 0;
                }
            }
/*
 * Non-Space event:  Was the last input a space? Then check if we can insert a tab and continue.
 *                   Is the current input a tab? Insert a tab again and reset your counters. 
 *                          We do this to ensure we don't print the spaces before a tab.
 *                          Since this is only checked if the last input was a space, make sure not to print it again later.
 *                   Print as many spaces as we have in our count.
 *                   Print the inputted character (unless we've already handled that.)
 */
            else
            {
                printChar = 1;

                if (spaceCount > 0)
                {
                    if (atTabStop(spaceCount, col))
                    {
                        s[i++] = '\t';
                        spaceCount = 0;
                        col = 0;
                    }

                    if (c == '\t')
                    {
                        s[i++] = '\t';
                        spaceCount = 0;
                        col = 0;
                        printChar = 0;
                    }

                    for (; spaceCount > 0; spaceCount--)
                    {
                        s[i++] = ' ';
                        col = incrementCol(col);
                    }
                }
                
                if (printChar)
                {
                    s[i++] = c;
                    col = incrementCol(col);
                }
            }
        }
        if (c == '\n')
            break;
    }
    
    s[i] = '\0';
    
    return i;
}

int incrementCol(int col)
{
    return (col+1)%TABSTOP;
}

int atTabStop(int s, int c)
{
    return (s + c)%TABSTOP == 0;
}

/*
 * This program reads input lines and turns spaces into the appropriate amount of tabs.
 */
#include <stdio.h>

#define TABSTOP 8     //tab size
#define MAX     1000  //max line size

int getLine(char s[], int lim);
int incrementCol(int col);

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
    int c, i, col, spaceCount, printTab;

    i = col = spaceCount = 0;

    while ((c = getchar()) != EOF)
    {
        if (i < lim)
        {
            if (c == ' ')
            {
                spaceCount++;
            
                if ((spaceCount+col)%TABSTOP == 0)
                {
                    s[i++] = '\t';
                    spaceCount = 0;
                    col = 0;
                }
            }
            else
            {
                printTab = 1;
                if (spaceCount > 0)
                {
                    if ((spaceCount+col)%TABSTOP == 0)
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
                        printTab = 0;
                    }

                    for (; spaceCount > 0; spaceCount--)
                    {
                        s[i++] = ' ';
                        col = incrementCol(col);
                    }
                }
                
                if (c != '\t' || printTab)
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

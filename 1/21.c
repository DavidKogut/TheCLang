/*
 * This program reads input lines and turns spaces into the appropriate amount of tabs.
 */
#include <stdio.h>

#define TABSTOP 8     //tab size
#define MAX     1000  //max line size

int getLine(char s[], int lim);
int entab(char s[], int index, int lim, int spaces, int c);

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
    int c, i, lastChar, spaceCount;

    i = 0;
    lastChar = spaceCount = -1;
    while ((c = getchar()) != EOF)
    {
        spaceCount = (c == '\t' || spaceCount == TABSTOP-1) ? 0 : spaceCount+1;

        if (i < lim-1)
        {
            if (c != ' ')
            {    
                if (lastChar+1 < i)
                    i = entab(s, lastChar+1, i, spaceCount, c);

                lastChar = i;
            }
            s[i++] = c;   
        }
        if (c == '\n')
            break;
    }
    s[i] = '\0';
    return i;
}


int entab(char s[], int lastCharIndex, int currIndex, int spaces, int c)
{
    int i, numTabs, newIndex;
    
    newIndex = lastCharIndex;
    numTabs = currIndex/TABSTOP - lastCharIndex/TABSTOP;

    for (i = 0; i < numTabs; i++)
        s[newIndex++] = '\t';
    
    return (newIndex > lastCharIndex || c == '\t') ? newIndex + spaces : currIndex;  
}

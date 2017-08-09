/*
 * This program reads input lines and turns spaces into the appropriate amount of tabs.
 */
#include <stdio.h>

#define TABSTOP 8     //tab size
#define MAX     1000  //max line size

int getLine(char s[], int lim);
int entab(char s[], int index, int lim);

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
    int c, i, lastChar;

    i = 0;
    lastChar = -1;

    while ((c = getchar()) != EOF)
    {
        if (i < lim-1)
        {
            if (c != ' ')
            {    
                if (lastChar+1 < i)
                    i = entab(s, lastChar+1, i+1);

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

int entab(char s[], int index, int lim)
{
    int i, numTabs, numSpaces;
    
    printf("old index:%d\n", index);
    numTabs = (lim-index)/TABSTOP;
    numSpaces = (lim-(index+TABSTOP*numTabs))%TABSTOP;
   
    printf("Tabs:%d spaces:%d\n", numTabs, numSpaces);
    for (i = 0; i < numTabs; i++)
    {
        s[index++] = '\t';
    }
    printf("new index:%d old index:%d\n", index+numSpaces, lim);
    
    return index+numSpaces;
}

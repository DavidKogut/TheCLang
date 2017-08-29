#include <stdio.h>

main() 
{
    int c, blanks, tabs, newlines;

    blanks = tabs = newlines = 0;
    
    while ((c = getchar()) != EOF) 
    {
        switch (c)
        {
            case ' ':
                ++blanks;
                break;
            case '\t':
                ++tabs;
                break;
            case '\n':
                ++newlines;
                break;
        }
    }

    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, newlines);

    return 0;
}


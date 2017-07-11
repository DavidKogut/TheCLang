#include <stdio.h>

#define IN  1
#define OUT 0
#define TRUE    1
#define FALSE   0

int isAlpha(int c);

main()
{
    int c, legal, state;

    state = OUT;
    legal = FALSE;

    while ((c = getchar()) != EOF)
    {
        /*
        * We will be following the wording exactly, we will be print one WORD per line.
        * This means all inputted characters will be printed, but we will be inserting a newline after every WORD.
        */
        putchar(c);

        if (c == '\n' || c == '\t' || c == ' ') // check for delimiter
        {
            state = OUT;
            if (legal)
            {
                legal = FALSE;
                putchar('\n');
            }
            else if (c == '\n')
            {
                //Since we print all characters, we can end up with a line with no words in it.
                //This warning will alert the user when that is the case.
                printf("^^^No words in above line^^^\n");
            }
        }
        else if ( state == OUT ) // starting new word
        {
            if (isAlpha(c))
            {
                legal = TRUE;
            }
            
            state = IN;
        }
    }

    return 0;
}

int isAlpha(int c)
{
    //          A - Z                      a - z
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

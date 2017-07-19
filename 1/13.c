#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX 10 //Max word length we're counting

void printHorizontal(int wordLen[]);

int main() 
{
    int c;
    int wc = 0;
    int wordLen[MAX] = {0}; //inititalze array to 0s
    int status = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (status)
            {
                status = OUT;
                wordLen[wc-1]++;
                wc = 0;
            }
        } 
        else 
        {
            status = IN;
            if (wc < MAX)
            {
                wc++;
            }
        }
    }
    
    printHorizontal(wordLen);

    return 0;
}


void printHorizontal(int wordLen[])
{
    int i, j;
    
    for (i = 0; i < MAX; i++)
    {
        printf("%*d", 2, i+1);
        if (i == MAX) 
            printf("+:");
        else
            printf(" :");
        for (j = 0; j < wordLen[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX 10 //Max word length we're counting, exceeding past 10 will break printing.

void printHorizontal(int wordLen[]);
void printVertical(int wordLen[]);
int getMax(int wordLen[]);

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
    
    printf("\n");
    printHorizontal(wordLen);
    printf("\n");
    printVertical(wordLen);
    return 0;
}


void printHorizontal(int wordLen[])
{
    int i, j;
    
    for (i = 0; i < MAX; i++)
    {
        printf("%*d", 2, i+1);
        if (i == MAX-1) 
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

void printVertical(int wordLen[])
{
    int i, most;
    
    for (most = getMax(wordLen); most > 0; most--)
    {
        for (i = 0; i < MAX; i++)
        {
            if (wordLen[i] >= most)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }

    for (i = 0; i < MAX; i++)
    {
        printf("%d ", i+1);
    }
    printf("\b+\n");

}

int getMax(int wordLen[])
{
    int i, max;

    max = 0;

    for (i = 0; i < MAX; i++)
    {
        if (wordLen[i] > max)
            max = wordLen[i];
    }

    return max;
}

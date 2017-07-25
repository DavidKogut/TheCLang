/*
 * Print a histogram of the different frequencies of different characters.
 * There are a lot of characters, so lets limit it to basic ASCII characters. (32 - 126)
 * It's a lot to print, so lets also only print non-zero values.
 */

#include <stdio.h>

#define MIN 32
#define MAX 128

void printHorizontal(int chars[]);

int main() 
{
    int c;
    int chars[MAX - MIN] = {0};

    while ((c = getchar()) != EOF)
    {
        if (c >= MIN  && c < MAX)
        {
            chars[c - MIN]++;
        }   
    }
    
    printf("\n");
    printHorizontal(chars);
    printf("\n");

    return 0;
}

void printHorizontal(int chars[])
{
    int i,j;

    for (i = 0; i < MAX-MIN; i++)
    {
        if (chars[i] != 0)
        {
            printf("%c: ", i + MIN);
            for (j = 0; j < chars[i]; j++)
            {
                printf("x");
            }
            printf("\n");
        }
    }
}

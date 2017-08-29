#include <stdio.h>

main()
{
    int c;

    /*
     * The loop below will only ever print the number 1 for each input.
     * c is being assigned the value to the right of it, which is: getchar() != EOF
     * getchar() recieves an input, we then check to see if its equal to EOF, the result is a 0 if it is, and a 1 if it's not.
     * Therefore it will always print 1, because as soon as 0 is stored in c, the loop will terminate.
     *
     * Note: putchar will not print anything because the value of 1 is not a character, but control code SOH.
     */
    while (c = getchar() != EOF)
        printf("%d\n", c); 

    return 0;
}

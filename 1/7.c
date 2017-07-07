#include <stdio.h>

main()
{
    /*
     * EOF is not a character, so we can't print it with putchar.
     * we can however print EOF's value. 
     */

    printf("%d\n", EOF);
    
    return 0;
}


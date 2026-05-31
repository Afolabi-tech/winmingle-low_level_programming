#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 
 *Samuel Afolabi
 *WinMingle Community C Training
 *This is a program that prints whether a number is positive, negative or zero.
 * */

int main(void)

{
    int n;
    srand(time(0));

    n = rand() - RAND_MAX / 3;

    if (n > 0)
        printf("%i is positive\n", n);
    else if (n < 0)
        printf("%i is negative\n", n);
    else
        printf("%i is zero\n", n);


    return(0);
}


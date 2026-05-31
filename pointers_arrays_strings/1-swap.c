#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: first integer
 * @b: second integer
 */

void swap_int(int *a, int *b)
{

    
    /**
     * Another Way of writing the code
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
    */

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

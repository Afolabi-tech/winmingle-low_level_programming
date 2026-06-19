#include "main.h"

/**
*int factorial - function that returns the factorial of a given number
*@n: value of the integer to find the factorial
*
*Return 0
*/

int factorial(int n)
{   

    if (n == 0 || n == 1)
        return (1);

    else if (n < 1)
        return (-1);

    return (n*factorial(n - 1));
}

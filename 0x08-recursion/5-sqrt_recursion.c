#include "main.h"

/**
*_sqrt_helper - funtion that returns the natural square root of a number
*@n: number
*@i: possible square root
*
*Return: natural square root or -1
*/
int sqrt_helper(int n, int i)
{
    if (i * i == n)
        return (i);

    if (i * i > n)
        return (-1);

    return (sqrt_helper(n, i + 1));
}

/**
*_sqrt_recursion - returns the natural square root of a number
*@n: number
*
*Return: naturn square root or -1
*/


int _sqrt_recursion(int n)
{
    if (n < 0)
        return (-1);

    return (sqrt_helper(n, 0));
}

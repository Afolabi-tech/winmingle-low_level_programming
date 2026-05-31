#include "main.h"
#include <stdio.h>

/**
 *print_numbers - function to print 0 - 9
 *
 *Return: Void
 */

void print_numbers(void)
{

    char x = '0';

    while (x <= '9')
    {


        _putchar(x);
        x++;
    }

    _putchar('\n');
}


#include "main.h"

/**
 *print lower case a - z using _putchar
 *
 */

void print_alphabet(void)

{
    char x;

    for (x = 'a'; x <= 'z'; x++)
    {
        _putchar(x);
    }

    _putchar('\n');

}

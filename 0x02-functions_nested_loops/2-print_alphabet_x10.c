#include "main.h"

/**
 *print lower case a - z using _putchar 10 times with new line.
 *
 */

void print_alphabet_x10(void)

{
    char x, i;

    for (i = 0; i < 10; i++)
    {
        for (x = 'a'; x <= 'z'; x++){
             _putchar(x);  
        }

        _putchar('\n');
    }

}

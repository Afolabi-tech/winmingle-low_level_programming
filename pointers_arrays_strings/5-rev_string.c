#include "main.h"

/**
 *rev_print - prints the reverse of MY School
 *
 *@s: reverse the string.
 */

void print_str(char *s)
{

    int i = 0;
    while (s[i] != '\0')
    {
        i++;

    }
    i--;

    while (i >= 0)
    {

        _putchar(s[i]);
        i--;
    }

    _putchar('\n');
}

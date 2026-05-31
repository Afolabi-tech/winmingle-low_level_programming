#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char x = 'a';

    while (x <= 'z') {
        putchar(x);
        x++;
    }

    putchar('\n');
    return(0);
}

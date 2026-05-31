#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char x = '0';

    while (x <= '9') {
        putchar(x);
        x++;
    }

    putchar('\n');
    return(0);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int x = 0;

    while (x < 10) {
        putchar(48 + x);
        x++;
    }

    putchar('\n');
    return(0);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    char x = 'a';

    while (x <= 'z') {
        if (x != 'e' && x != 'q'){
            putchar(x);
        }
        x++;
    }

    putchar('\n');
    return(0);
}

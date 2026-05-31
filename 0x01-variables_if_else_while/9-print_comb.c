#include <stdio.h>

/**
 *Print all possible combinations of single-digit numbers separated by commas and spaces.
 *
 *
 */

int main(void)
{
    int n;
    for(n = 0; n <= 9; n++){
        putchar(n + '0');

        if(n != 9){
            putchar(',');
            putchar(' ');

        }
    }
    putchar('\n');
    return(0);
}

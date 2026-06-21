#include <stdio.h>
#include <stdlib.h>

/**
*main - Program that prints all arguments passed into it.
*@argc: number of arguments
*@arg: array o arguments
*/

int main(int argc, char *argv[])

{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);

    }
       


    return (0);
}

#include <stdio.h>
#include <stdlib.h>

/**
*0-whatsmyname - Program that prints its own name
*
*/

int main(int argc, char *argv[])

{
    int i;
    printf("This program's name is \"%s\".\n", argv[0]);
    if (argc > 1)
    {

        for (i = 0; i < argc; i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);

        }
    }   


    return (0);
}

#include "function_pointers.h"

/**
*int_index - Searches for an integer; returns index of first element where cmp != 0, otherwise -1
*if size <= 0, return -1
*
*/

int int_index(int *array, int size, int (*cmp)(int))
{
    int i, j;

    if (size > 0 && array && cmp)
    {
        for (i = 0; i < size; i++)
        {
            j = cmp(array[i]);

            if (j)
                break;
        }

        if (i < size)
            return (i);
    }
    return (-1);

}

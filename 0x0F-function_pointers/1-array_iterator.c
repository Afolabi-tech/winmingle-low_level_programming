#include "function_pointers.h"

/**
*array_iterator - function action on each element of array
*
*Return: 0
*/

void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t n;

    if (array && action)
    {
        for (n = 0; n < size; n++)
            action(array[n]);
    }
}

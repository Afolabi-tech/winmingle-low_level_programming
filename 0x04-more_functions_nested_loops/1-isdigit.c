#include "main.h"

/**
 *1-isdigit - funtion to check for a digit (0 through 9)
 *
 *Return: 1
 */


int _isdigit(int c)
{

    if (c >= '0' && c <= '9')
    {

        return(1);
    }
    else
    {
        return(0);
    }

}

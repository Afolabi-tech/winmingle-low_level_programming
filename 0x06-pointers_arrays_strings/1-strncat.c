#include "main.h"

/**
* _strncpy - concatenate strings using at most n bytes from src
* @dest: destination string
* @src: source string
* @n: maximum number of bytes to copy from src
*
* Return: pointer to dest
*/
	char *_strncat(char *dest, char *src, int n);
	
{
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}

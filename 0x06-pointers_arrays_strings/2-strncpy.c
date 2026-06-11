#include "main.h"

/**
* _strncpy - copy strings using at most n bytes from src
* @dest: destination buffer
* @src: source string
* @n: maximum number of bytes to copy from src
*
* Return: pointer to dest
*/
char *_strncpy(char *dest, char *src, int n)
	
{
	int i = 0;

	for (; i < n && src[i] != '\0'; i++)
	
		dest[i] = src[i];
		
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

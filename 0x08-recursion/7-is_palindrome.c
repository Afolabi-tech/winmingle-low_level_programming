#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen(s + 1));
}

/**
 * palindrome_helper - checks if a string is a palindrome
 * @s: string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	len = _strlen(s);

	return (palindrome_helper(s, 0, len - 1));
}

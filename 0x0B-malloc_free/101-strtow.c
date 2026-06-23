#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in a string
 * @str: input string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, words = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' &&
		    (i == 0 || str[i - 1] == ' '))
			words++;
	}

	return (words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of words, or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, start, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);

	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	k = 0;
	i = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;

		if (str[i] == '\0')
			break;

		start = i;
		len = 0;

		while (str[i] != ' ' && str[i] != '\0')
		{
			len++;
			i++;
		}

		words[k] = malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(words[j]);

			free(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[start + j];

		words[k][j] = '\0';
		k++;
	}

	words[k] = NULL;

	return (words);
}

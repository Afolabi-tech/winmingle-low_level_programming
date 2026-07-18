#include <stdlib.h>
#include "lists.h"

/**
 * struct listp_s - stores visited node addresses
 * @p: pointer to a listint_t node
 * @next: pointer to next stored address
 */
typedef struct listp_s
{
	const listint_t *p;
	struct listp_s *next;
} listp_t;

/**
 * free_listp - frees the helper list
 * @head: helper list
 */
static void free_listp(listp_t *head)
{
	listp_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_nodep - stores a visited address
 * @head: helper list
 * @p: node address
 *
 * Return: new helper node or NULL
 */
static listp_t *add_nodep(listp_t **head, const listint_t *p)
{
	listp_t *new;

	new = malloc(sizeof(listp_t));
	if (new == NULL)
		return (NULL);

	new->p = p;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: address of the head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listp_t *visited = NULL;
	listp_t *temp;
	listint_t *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		temp = visited;

		while (temp != NULL)
		{
			if (temp->p == *h)
			{
				free_listp(visited);
				*h = NULL;
				return (count);
			}
			temp = temp->next;
		}

		if (add_nodep(&visited, *h) == NULL)
		{
			free_listp(visited);
			exit(98);
		}

		next = (*h)->next;
		free(*h);
		*h = next;
		count++;
	}

	free_listp(visited);
	*h = NULL;

	return (count);
}

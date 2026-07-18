#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * struct listp_s - stores visited node addresses
 * @p: pointer to a listint_t node
 * @next: points to the next stored address
 */
typedef struct listp_s
{
	const listint_t *p;
	struct listp_s *next;
} listp_t;

/**
 * free_listp - frees a listp_t list
 * @head: pointer to the first node
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
 * add_nodep - adds a node address to the list
 * @head: address of the head pointer
 * @p: address to store
 *
 * Return: new node or NULL
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
 * print_listint_safe - prints a listint_t list safely
 * @head: pointer to the first node
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	listp_t *visited = NULL, *temp;
	size_t count = 0;

	while (head != NULL)
	{
		temp = visited;

		while (temp != NULL)
		{
			if (temp->p == head)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(visited);
				return (count);
			}
			temp = temp->next;
		}

		if (add_nodep(&visited, head) == NULL)
			exit(98);

		printf("[%p] %d\n", (void *)head, head->n);

		count++;
		head = head->next;
	}

	free_listp(visited);

	return (count);
}

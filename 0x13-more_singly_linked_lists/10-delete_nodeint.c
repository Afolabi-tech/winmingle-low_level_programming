#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a given index
 * @head: address of the pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Delete the first node */
	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}

	temp = *head;

	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);

	node = temp->next;
	temp->next = node->next;
	free(node);

	return (1);
}

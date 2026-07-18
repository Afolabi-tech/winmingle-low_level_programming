#include "lists.h"

/**
*insert_nodeint_at_index - inserts a new node at a given index
*@head: address of the pointer to the first node
*@idx: index where the new node should be inserted
*@n: integer to store in the new node
*
*Return: address of the new node, or NULL if it fails
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new;
    listint_t *temp;
    unsigned int i;
    
    if (head == NULL)
        return (NULL);

    new = malloc(sizeof(listint_t));

    if (new == NULL)
        return (NULL);

    new->n = n;

    if (idx == 0)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    temp = *head;

    for (i = 0; temp != NULL && i < idx - 1; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        free(new);
        return (NULL);
    }

    new->next = temp->next;
    temp->next = new;

    return (new);
}

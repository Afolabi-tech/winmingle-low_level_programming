#include "lists.h"
#include <string.h>

/**
*add_node_end - function that adds a new node at the end of a list
*@head: address of pointer to the first node
*@str: string to be duplicated and stored 
*
*Return: address of the new element, or NULL if it failed
*/

list_t *add_node_end(list_t **head, const char *str)
{
    list_t *temp;
    list_t *new;
    unsigned int len;

    if (head == NULL || str == NULL)
        return (NULL);

    new = malloc(sizeof(list_t));

    if (new == NULL)
        return (NULL);

    new->str = strdup(str);

    if (new->str == NULL){
        free(new);
        return (NULL);
    }

    len = 0;
    while (str[len] != '\0')
        len++;
    
    new->len = len;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return (new);
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    
    return(new);
        
}

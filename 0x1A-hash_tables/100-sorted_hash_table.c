#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;

    if (size == 0)
        return (NULL);

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->array = calloc(size, sizeof(shash_node_t *));
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    ht->size = size;
    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - adds or updates an element in a sorted hash table
 * @ht: sorted hash table
 * @key: key
 * @value: value associated with key
 *
 * Return: 1 if successful, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *current;
    shash_node_t *new_node;
    shash_node_t *sorted_current;

    if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    /*
     * Check if key already exists in the hash bucket.
     */
    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);

            current->value = strdup(value);

            if (current->value == NULL)
                return (0);

            return (1);
        }

        current = current->next;
    }

    /*
     * Create new node.
     */
    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    /*
     * Insert into hash bucket.
     */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /*
     * Initialize sorted-list pointers.
     */
    new_node->sprev = NULL;
    new_node->snext = NULL;

    /*
     * Empty sorted list.
     */
    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;

        return (1);
    }

    /*
     * Find the correct position in sorted list.
     */
    sorted_current = ht->shead;

    while (sorted_current != NULL &&
           strcmp(sorted_current->key, key) < 0)
    {
        sorted_current = sorted_current->snext;
    }

    /*
     * Insert at beginning.
     */
    if (sorted_current == ht->shead)
    {
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    /*
     * Insert at end.
     */
    else if (sorted_current == NULL)
    {
        new_node->sprev = ht->stail;
        ht->stail->snext = new_node;
        ht->stail = new_node;
    }
    /*
     * Insert in the middle.
     */
    else
    {
        new_node->snext = sorted_current;
        new_node->sprev = sorted_current->sprev;

        sorted_current->sprev->snext = new_node;
        sorted_current->sprev = new_node;
    }

    return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: sorted hash table
 * @key: key to search for
 *
 * Return: value associated with key, or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];

    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);

        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - prints the sorted hash table
 * @ht: sorted hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;
    int first;

    if (ht == NULL)
        return;

    current = ht->shead;
    first = 1;

    printf("{");

    while (current != NULL)
    {
        if (!first)
            printf(", ");

        printf("'%s': '%s'", current->key, current->value);

        first = 0;
        current = current->snext;
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table in reverse
 * @ht: sorted hash table
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;
    int first;

    if (ht == NULL)
        return;

    current = ht->stail;
    first = 1;

    printf("{");

    while (current != NULL)
    {
        if (!first)
            printf(", ");

        printf("'%s': '%s'", current->key, current->value);

        first = 0;
        current = current->sprev;
    }

    printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: sorted hash table
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current;
    shash_node_t *next;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];

        while (current != NULL)
        {
            next = current->next;

            free(current->key);
            free(current->value);
            free(current);

            current = next;
        }
    }

    free(ht->array);
    free(ht);
}

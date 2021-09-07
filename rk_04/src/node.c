#include "../inc/node.h"

node_t *create_node(char *word)
{
    node_t *node = malloc(sizeof(node_t));

    if (node)
    {
        node->word = malloc((sizeof(char *) * (strlen(word) + 1)));
        strcpy(node->word, word);
        node->next = NULL;
    }

    return node;
}

node_t *add_node(node_t *head, node_t *node)
{
    node_t *cur = head;

    if (!head)
        return node;

    for ( ; cur->next; cur = cur->next)
        ;
    
    cur->next = node;

    return head;
}
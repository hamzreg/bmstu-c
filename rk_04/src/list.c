#include "../inc/list.h"

void list_init(list_t *list)
{
    list->head = NULL;
    list->size = 0;
}


int read_list(list_t *list, const char *filename)
{
    FILE *in_file = fopen(filename, "r");

    if (!in_file)
        return ERROR_READ;

    char word[MAX_LEN];

    while (fgets(word, MAX_LEN, in_file) != NULL)
    {
        node_t *node = create_node(word);
        list->head = add_node(list->head, node);
    }

    if (fclose(in_file) != OK)
        return ERROR_READ;
    
    return OK;
}


int write_list(node_t *head, const char *filename)
{
    FILE *out_file = fopen(filename, "w");

    if (!out_file)
        return ERROR_READ;
    

    for ( ; head; head = head->next)
    {
        fprintf(out_file, "%s", head->word);
    }
    
    if (fclose(out_file) != OK)
        return ERROR_READ;
    
    return OK;
}

void free_list(node_t *head)
{
    node_t *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


int my_strlen(char *word)
{
    int i = 0;

    while (word[i] != '\0')
        i++;
    
    return i;
}


void reverse_word(char *word, char *new)
{
    int len = my_strlen(word);
    int k = 0;

    for (int j = len; j >= 0; j--)
        new[k++] = word[j];
    
    new[k] = '\0';
}


void reverse_list(node_t *head)
{
    for (; head; head = head->next)
    {
        char new[MAX_LEN];
        reverse_word(head->word, new);
        head->word = new;
    }
}

void print_list(node_t *head)
{
    node_t *node = head;

    for (; node; node = node->next)
    {
        printf("%s\n", node->word);
    }
}
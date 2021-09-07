#include "../inc/multiplier.h"


multiplier_t *create_multiplier(const int data)
{
    multiplier_t *multiplier = malloc(sizeof(multiplier_t));

    if (multiplier)
    {
        multiplier->value = data;
        multiplier->next = NULL;
    }

    return multiplier;
}


void multiplier_free(multiplier_t *multiplier)
{
    free(multiplier);
}


void add_multiplier_end(polynom_t *polynom, multiplier_t *multiplier)
{
    if (polynom->head == NULL)
    {
        polynom->head = multiplier;
        polynom->tail = multiplier;
    }
    else
    {
        polynom->tail->next = multiplier;
        multiplier->next = NULL;
        polynom->tail = multiplier;
    }
}


void delete_multiplier(polynom_t *polynom, const int position)
{
    multiplier_t *add_node = polynom->head, *prev_node = NULL;

    int i = 0;

    for (; add_node; add_node = add_node->next)
    {
        if (i == position)
        {
            if (prev_node)
                prev_node->next = add_node->next;
            else
                polynom->head = add_node->next;

            multiplier_free(add_node);

            return;
        }

        prev_node = add_node;

        i++;
    }
}

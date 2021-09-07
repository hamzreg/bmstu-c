#include "../inc/polynom.h"


void init_polynom(polynom_t *const polynom)
{
    polynom->power = NO_POWER;
    polynom->head = NULL;
    polynom->tail = NULL;
}


void free_polynom(multiplier_t *head)
{
    multiplier_t *node;

    for (; head; head = node)
    {
        node = head->next;
        multiplier_free(head);
    }
}


int input_polynom(polynom_t *polynom, int mode)
{
    int code = scanf("%d ", &polynom->power);

    if (!code)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }

    if (polynom->power < 0)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }
    LOG_INFO("Power is %d", polynom->power);

    if (mode == MODE_DVD)
        polynom->power++;

    int multiplier;
    multiplier_t *node;

    for (int i = 0; i < polynom->power; i++)
    {
        code = scanf("%d", &multiplier);

        if (!code)
        {
            free_polynom(polynom->head);
            return ERROR_MULTIPLIER;
        }

        node = create_multiplier(multiplier);
        add_multiplier_end(polynom, node);
        LOG_INFO("Element %d added", multiplier);
    }

    return OK;
}


int print_polynom(multiplier_t *head)
{
    for ( ; head; head = head->next)
        printf("%d ", head->value);

    printf("L\n");

    return OK;
}


int count_polunom_value(multiplier_t *head, const int data)
{
    int term, result = head->value;

    head = head->next;
    LOG_INFO("START: result = %d", result);

    for (; head; head = head->next)
    {
        term = head->value;
        result = result * data + term;

        LOG_INFO("NOW: term = %d, result = %d", term, result);
    }

    return result;
}


void differentiate_polynom(multiplier_t *head, const int power)
{
    int i = 0;

    for (; head; head = head->next)
    {
        head->value = head->value * (power - i - 1);
        i++;
    }
}


void add_polynoms(multiplier_t *first, multiplier_t *second)
{
    while (first)
    {
        first->value += second->value;

        second = second->next;
        first = first->next;
    }
}


void get_second_polynom(polynom_t *first, polynom_t *second)
{
    multiplier_t *add_node = first->head, *now;

    init_polynom(second);
    second->power = first->power - 1;

    int i = 0, count_deleted = 0;

    while(add_node)
    {
        LOG_INFO("Now is %d", add_node->value);

        if (i % 2 != 0)
        {
            now = create_multiplier(add_node->value);
            add_multiplier_end(second, now);

            add_node = add_node->next;
            delete_multiplier(first, i - count_deleted);
            count_deleted++;
        }
        else
            add_node = add_node->next;

        i++;
    }
}

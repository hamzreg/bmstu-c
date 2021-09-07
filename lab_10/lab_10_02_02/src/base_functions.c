#include "../inc/base_functions.h"

int process_polynom(void)
{
    char function[LEN_FUNCTION];
    scanf("%s", function);

    if (strlen(function) >= LEN_FUNCTION)
    {
        LOG_ERROR("%s", "Invalid command");
        return ERROR_INPUT;
    }

    if (strcmp(function, VAL) == 0)
    {
        return get_polynom_value();
    }
    else if (strcmp(function, DDX) == 0)
    {
        return get_derivative();
    }
    else if (strcmp(function, SUM) == 0)
    {
        return get_sum_polynoms();
    }
    else if (strcmp(function, DVD) == 0)
    {
        return divide_polynom();
    }

    return ERROR_INPUT;
}


int get_polynom_value(void)
{
    polynom_t polynom;

    init_polynom(&polynom);
    int code = input_polynom(&polynom, OTHER);

    if (code)
        return ERROR_INPUT;

    int data;
    code = scanf("%d", &data);

    if (!code)
        return ERROR_DATA;
    LOG_INFO("Data is %d", data);

    int result = count_polunom_value(polynom.head, data);

    free_polynom(polynom.head);

    printf("%d\n", result);

    return OK;
}


int get_derivative(void)
{
    polynom_t polynom;

    init_polynom(&polynom);
    int code = input_polynom(&polynom, OTHER);

    if (code)
        return ERROR_INPUT;

    differentiate_polynom(polynom.head, polynom.power);

    delete_multiplier(&polynom, polynom.power - 1);

    print_polynom(polynom.head);

    free_polynom(polynom.head);

    return OK;
}


int get_sum_polynoms(void)
{
    polynom_t first, second;

    init_polynom(&first);
    int code = input_polynom(&first, OTHER);

    if (code)
        return ERROR_INPUT;

    init_polynom(&second);
    code = input_polynom(&second, OTHER);

    if (code)
    {
        free_polynom(first.head);
        return ERROR_INPUT;
    }

    multiplier_t *add_node = first.head, *node = second.head;

    if (first.power > second.power)
    {
        for (int i = 0; i < first.power - second.power; i++)
            add_node = add_node->next;

        add_polynoms(add_node, node);
        print_polynom(first.head);
    }
    else
    {
        for (int i = 0; i < second.power - first.power; i++)
            node = node->next;

        add_polynoms(node, add_node);
        print_polynom(second.head);
    }

    free_polynom(first.head);
    free_polynom(second.head);

    return OK;
}


int divide_polynom(void)
{
    polynom_t first_polynom;

    init_polynom(&first_polynom);
    int code = input_polynom(&first_polynom, MODE_DVD);

    if (code)
        return ERROR_INPUT;

    if (first_polynom.power == POWER_ONE)
    {
        free_polynom(first_polynom.head);
        return EMPTY_RESULT_POLYNOM;
    }

    polynom_t second_polynom;
    get_second_polynom(&first_polynom, &second_polynom);

    if (first_polynom.power % 2 == 0)
    {
        print_polynom(second_polynom.head);
        print_polynom(first_polynom.head);
    }
    else
    {
        print_polynom(first_polynom.head);
        print_polynom(second_polynom.head);
    }

    free_polynom(first_polynom.head);
    free_polynom(second_polynom.head);

    return OK;
}

#include <stdio.h>
#include "process.h"

int compare_numbers(int const first_number, int const second_number)
{
    int product = first_number * second_number;

    if (first_number == 0)
    {
        if (second_number < 0)
            return DIFFERENT_SIGNS;
    }
    else if (second_number == 0)
    {
        if (first_number < 0)
            return DIFFERENT_SIGNS;
    }

    if (product < 0)
        return DIFFERENT_SIGNS;

    return EQUAL_SIGNS;
}

int process(FILE *f, int *const number_sign_changes)
{
    int now_number, last_number, count = 1;

    if (fscanf(f, "%d", &last_number) == 1)
    {
        while (fscanf(f, "%d", &now_number) == 1)
        {
            *number_sign_changes += compare_numbers(last_number, now_number);
            last_number = now_number;
            count++;
        }

        if (count == 1)
            return ONE_NUMBER;

        return OK;
    }

    return NO_NUMBERS;
}

#include <stdio.h>
#include "count_numbers_more_average.h"

void count_numbers_more_average(FILE *f, int *const amount, const float average)
{
    *amount = 0;
    float number;

    while (fscanf(f, "%f", &number) == 1)
        if (number > average)
            *amount += 1;
}

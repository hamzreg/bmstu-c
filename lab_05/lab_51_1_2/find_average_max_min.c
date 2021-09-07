#include <stdio.h>
#include "find_average_max_min.h"

int find_average_max_min(FILE *f, float *const average)
{
    float number, maximum, minimum;

    if (fscanf(f, "%f", &minimum) == 1)
    {
        maximum = minimum;

        while (fscanf(f, "%f", &number) == 1)
        {
            if (number < minimum)
                minimum = number;

            if (number > maximum)
                maximum = number;
        }

        *average = (maximum + minimum) / 2;
        return OK;
    }

    return NO_FLOAT_NUMBERS;
}

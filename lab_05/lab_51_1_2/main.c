#include <stdio.h>
#include "error_codes.h"
#include "find_average_max_min.h"
#include "count_numbers_more_average.h"

int main(int argc, char **argv)
{
    FILE *f;
    float average;
    int amount;

    if (argc != 2)
    {
        fprintf(stderr, "File name not received");
        return NO_FILE_NAME;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        fprintf(stderr, "Error entering file name");
        return ERROR_FILE_NAME;
    }

    int code = find_average_max_min(f, &average);

    if (fclose(f) != OK)
    {
        fprintf(stderr, "Error close file");
        return ERROR_CLOSE_FILE;
    }

    if (code != OK)
    {
        fprintf(stderr, "There are no float numbers in the file");
        return code;
    }

    f = fopen(argv[1], "r");

    count_numbers_more_average(f, &amount, average);

    if (fclose(f) != OK)
    {
        fprintf(stderr, "Error close file");
        return ERROR_CLOSE_FILE;
    }

    printf("The amount of numbers more than average of max and min is %d", amount);

    return OK;
}

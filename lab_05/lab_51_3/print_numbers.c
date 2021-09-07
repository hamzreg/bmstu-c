#include <stdio.h>
#include "print_numbers.h"

int print_numbers(FILE *f)
{
    int number;
    size_t file_size;
    int rc = 0;

    rc = find_file_size(f, &file_size);

    if (rc != 0)
        return FILE_SIZE_ERROR;

    if (file_size % sizeof(int) != 0)
        return FILE_SIZE_ERROR;

    if (file_size != 0)
    {
        while (fread(&number, sizeof(int), 1, f))
            printf("%d ", number);
        return OK;
    }

    return FILE_SIZE_ERROR;
}

#include <stdio.h>
#include "find_file_size.h"

int find_file_size(FILE *f, size_t *file_size)
{
    long size;

    if (fseek(f, 0L, SEEK_END))
       return FILE_SIZE_ERROR;

    size = ftell(f);

    if (size < 0)
        return FILE_SIZE_ERROR;

    *file_size = size;

    return fseek(f, 0L, SEEK_SET);
}

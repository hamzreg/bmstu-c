#include "file_size.h"
#include "return_codes.h"

int check_file_size(FILE *f)
{
    long size;

    if (fseek(f, 0L, SEEK_END))
        return FILE_SIZE_ERROR;

    size = ftell(f);

    if (size <= 0)
        return FILE_SIZE_ERROR;

    return fseek(f, 0L, SEEK_SET);
}

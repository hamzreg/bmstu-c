#include <stdio.h>
#include <stdlib.h>
#include "create_file.h"

int create_file(FILE *f)
{
    int number;
    size_t wrote;
    int rc = 0;
    int i = 0;
    int amount = rand();

    while (!rc && (i < amount)) 
    {
        number = rand();
        wrote = fwrite(&number, sizeof(int), 1, f);
        i++;

        rc = (wrote != 1);
    }

    if (rc == 0)
        return OK;

    return WRITE_ERROR;
}

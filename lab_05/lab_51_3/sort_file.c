#include <stdio.h>
#include "sort_file.h"

void get_number_by_pos(FILE *f, const int offset, int *const number)
{
    fseek(f, offset * sizeof(int), SEEK_SET);

    fread(number, sizeof(int), 1, f);
}

void put_number_by_pos(FILE *f, const int offset, const int number)
{
    fseek(f, offset * sizeof(int), SEEK_SET);

    fwrite(&number, sizeof(int), 1, f);
}

int sort_file(FILE *f)
{
    int number_one, number_two;
    size_t file_size;
    int rc = 0;
    int amount;

    rc = find_file_size(f, &file_size);

    if (rc != 0)
        return FILE_SIZE_ERROR;

    if (file_size % sizeof(int) != 0)
        return FILE_SIZE_ERROR;

    amount = file_size / sizeof(int);

    if (amount == 0)
        return FILE_SIZE_ERROR;

    for (int i = 0; i < amount; i++)
    {
        for (int j = amount - 1; j > i; j--)
        {
            get_number_by_pos(f, j, &number_one);
            get_number_by_pos(f, j - 1, &number_two);

            if (number_two > number_one)
            {
                put_number_by_pos(f, j - 1, number_one);
                put_number_by_pos(f, j, number_two);
            }
        }
    }

    return OK;
}

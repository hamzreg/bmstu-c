#include <stdio.h>
#include <stdlib.h>
#include "matrix_t.h"
#include "matrix.h"

#define OK 0
#define ERROR 1

int main(int argc, char **argv)
{
    FILE *in_file = fopen(argv[1], "r");

    if (in_file == NULL)
    {
        printf("File open error");
        return ERROR;
    }

    matrix_t matrix;
    read_matrix(in_file, &matrix);
    fclose(in_file);

    replace_zero(&matrix);

    delete_full_zero_rows(&matrix);

    FILE *out_file = fopen(argv[2], "w");

    write_matrix_in_file(out_file, matrix);
    free(matrix.data);
    fclose(out_file);

    return OK;
}
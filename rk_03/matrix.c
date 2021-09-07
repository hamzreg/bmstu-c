#include <stdio.h>
#include "matrix_t.h"
#include "matrix.h"
#include <stdlib.h>

int read_matrix(FILE *in_file, matrix_t *matrix)
{
    int rows, columns;

    if (fscanf(in_file, "%d %d", &rows, &columns) == 1)
    {
        matrix->rows = rows;
        matrix->columns = columns;

        matrix->data = malloc(matrix->rows * matrix->columns * sizeof(int));

        if (matrix->data == NULL)
        {
            printf("Allocate error\n");
            return ERROR_ALLOCATE;
        }

        for (int i = 0; i < matrix->rows; i++)
            for (int j = 0; j < matrix->columns; j++)
                fscanf(in_file, "%d", &matrix->data[i * matrix->columns + j]);

        return OK;
    }

    return DATA_ERROR;
}


int get_count_unit(matrix_t *matrix, const int row, const int column)
{
    int count_unit = 0;

    if (column - 1 >= MIN_COLUMN && row - 1 >= MIN_ROW && column + 1 < matrix->columns && row + 1 < matrix->rows)
    {
        if (matrix->data[row * matrix->columns + column - 1] == MAGIC_ELEMENT)
            count_unit++;
        
        if (matrix->data[row * matrix->columns + column + 1] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row - 1) * matrix->columns + column] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row - 1) * matrix->columns + column - 1] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row - 1) * matrix->columns + column + 1] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row + 1) * matrix->columns + column] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row + 1) * matrix->columns + column + 1] == MAGIC_ELEMENT)
            count_unit++;

        if (matrix->data[(row + 1) * matrix->columns + column - 1] == MAGIC_ELEMENT)
            count_unit++;
    }

    return count_unit;
}


void replace_zero(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            if (matrix->data[i * matrix->columns + j] == 0)
                matrix->data[i * matrix->columns + j] = get_count_unit(matrix, i, j);
}


void shift(matrix_t *matrix, const int row)
{
    for (int i = row; i < matrix->rows - 1; i++)
        for (int j = 0; j < matrix->columns; j++)
            matrix->data[i * matrix->columns + j] = matrix->data[(i + 1) * matrix->columns +j];
}


void delete_full_zero_rows(matrix_t *matrix)
{
    int count_zero;

    for (int i = 0; i < matrix->rows; i++)
    {
        count_zero = 0;
        
        for (int j = 0; j < matrix->columns; j++)
        {
            if (matrix->data[i * matrix->columns + j] == 0)
                count_zero++;
        }

        if (count_zero == matrix->columns)
        {
            matrix->rows--;
            shift(matrix, i);
        }
    }
}


void get_count_not_zero(matrix_t matrix, int *count_not_zero)
{
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            if (matrix.data[i * matrix.columns + j] != 0)
                count_not_zero++;
}


void write_matrix_in_file(FILE *out_file, matrix_t matrix)
{
    int count_not_zero = 0;
    get_count_not_zero(matrix, &count_not_zero);

    fprintf(out_file, "%d %d %d\n", matrix.rows, matrix.columns, count_not_zero);

    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
            if (matrix.data[i * matrix.columns + j] != 0)
                fprintf(out_file, "%d %d %d\n", i + 1, j + 1, matrix.data[i * matrix.columns + j]); 
}

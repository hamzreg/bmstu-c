#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../inc/matrix.h"


void free_matrix(int **matrix, const int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
}


int **allocate_matrix(const int rows, const int columns)
{
    int **matrix = calloc(rows, sizeof(int *));

    if (!matrix)
        return NULL;
    
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(columns * sizeof(int));

        if (!matrix[i])
        {
            free_matrix(matrix, rows);
            return NULL;
        }
    }

    return matrix;
}


int input_matrix(matrix_t *matrix)
{
    int rows, columns;

    if (scanf("%d", &rows) != 1 || rows < MIN_SIZE)
    {
        LOG_ERROR("%s", "Invalid rows count");
        return ERROR_ROWS;
    }
    matrix->rows = rows;

    if (scanf("%d", &columns) != 1 || columns < MIN_SIZE)
    {
        LOG_ERROR("%s", "Invalid columns count");
        return ERROR_COLUMNS;
    }
    matrix->columns = columns;

    matrix->matrix = allocate_matrix(matrix->rows, matrix->columns);

    if (matrix->matrix == NULL)
    {
        LOG_ERROR("%s", "Allocate error");
        return ERROR_ALLOCATE;
    }

    int number;
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (scanf("%d", &number) != 1)
            {
                free_matrix(matrix->matrix, matrix->rows);
                LOG_ERROR("%s", "Invalid number");
                return ERROR_NUMBER;
            }

            *(*(matrix->matrix + i) + j) = number;
        }
    }

    return OK;
}


void print_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
            printf("%d ", *(*(matrix->matrix + i) + j));
        
        if (i != matrix->rows - 1)
            printf("\n");
    }
}


void search_max_number_position(int *const i_max, int *const j_max, matrix_t *matrix)
{
    int maximum = *(*(matrix->matrix + matrix->rows - 1) + matrix->columns - 1);
    *i_max = matrix->rows - 1;
    *j_max = matrix->columns - 1;

    for (int j = matrix->columns - 1; j > -1; j--)
    {
        for (int i = matrix->rows - 1; i > -1; i--)
        {
            if (*(*(matrix->matrix + i) + j) > maximum)
            {
                *i_max = i;
                *j_max = j;
                maximum = *(*(matrix->matrix + i) + j);
            }
        }
    }
}


void shift_row(matrix_t *matrix, const int max_i)
{
    for (int i = max_i; i < matrix->rows - 1; i++)
        for (int j = 0; j < matrix->columns; j++)
            *(*(matrix->matrix + i) + j) = *(*(matrix->matrix + i + 1) + j);
    free(matrix->matrix[matrix->rows - 1]);
}


void shift_column(matrix_t *matrix, const int max_j)
{
    for (int j = max_j; j < matrix->columns - 1; j++)
        for (int i = 0; i < matrix->rows; i++)
            *(*(matrix->matrix + i) + j) = *(*(matrix->matrix + i) + j + 1);
}


int reduce_matrix(matrix_t *matrix)
{
    if (!matrix->matrix)
        return EMPTY_MATRIX;
    
    int count;
    int max_i, max_j;
    if (matrix->rows > matrix->columns)
    {
        count = matrix->rows - matrix->columns;

        while (count)
        {
            search_max_number_position(&max_i, &max_j, matrix);
            shift_row(matrix, max_i);
            matrix->rows--;
            count--;
        }

        int **matrix_pointer = realloc(matrix->matrix, matrix->rows * sizeof(int *));

        if (matrix_pointer)
            matrix->matrix = matrix_pointer;
        else
        {
            free(matrix_pointer);
            LOG_ERROR("%s", "Memory allocation error");
            return ERROR_ALLOCATE;
        }
    }

    if (matrix->columns > matrix->rows)
    {
        count = matrix->columns - matrix->rows;

        while (count)
        {
            search_max_number_position(&max_i, &max_j, matrix);
            shift_column(matrix, max_j);
            matrix->columns--;
            count--;
        }

        for (int i = 0; i < matrix->rows; i++)
        {
            int *row_pointer = realloc(matrix->matrix[i], matrix->columns * sizeof(int));

            if (row_pointer)
                matrix->matrix[i] = row_pointer;
            else
            {
                free(row_pointer);
                LOG_ERROR("%s", "Memory allocation error");
                return ERROR_ALLOCATE;
            }
        }
    }
    return OK;
}


void add_row(matrix_t *matrix)
{
    float average = 0;

    for (int j = 0; j < matrix->columns; j++)
    {
        average = 0;

        for (int i = 0; i < matrix->rows - 1; i++)
            average += *(*(matrix->matrix + i) + j);
        average /= matrix->rows - 1;
    
        *(*(matrix->matrix + matrix->rows - 1) + j) = (int)floor(average);
    }
}


void add_column(matrix_t *matrix)
{
    int minimum;
    for (int i = 0; i < matrix->rows; i++)
    {
        minimum = *(*(matrix->matrix + i));

        for (int j = 0; j < matrix->columns - 1; j++)
            if (*(*(matrix->matrix + i) + j) < minimum)
                minimum = *(*(matrix->matrix + i) + j);

        *(*(matrix->matrix + i) + matrix->columns - 1) = minimum;
    }
}


int get_max_size(const int one_size, const int two_size, int *const result_size)
{
    if (one_size > two_size)
    {
        *result_size = one_size;
        return SIZE_A;
    }
    else if (two_size > one_size)
    {
        *result_size = two_size;
        return SIZE_B;
    }

    return SAME;
}


int enlarge_matrix(matrix_t *matrix, const int size)
{
    if (!matrix->matrix)
        return EMPTY_MATRIX;
    
    int **matrix_pointer = realloc(matrix->matrix, size * sizeof(int *));

    if (matrix_pointer)
        matrix->matrix = matrix_pointer;
    else
    {
        free(matrix_pointer);
        LOG_ERROR("%s", "Memory allocation error");
        return ERROR_ALLOCATE;
    }
    
    int count = size - matrix->rows;

    while (count)
    {
        matrix->matrix[matrix->rows] = malloc(matrix->columns * sizeof(int));

        if (!matrix->matrix[matrix->rows])
        {
            free_matrix(matrix->matrix, matrix->rows);
            LOG_ERROR("%s", "Memory allocation error");
            return ERROR_ALLOCATE;
        }

        matrix->rows++;
        add_row(matrix);
        count--;
    }

    count = size - matrix->columns;

    for (int i = 0; i < matrix->rows; i++)
    {
        int *row_pointer = realloc(matrix->matrix[i], size * sizeof(int));

        if (row_pointer)
            matrix->matrix[i] = row_pointer;
        else
        {
            free(row_pointer);
            LOG_ERROR("%s", "Memory allocation error");
            return ERROR_ALLOCATE;
        }
    }

    while (count)
    {
        matrix->columns++;
        add_column(matrix);
        count--;
    }
 
    return OK;
}


int multiplicate(matrix_t matrix_a, matrix_t matrix_b, matrix_t *result)
{
    if (!matrix_a.matrix || !matrix_b.matrix)
        return EMPTY_MATRIX;

    result->rows = matrix_a.rows;
    result->columns = matrix_a.columns;

    int sum;
 
    for (int i = 0; i < matrix_a.rows; i++)
    {
        for (int j = 0; j < matrix_b.columns; j++)
        {
            sum = 0;
            for (int k = 0; k < matrix_a.rows; k++)
                sum += *(*(matrix_a.matrix + i) + k) * *(*(matrix_b.matrix + k) + j);
            *(*(result->matrix + i) + j) = sum;
        }
    }

    return OK;
}


int input_powers(int *const power_a, int *const power_b)
{
    if (scanf("%d", power_a) != 1)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }

    if (*power_a < 0)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }

    if (scanf("%d", power_b) != 1)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }

    if (*power_b < 0)
    {
        LOG_ERROR("%s", "Invalid power");
        return ERROR_POWER;
    }

    return OK;
}


void get_identity_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (i == j)
                *(*(matrix->matrix + i) + j) = 1;
            else
                *(*(matrix->matrix + i) + j) = 0;
        }
    }
}


void copy_matrix(matrix_t *result_matrix, matrix_t *first_matrix)
{
    for (int i = 0; i < result_matrix->rows; i++)
        for (int j = 0; j < result_matrix->columns; j++)
            *(*(result_matrix->matrix + i) + j) = *(*(first_matrix->matrix + i) + j);
}


int pow_matrix(matrix_t *matrix, const int power)
{
    if (power == ZERO)
        get_identity_matrix(matrix);
    else
    {
        matrix_t first_matrix, add_matrix;

        first_matrix.rows = matrix->rows;
        first_matrix.columns = matrix->columns;
        add_matrix.rows = matrix->rows;
        add_matrix.columns = matrix->columns;

        first_matrix.matrix = allocate_matrix(first_matrix.rows, first_matrix.columns);

        if (first_matrix.matrix == NULL)
        {
            LOG_ERROR("%s", "Memory allocated error\n");
            return ERROR_ALLOCATE;
        }

        add_matrix.matrix = allocate_matrix(add_matrix.rows, add_matrix.columns);

        if (add_matrix.matrix == NULL)
        {
            free_matrix(first_matrix.matrix, first_matrix.rows);
            LOG_ERROR("%s", "Memory allocated error\n");
            return ERROR_ALLOCATE;
        }

        copy_matrix(&first_matrix, matrix);

        for (int i = 0; i < power - 1; i++)
        {
            copy_matrix(&add_matrix, matrix);
            multiplicate(add_matrix, first_matrix, matrix);
        }
        
        free_matrix(add_matrix.matrix, add_matrix.rows);
        free_matrix(first_matrix.matrix, first_matrix.rows);
    }

    return OK;
}
#include <stdio.h>
#include "../inc/base_functions.h"

int input_matrixs(matrix_t *matrix_a, matrix_t *matrix_b)
{
    int code = input_matrix(matrix_a);

    if (code != OK)
        return code;
    
    code = input_matrix(matrix_b);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        return code;
    }
    
    return OK;
}


int process_matrixs(matrix_t *matrix_a, matrix_t *matrix_b)
{
    int code = reduce_matrix(matrix_a);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return code;
    }
    LOG_INFO("%s", "Matrix A reduced");

    code = reduce_matrix(matrix_b);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return code;
    }
    LOG_INFO("%s", "Matrix B reduced");

    int size;

    if (get_max_size(matrix_a->rows, matrix_b->rows, &size) == SIZE_A)
    {
        code = enlarge_matrix(matrix_b, size);

        if (code != OK)
        {
            free_matrix(matrix_a->matrix, matrix_a->rows);
            free_matrix(matrix_b->matrix, matrix_b->rows);
            return code;
        }
        LOG_INFO("%s", "Matrix A enlarged");
    }
    else if (get_max_size(matrix_a->rows, matrix_b->rows, &size) == SIZE_B)
    {
        code = enlarge_matrix(matrix_a, size);

        if (code != OK)
        {
            free_matrix(matrix_a->matrix, matrix_a->rows);
            free_matrix(matrix_b->matrix, matrix_b->rows);
            return code;
        }
        LOG_INFO("%s", "Matrix B enlarged");
    }
    
    int power_a, power_b;

    code = input_powers(&power_a, &power_b);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);
        return code;
    }
    
    code = pow_matrix(matrix_a, power_a);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);

        return code;
    }
    LOG_INFO("%s", "Matrix A powered");

    code = pow_matrix(matrix_b, power_b);

    if (code != OK)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->rows);

        return code;
    }
    LOG_INFO("%s", "Matrix B powered");

    return OK;
}


int get_result_matrix(matrix_t *matrix_a, matrix_t *matrix_b)
{
    matrix_t result;

    result.matrix = allocate_matrix(matrix_a->rows, matrix_a->columns);

    if (result.matrix == NULL)
    {
        free_matrix(matrix_a->matrix, matrix_a->rows);
        free_matrix(matrix_b->matrix, matrix_b->columns);
        return ERROR_ALLOCATE;
    }

    int code = multiplicate(*matrix_a, *matrix_b, &result);

    free_matrix(matrix_a->matrix, matrix_a->rows);
    free_matrix(matrix_b->matrix, matrix_b->rows);

    if (code != OK)
        return code;

    LOG_INFO("%s", "result matrix");
    print_matrix(&result);
    free_matrix(result.matrix, result.rows);

    return OK;
}
#include <stdio.h>
#include <stdlib.h>
#include "../inc/macrologger.h"
#include "../inc/base_functions.h"
#include "../inc/matrix.h"
#include "../inc/matrix_t.h"
#include "../inc/errors.h"
#include "../inc/constants.h"

int main(void)
{
    matrix_t matrix_a, matrix_b;

    int code = input_matrixs(&matrix_a, &matrix_b);

    if (code != OK)
        return code;

    code = process_matrixs(&matrix_a, &matrix_b);

    if (code != OK)
        return code;

    code = get_result_matrix(&matrix_a, &matrix_b);

    if (code != OK)
        return code;

    return OK;
}
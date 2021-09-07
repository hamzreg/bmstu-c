#include "../inc/check_matrix.h"


int compare_matrixs(matrix_t first_matrix, matrix_t second_matrix)
{
    if (first_matrix.rows != second_matrix.rows || \
       first_matrix.columns != second_matrix.columns)
        return NOT_EQUAL;

    for (int i = 0; i < first_matrix.rows; i++)
    {
        for (int j = 0; j < first_matrix.columns; j++)
        {
            if (*(*(first_matrix.matrix + i) + j) != *(*(second_matrix.matrix + i) + j))
                return NOT_EQUAL;
        }
    }

    return EQUAL;
}


void fill_matrix(matrix_t *matrix)
{
    matrix->columns = matrix->rows = MATRIX_SIZE;

    matrix->matrix = allocate_matrix(matrix->rows, matrix->columns);

    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            *(*(matrix->matrix + i) + j) = i;
}


void fill_result(matrix_t *matrix)
{
    matrix->columns = matrix->rows = MATRIX_SIZE;

    matrix->matrix = allocate_matrix(matrix->rows, matrix->columns);

    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
            *(*(matrix->matrix + i) + j) = i * 3;
}

START_TEST(test_multiplicate_empty_first_matrix)
{
    matrix_t matrix_a = {NULL, MATRIX_SIZE, MATRIX_SIZE}, matrix_b, result;
    fill_matrix(&matrix_b);
    fill_matrix(&result);

    int rc = multiplicate(matrix_a, matrix_b, &result);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(result.matrix, result.rows);
    ck_assert_int_eq(rc, EMPTY_MATRIX);
}
END_TEST


START_TEST(test_multiplicate_empty_second_matrix)
{
    matrix_t matrix_a, matrix_b = {NULL, MATRIX_SIZE, MATRIX_SIZE}, result;
    fill_matrix(&matrix_a);
    fill_matrix(&result);

    int rc = multiplicate(matrix_a, matrix_b, &result);
    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(result.matrix, result.rows);
    ck_assert_int_eq(rc, EMPTY_MATRIX);
}
END_TEST


START_TEST(test_multiplicate_usual_matrixs)
{
    int code = NOT_EQUAL;
    matrix_t matrix_a, matrix_b, result, true_matrix;

    result.matrix = allocate_matrix(MATRIX_SIZE, MATRIX_SIZE);

    if (result.matrix)
    {
        fill_matrix(&matrix_a);
        fill_matrix(&matrix_b);
        fill_result(&true_matrix);

        int rc = multiplicate(matrix_a, matrix_b, &result);
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);

        if (!rc)
            code = compare_matrixs(result, true_matrix);

        free_matrix(result.matrix, result.rows);
        free_matrix(true_matrix.matrix, true_matrix.rows);
    }
    ck_assert_int_eq(code, EQUAL);
}
END_TEST


START_TEST(test_multiplicate_identity_matrixs)
{
    int code = NOT_EQUAL;
    matrix_t matrix_a, matrix_b, result, true_matrix;

    result.matrix = allocate_matrix(MATRIX_SIZE, MATRIX_SIZE);

    if (result.matrix)
    {
        fill_matrix(&matrix_a);
        fill_matrix(&matrix_b);
        get_identity_matrix(&matrix_b);
        fill_matrix(&true_matrix);
        int rc = multiplicate(matrix_a, matrix_b, &result);
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);

        if (!rc)
            code = compare_matrixs(result, true_matrix);

        free_matrix(result.matrix, result.rows);
        free_matrix(true_matrix.matrix, true_matrix.rows);
    }

    ck_assert_int_eq(code, EQUAL);
}
END_TEST


Suite *multiplicate_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("multiplicate");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_multiplicate_empty_first_matrix);
    tcase_add_test(tc_neg, test_multiplicate_empty_second_matrix);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_multiplicate_usual_matrixs);
    tcase_add_test(tc_pos, test_multiplicate_identity_matrixs);
    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_zero_power)
{
    int power = 0;
    int code = NOT_EQUAL;
    matrix_t matrix, true_matrix;
    fill_matrix(&matrix);
    fill_matrix(&true_matrix);
    get_identity_matrix(&true_matrix);

    pow_matrix(&matrix, power);
    code = compare_matrixs(matrix, true_matrix);
    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(true_matrix.matrix, true_matrix.rows);
    ck_assert_int_eq(code, EQUAL);
}
END_TEST


START_TEST(test_one_power)
{
    int power = 1;
    int code = NOT_EQUAL;
    matrix_t matrix, true_matrix;
    fill_matrix(&matrix);
    fill_matrix(&true_matrix);

    pow_matrix(&matrix, power);
    code = compare_matrixs(matrix, true_matrix);
    free_matrix(matrix.matrix, matrix.rows);
    free_matrix(true_matrix.matrix, true_matrix.rows);
    ck_assert_int_eq(code, EQUAL);
}
END_TEST


START_TEST(test_usual_power)
{
    int power = 2;
    int code = NOT_EQUAL;
    matrix_t matrix, true_matrix;

    true_matrix.matrix = allocate_matrix(MATRIX_SIZE, MATRIX_SIZE);

    if (true_matrix.matrix)
    {
        fill_matrix(&matrix);
        multiplicate(matrix, matrix, &true_matrix);

        pow_matrix(&matrix, power);
        code = compare_matrixs(matrix, true_matrix);
        free_matrix(matrix.matrix, matrix.rows);
        free_matrix(true_matrix.matrix, true_matrix.rows);
        ck_assert_int_eq(code, EQUAL);
    }
}
END_TEST


Suite *pow_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pow_matrix");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_zero_power);
    tcase_add_test(tc_pos, test_one_power);
    tcase_add_test(tc_pos, test_usual_power);
    suite_add_tcase(s, tc_pos);

    return s;
}
#include "../inc/check_polynom.h"

void fill_polynom(polynom_t *polynom)
{
    polynom->power = 4;
    multiplier_t *node;

    for (int i = 0; i < polynom->power; i++)
    {
        node = create_multiplier(polynom->power - i);
        add_multiplier_end(polynom, node);
    }
}


void fill_derivative(polynom_t *polynom)
{
    polynom->power = 3;
    multiplier_t *node;

    node = create_multiplier(12);
    add_multiplier_end(polynom, node);

    node = create_multiplier(6);
    add_multiplier_end(polynom, node);

    node = create_multiplier(2);
    add_multiplier_end(polynom, node);
}


void fill_add_polynom(polynom_t *polynom)
{
    polynom->power = 4;
    multiplier_t *node;

    for (int i = 0; i < polynom->power; i++)
    {
        node = create_multiplier((polynom->power - i) * 2);
        add_multiplier_end(polynom, node);
    }
}


int compare_polynoms(multiplier_t *first, multiplier_t *second)
{
    for ( ; first; first = first->next)
    {
        if (first->value != second->value)
            return NOT_EQUAL;

        second = second->next;
    }

    return EQUAL;
}


START_TEST(test_get_value)
{
    polynom_t polynom;
    init_polynom(&polynom);
    fill_polynom(&polynom);

    int data = 7, true_result = 1534;
    int result = count_polunom_value(polynom.head, data);

    free_polynom(polynom.head);

    ck_assert_int_eq(true_result, result);
}
END_TEST


Suite *get_value_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("get_value");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_get_value);
    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_differentiate)
{
    polynom_t polynom;
    init_polynom(&polynom);
    fill_polynom(&polynom);

    polynom_t result;
    init_polynom(&result);
    fill_derivative(&result);

    differentiate_polynom(polynom.head, polynom.power);
    delete_multiplier(&polynom, polynom.power - 1);
    int code = compare_polynoms(polynom.head, result.head);

    free_polynom(polynom.head);
    free_polynom(result.head);

    ck_assert_int_eq(code, EQUAL);
}
END_TEST


Suite *get_derivative_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("differentiate");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_differentiate);
    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_add_polynoms)
{
    polynom_t first;
    init_polynom(&first);
    fill_polynom(&first);

    polynom_t second;
    init_polynom(&second);
    fill_polynom(&second);

    polynom_t result;
    init_polynom(&result);
    fill_add_polynom(&result);

    add_polynoms(first.head, second.head);
    int code = compare_polynoms(first.head, result.head);

    free_polynom(first.head);
    free_polynom(second.head);
    free_polynom(result.head);

    ck_assert_int_eq(code, EQUAL);
}
END_TEST


Suite *add_polynoms_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("add_polynoms");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_add_polynoms);
    suite_add_tcase(s, tc_pos);

    return s;
}

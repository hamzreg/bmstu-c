#include "../inc/check_my_snprintf.h"


START_TEST(test_one_character)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    char symbol = 'a';

    int count_read = my_snprintf(my_result, TEST_LEN, "%c", symbol);
    int true_count = snprintf(true_result, TEST_LEN, "%c", symbol);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


START_TEST(test_several_characters)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    char a = 'a', b = 'b', d = 'd';

    int count_read = my_snprintf(my_result, TEST_LEN, "%c %c%c", a, b, d);
    int true_count = snprintf(true_result, TEST_LEN, "%c %c%c", a, b, d);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


Suite *char_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("%c");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_one_character);
    tcase_add_test(tc_pos, test_several_characters);
    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_one_short_integer)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    short int number = SHRT_MAX;

    int count_read = my_snprintf(my_result, TEST_LEN, "Score is %hd!", number);
    int true_count = snprintf(true_result, TEST_LEN, "Score is %hd!", number);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


START_TEST(test_several_short_integer)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    short int a = SHRT_MIN, b = 5, c = 0;

    int count_read = my_snprintf(my_result, TEST_LEN, "%hd %hd%hd", a, b, c);
    int true_count = snprintf(true_result, TEST_LEN, "%hd %hd%hd", a, b, c);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


Suite *short_integer_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("%hd");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_one_short_integer);
    tcase_add_test(tc_pos, test_several_short_integer);

    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_string_empty)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    char string [] = "";

    int count_read = my_snprintf(my_result, TEST_LEN, "%s", string);
    int true_count = snprintf(true_result, TEST_LEN, "%s", string);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


START_TEST(test_one_string)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    char string [] = "Hello, world!";

    int count_read = my_snprintf(my_result, TEST_LEN, "%s", string);
    int true_count = snprintf(true_result, TEST_LEN, "%s", string);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


START_TEST(test_several_string)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    char first [] = "Hello,";
    char second [] = "world!";

    int count_read = my_snprintf(my_result, TEST_LEN, "%s %s", first, second);
    int true_count = snprintf(true_result, TEST_LEN, "%s %s", first, second);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


Suite *string_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("%s");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_string_empty);
    tcase_add_test(tc_pos, test_one_string);
    tcase_add_test(tc_pos, test_several_string);

    suite_add_tcase(s, tc_pos);

    return s;
}


START_TEST(test_one_octal)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    unsigned int number = 0;

    int count_read = my_snprintf(my_result, TEST_LEN, "%o!", number);
    int true_count = snprintf(true_result, TEST_LEN, "%o!", number);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


START_TEST(test_several_octal)
{
    char *my_result = malloc(TEST_LEN * sizeof(char));

    if (!my_result)
        return;

    char *true_result = malloc(TEST_LEN * sizeof(char));

    if (!true_result)
    {
        free(my_result);
        return;
    }

    int a = UINT_MAX, b = 5, c = 120;

    int count_read = my_snprintf(my_result, TEST_LEN, "%o %o%o", a, b, c);
    int true_count = snprintf(true_result, TEST_LEN, "%o %o%o", a, b, c);

    int code = true_count - count_read;

    code += my_strcmp(my_result, true_result);

    free(my_result);
    free(true_result);

    ck_assert_int_eq(code, OK);
}
END_TEST


Suite *octal_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("%o");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_one_octal);
    tcase_add_test(tc_pos, test_several_octal);
    suite_add_tcase(s, tc_pos);

    return s;
}

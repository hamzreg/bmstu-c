#include "../inc/check_main.h"

int main(void)
{
    Suite *set_char = char_suite();
    SRunner *runner_char = srunner_create(set_char);
    srunner_run_all(runner_char, CK_VERBOSE);
    int errors = srunner_ntests_failed(runner_char);
    srunner_free(runner_char);

    Suite *set_short_int = short_integer_suite();
    SRunner *runner_short_int = srunner_create(set_short_int);
    srunner_run_all(runner_short_int, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_short_int);
    srunner_free(runner_short_int);

    Suite *set_string = string_suite();
    SRunner *runner_string = srunner_create(set_string);
    srunner_run_all(runner_string, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_string);
    srunner_free(runner_string);

    Suite *set_octal = octal_suite();
    SRunner *runner_octal = srunner_create(set_octal);
    srunner_run_all(runner_octal, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_octal);
    srunner_free(runner_octal);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

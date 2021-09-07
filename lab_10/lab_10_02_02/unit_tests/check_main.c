#include "../inc/check_main.h"

int main(void)
{
    Suite *set_value = get_value_suite();
    SRunner *runner_value = srunner_create(set_value);
    srunner_run_all(runner_value, CK_VERBOSE);
    int errors = srunner_ntests_failed(runner_value);
    srunner_free(runner_value);

    Suite *set_derivative = get_derivative_suite();
    SRunner *runner_derivative = srunner_create(set_derivative);
    srunner_run_all(runner_derivative, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_derivative);
    srunner_free(runner_derivative);

    Suite *set_sum = add_polynoms_suite();
    SRunner *runner_sum = srunner_create(set_sum);
    srunner_run_all(runner_sum, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_sum);
    srunner_free(runner_sum);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

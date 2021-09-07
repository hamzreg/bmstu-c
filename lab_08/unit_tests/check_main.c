#include "../inc/check_main.h"

int main(void)
{
    Suite *set_multiplicate = multiplicate_suite();
    SRunner *runner_multiplicate = srunner_create(set_multiplicate);
    srunner_run_all(runner_multiplicate, CK_VERBOSE);
    int errors = srunner_ntests_failed(runner_multiplicate);
    srunner_free(runner_multiplicate);

    Suite *set_pow = pow_matrix_suite();
    SRunner *runner_pow = srunner_create(set_pow);
    srunner_run_all(runner_pow, CK_VERBOSE);
    errors += srunner_ntests_failed(runner_pow);
    srunner_free(runner_pow);

    return (errors == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
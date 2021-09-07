#include "../inc/base_functions.h"

int main(int argc, char **argv)
{
    int code = check_argc(argc, argv);

    if (code)
        return code;

    array_t array;

    code = read_array(argv[1], &array);

    if (code)
        return code;

    code = write_array(argv[2], &array, argc);

    return code;
}

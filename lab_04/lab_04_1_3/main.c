#include <stdio.h>
#include "input_output.h"
#include "make_string.h"

int main(void)
{
    char str[MAX_LINE_LEN + 1];
    char array[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
    int row;
    char result[MAX_LINE_LEN] = { '\0' };

    int input_code = input(str);

    if (input_code != OK)
        return input_code;

    int array_code = make_array(str, array, &row);

    if (array_code != OK)
        return array_code;

    int string_code = make_string(result, array, row);

    if (string_code != OK)
        return string_code;

    output(result);

    return OK;
}

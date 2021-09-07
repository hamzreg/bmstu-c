#include <stdio.h>
#include "input_output.h"
#include "string_process.h"
#include "array_process.h"

int main(void)
{
    char str[MAX_LINE_LEN + 1];
    char array[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
    int row;

    int input_code = input(str);

    if (input_code != OK)
        return input_code;

    int array_code = make_array(str, array, &row);

    if (array_code != OK)
        return array_code;

    arrange_array(array, row);
    remove_repet(array, &row);
    output(array, row);

    return OK;
}

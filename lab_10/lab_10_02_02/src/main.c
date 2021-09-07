#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/base_functions.h"
#include "../inc/constants.h"
#include "../inc/return_codes.h"
#include "../inc/polynom.h"

int main(void)
{
    int code = process_polynom();

    if (!code)
        return code;
    else
    {
        LOG_ERROR("%s", "Invalid command");
        return ERROR_INPUT;
    }

    return OK;
}

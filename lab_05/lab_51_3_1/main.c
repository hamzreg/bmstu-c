#include <stdio.h>
#include "process.h"

int main(void)
{
    int number_sign_changes = 0, code;

    code = process(stdin, &number_sign_changes);

    if (code == OK)
    {
        printf("Number of sign changes is %d\n", number_sign_changes);
        return OK;
    }
    else if (code == ONE_NUMBER)
        return ONE_NUMBER;

    return NO_NUMBERS;
}

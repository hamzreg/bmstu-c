#include <stdio.h>
#include <string.h>
#include "my_strspn.h"

int main(void)
{
    char arr_str[][MAX_LENTGH] = { "13234321", "human", "2nd day", "no", "     " };
    char arr_symbol[][MAX_LENTGH] = { "231", "man", "now day 2", "yes", "   " };

    for (int i = 0; i < MAX_ROW_COUNT; i++)
    {
        printf("The result of my_strspn is %zd\n", my_strspn(arr_str[i], arr_symbol[i]));
        printf("The result of strspn is %zd\n", strspn(arr_str[i], arr_symbol[i]));
    }

    return OK;
}

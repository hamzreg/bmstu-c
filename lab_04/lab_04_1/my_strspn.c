#include <stdio.h>
#include "my_strspn.h"

size_t my_strspn(const char *str, const char *symbol)
{
    size_t length = 0;
    int fl;

    for (int i = 0; str[i] != '\0'; i++)
    {
        fl = 0;

        for (int j = 0; symbol[j] != '\0'; j++)
        {
            if (str[i] == symbol[j])
                fl = 1;
        }

        if (fl)
            length++;
        else
            return length;
    }

    return length;
}

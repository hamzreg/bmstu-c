#include <stdio.h>
#include "string_process.h"

int compare_strings(const char *str1, const char *str2)
{
    int i = 0;

    while ((str1[i] != '\0') || (str2[i] != '\0'))
    {
        if (str1[i] == str2[i])
            i++;
        else if (str1[i] < str2[i])
            return LESS;
        else
            return MORE;
    }

    if (str1[i] == '\0')
    {
        if (str2[i] == '\0')
            return EQUAL;
        else
            return LESS;
    }
    return MORE;
}

void swap(char *const str1, char *const str2)
{
    char t;

    for (int i = 0; i < MAX_WORD_LEN; i++)
    {
        t = str1[i];
        str1[i] = str2[i];
        str2[i] = t;
    }
}

#include <stdio.h>
#include <string.h>
#include "input_output.h"

int input(char *const str)
{
    char separator[] = " ,;:-.!?";
    int fl = 0, count = 0;

    if (fgets(str, MAX_LINE_LEN + 1, stdin) == NULL)
    {
        printf("The line not read");
        return NOT_READ;
    }

    if (strlen(str) > MAX_LINE_LEN + 1)
    {
        printf("The length of line more than permissible");
        return MORE_MAX_LEN;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; separator[j] != '\0'; j++)
        {
            if (str[i] == separator[j])
                fl = 1;
        }

        if (fl == 1)
        {
            count++;
            fl = 0;
        }
    }

    str[strlen(str) - 1] = str[strlen(str)];

    if (count == strlen(str))
    {
        printf("The line only from separators");
        return ONLY_SEP;
    }

    if (str[0] == '\0')
    {
        printf("The line is empty");
        return EMPTY;
    }

    return OK;
}

void output(const char *str)
{
    printf("Result: %s\n", str);
}

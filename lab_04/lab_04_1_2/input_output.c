#include <stdio.h>
#include "input_output.h"

int input(char *const str)
{
    int ch;
    int i = 0;
    char separator[] = " ,;:-.!?";
    int fl = 0, count = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i > MAX_LINE_LEN - 1)
        {
            printf("The length of line more than permissible");
            return MORE_MAX_LEN;
        }

        if (ch == EOF)
        {
            printf("The character was not read");
            return NOT_READ_CH;
        }

        for (int j = 0; separator[j] != '\0'; j++)
        {
            if (ch == separator[j])
                fl = 1;
        }

        if (fl == 1)
        {
            count++;
            fl = 0;
        }

        str[i++] = ch;
    }

    if (i == 0)
    {
        printf("The line is empty");
        return EMPTY;
    }

    if (count == i)
    {
        printf("The line only from separators");
        return ONLY_SEP;
    }

    str[i] = '\0';

    return OK;
}

void output(char array[][MAX_WORD_LEN + 1], const int row)
{
    printf("Result: ");

    for (int i = 0; i < row; i++)
    {
        printf("%s ", array[i]);
    }
}

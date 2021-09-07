#include <stdio.h>
#include "string_process.h"
#include "array_process.h"

int separator(char ch)
{
    char symbol[] = " ,;:.-!?";

    for (int i = 0; symbol[i] != '\0'; i++)
    {
        if (ch == symbol[i])
            return YES;
    }

    return NO;
}

int make_array(const char *str, char (*array)[MAX_WORD_LEN + 1], int *const size)
{
    int k = 0, t = 0, l = 0;
    char now, past;

    if (separator(str[0]) == NO)
    {
        array[k][0] = str[0];
        t++;
        l++;
    }

    for (int i = 1; str[i] != '\0'; i++)
    {
        now = separator(str[i]);
        past = separator(str[i - 1]);

        if ((now == YES) && (past == NO))
        {
            array[k++][t] = '\0';
            l = 0;
            t = 0;
        }

        if (now == NO)
        {
            array[k][t++] = str[i];
            l++;
        }

        if (l > MAX_WORD_LEN)
        {
            printf("The len word more than sixteen");
            return MORE_WORD_LEN;
        }
    }

    *size = k + 1;
    array[k][t] = '\0';

    return OK;
}

void shift(char (*array)[MAX_WORD_LEN + 1], const int i, int size)
{
    for (int j = i; j < size - 1; j++)
    {
        for (int k = 0; k < MAX_WORD_LEN; k++)
        {
            array[j][k] = array[j + 1][k];
        }
    }
}

void remove_repet(char (*array)[MAX_WORD_LEN + 1], int *size)
{
    int code;

    for (int i = 0; i < *size; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            code = compare_strings(array[i], array[j]);

            if (code == EQUAL)
            {
                shift(array, j, *size);
                *size = *size - 1;
                j--;
            }
        }
    }
}

void arrange_array(char (*array)[MAX_WORD_LEN + 1], const int size)
{
    int code;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            code = compare_strings(array[j], array[j + 1]);

            if (code > 1)
                swap(array[j], array[j + 1]);
        }
    }
}

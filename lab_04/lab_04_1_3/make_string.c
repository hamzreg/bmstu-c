#include <stdio.h>
#include <string.h>
#include "make_string.h"

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
    int k = 0, t = 0, l = 0, length = 1;
    char now, past;

    if (separator(str[0]) == NO)
    {
        array[k][0] = str[0];
        t++;
        l++;
    }

    for (int i = 1; str[i] != '\0'; i++)
    {
        length++;
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
            printf("The length word more than sixteen");
            return MORE_WORD_LEN;
        }
    }

    if (k == 0)
    {
        printf("In string has only one word");
        return ONE_WORD;
    }

    if (separator(str[length - 1]) == NO)
    {
        *size = k + 1;
        array[k][t] = '\0';
    }
    else
        *size = k;

    return OK;
}

void shift(char *word, const int i, const int size)
{
    for (int j = i; j < size; j++)
    {
        word[j] = word[j + 1];
    }
}

void transform_word(char *word)
{
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (word[i] == word[j])
            {
                shift(word, j, length);
                length--;
                j--;
            }
        }
    }
}

int make_string(char *str, char array[][MAX_WORD_LEN + 1], const int size)
{
    for (int i = size - 2; i > -1; i--)
    {
        if (strcmp(array[i], array[size - 1]) != 0)
        {
            transform_word(array[i]);
            strcat(str, array[i]);
            strcat(str, " ");
        }
    }

    str[strlen(str) - 1] = str[strlen(str)];

    if (str[0] == '\0')
        return EMPTY;
    return OK;
}

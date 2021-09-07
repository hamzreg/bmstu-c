#include "../inc/my_strings.h"

int my_strcmp(char *first, char *second)
{
    int i = 0;

    while (first[i] != '\0' && second[i] != '\0')
    {
        if (first[i] != second[i])
            return (first[i] - second[i]);

        i++;
    }

    if (first[i] == '\0' && second[i] == '\0')
        return EQUAL;

    return NOT_EQUAL;
}


int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}


int insert_string(char *buffer, char *string,
int start, int size)
{
    int i = 0;

    while (start < size - 1 && string[i] != '\0')
        buffer[start++] = string[i++];

    return start;
}


void reverse_string(char *string, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char symbol = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = symbol;
    }
}


int specifier_string(char *buffer, int *i, size_t size,
char *string)
{
    if (*i < size - 1 && size)
        *i = insert_string(buffer, string, *i, size);

    return my_strlen(string);
}


int specifier_short_int(char *buffer, int *i, size_t size,
short int number)
{
    int len_arg = get_len_number(number);

    char *string = malloc((len_arg + 1) * sizeof(char));

    if (!string)
        return ZERO_LEN;

    convert_number(string, number, len_arg);

    if (*i < size - 1 && size)
        *i = insert_string(buffer, string, *i, size);

    free(string);

    return len_arg;
}


int specifier_octal(char *buffer, int *i, size_t size,
unsigned int number)
{
    int len_arg = get_len_octal(number) + 1;

    char *string = malloc((len_arg + 1) * sizeof(char));

    if (!string)
        return ZERO_LEN;

    convert_octal(string, number);

    if (*i < size - 1 && size)
        *i = insert_string(buffer, string, *i, size);

    free(string);

    return len_arg;
}


int my_snprintf(char *restrict buffer, size_t size,
const char *restrict format, ...)
{
    va_list args;
    va_start(args, format);

    int count_read = 0;
    int i = 0, j = 0;

    while (format[j] != '\0')
    {
        if (format[j] != '%')
        {
            if (i < size - 1 && size)
                buffer[i++] = format[j];

            j++;
            count_read++;
            continue;
        }
        else
            j++;

        if (format[j] == 'c')
        {
            char symbol = va_arg(args, int);

            if (i < size - 1 && size)
                buffer[i++] = symbol;

            j++;
            count_read++;
        }
        else if (format[j] == 's')
        {
            char *string = va_arg(args, char *);
            count_read += specifier_string(buffer, &i,
            size, string);

            j++;
        }
        else if (format[j] == 'h')
        {
            short int number = va_arg(args, int);
            count_read += specifier_short_int(buffer, &i,
            size, number);

            j += 2;
        }
        else if (format[j] == 'o')
        {
            unsigned int octal_number = va_arg(args, int);
            count_read += specifier_octal(buffer, &i, size,
            octal_number);

            j++;
        }
    }

    if (size)
        buffer[i] = '\0';

    va_end(args);

    return count_read;
}

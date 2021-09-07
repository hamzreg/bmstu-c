#include "../inc/numbers.h"

int get_len_number(short int number)
{
    int len = 0;

    if (number < 0)
        len++;

    if (number == 0)
        len++;

    while (number != 0)
    {
        len++;
        number /= 10;
    }

    return len;
}


int get_len_octal(unsigned int number)
{
    int i = 0, base = number / OCTAL;

    while (base)
    {
        base /= OCTAL;

        i++;
    }

    return i;
}


void convert_octal(char *string, unsigned int number)
{
    int i = 0;
    int base = number / OCTAL, remainder;

    while (base)
    {
        remainder = number % OCTAL;
        string[i++] = remainder + '0';

        number = base;
        base /= OCTAL;
    }

    string[i++] = number + '0';
    string[i] = '\0';

    reverse_string(string, i);
    LOG_INFO("%s", string);
}


void convert_number(char *string, int number, int len)
{
    int i = len;

    if (number < 0)
    {
        string[0] = '-';
        number *= (-1);
    }

    if (number == 0)
        string[0] = '0';

    while (number != 0)
    {
        string[len - 1] = number % 10 + '0';
        number /= 10;

        len--;
    }

    string[i] = '\0';
    LOG_INFO("%s", string);
}

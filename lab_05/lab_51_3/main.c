/*
 * Selected integer type - int
 * Sorting algorithm - bubble sorting
 * Ordering direction - ascending numbers
 * When writing to a file, the 4th argument
 * is the count of numbers
*/

#include <stdio.h>
#include "create_file.h"
#include "print_numbers.h"
#include "sort_file.h"
#include "error_codes.h"

int main(int argc, char **argv)
{
    FILE *f;
    int code;

    if (argc != 3)
    {
        fprintf(stderr, "Invalid command");
        return ERROR_COMMAND;
    }

    if (*argv[1] == 'c')
    {
        f = fopen(argv[2], "wb");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }

        if (create_file(f) != OK)
        {
            fprintf(stderr, "Write error");
            return WRITE_ERROR;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close file");
            return ERROR_CLOSE_FILE;
        }
    }
    else if (*argv[1] == 'p')
    {
        f = fopen(argv[2], "rb");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }

        code = print_numbers(f);

        if (code != OK)
        {
            fprintf(stderr, "No integers in file");
            return code;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close file");
            return ERROR_CLOSE_FILE;
        }
    }
    else if (*argv[1] == 's')
    {
        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }

        code = sort_file(f);

        if (code != OK)
        {
            fprintf(stderr, "No integers in file");
            return code;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close file");
            return ERROR_CLOSE_FILE;
        }
    }

    return OK;
}

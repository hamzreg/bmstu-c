#include <stdio.h>
#include <string.h>
#include "sort_students.h"
#include "print_student_info.h"
#include "remove_students.h"
#include "error_codes.h"

int main(int argc, char **argv)
{
    FILE *f, *f_out;
    int code;

    if (argc < 3)
    {
        fprintf(stderr, "Invalid command");
        return ERROR_COMMAND;
    }

    if (strcmp(argv[1], "sb") == 0)
    {
        if (argc != 3)
        {
            fprintf(stderr, "Invalid command");
            return ERROR_COMMAND;
        }

        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }

        code = sort_students(f);

        if (code != OK)
        {
            fprintf(stderr, "File size error or it is empty");
            return code;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close file");
            return ERROR_CLOSE_FILE;
        }

        return OK;
    }
    else if (strcmp(argv[1], "fb") == 0)
    {
        if (argc != 5)
        {
            fprintf(stderr, "Invalid command");
            return ERROR_COMMAND;
        }

        f = fopen(argv[2], "rb");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }
        
        f_out = fopen(argv[3], "wb");

        if (f_out == NULL)
        {
            fprintf(stderr, "File name not treceived");
            return NO_FILE_NAME;
        }

        code = print_student_info(f, f_out, argv[4]);

        if (code != OK)
        {
            fprintf(stderr, "File size error or it is empty");
            return code;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close input file");
            return ERROR_CLOSE_FILE;
        }

        if (fclose(f_out) != OK)
        {
            fprintf(stderr, "Error close output file");
            return ERROR_CLOSE_FILE;
        }

        return OK;
    }
    else if (strcmp(argv[1], "db") == 0)
    {
        if (argc != 3)
        {
            fprintf(stderr, "Invalid command");
            return ERROR_COMMAND;
        }

        f = fopen(argv[2], "rb+");

        if (f == NULL)
        {
            fprintf(stderr, "File name not received");
            return NO_FILE_NAME;
        }

        code = remove_students(f);

        if (code != OK)
        {
            fprintf(stderr, "File size error or it is empty");
            return code;
        }

        if (fclose(f) != OK)
        {
            fprintf(stderr, "Error close file");
            return ERROR_CLOSE_FILE;
        }

        return OK;
    }

    return ERROR_COMMAND;
}

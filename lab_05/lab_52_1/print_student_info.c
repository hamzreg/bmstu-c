#include <stdio.h>
#include "find_file_size.h"
#include <string.h>
#include "print_student_info.h"

int print_student_info(FILE *f_in, FILE *f_out, char *str)
{
    size_t file_size;
    int rc, fl = 0;
    student student_one;

    rc = find_file_size(f_in, &file_size);
    
    if (rc != 0)
        return FILE_SIZE_ERROR;

    if (file_size % sizeof(student) != 0)
        return FILE_SIZE_ERROR;

    if (file_size != 0)
    {
        while (fread(&student_one, sizeof(student), 1, f_in))
        {
            if (strstr(student_one.surname, str) != NULL)
            {
                fwrite(&student_one, sizeof(student), 1, f_out);
                fl = 1;
            }
        }

        if (fl == 0)
            return NO_THAT_STUDENT;

        return OK;
    }

    return EMPTY_FILE;
}

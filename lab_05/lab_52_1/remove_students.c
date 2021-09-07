#include <stdio.h>
#include <math.h>
#include "find_file_size.h"
#include "get_put_student.h"
#include "remove_students.h"
#include <unistd.h>

void find_average_mark(unsigned int *const marks, double *now_average_mark)
{
    *now_average_mark = 0;

    for (int i = 0; i < COUNT_SUBJECT; i++)
        *now_average_mark += marks[i];

    *now_average_mark /= COUNT_SUBJECT;
}

void shift(FILE *f, const int pos, const int n)
{
    student student_one;

    for (int i = pos; i < n - 1; i++)
    {
        get_student_by_pos(f, i + 1, &student_one);

        put_student_by_pos(f, i, student_one);
    }
}

int remove_students(FILE *f)
{
    int rc;
    size_t file_size;
    double average_mark = 0, now_average_mark;
    int amount;
    student student_one;

    rc = find_file_size(f, &file_size);

    if (rc != 0)
        return FILE_SIZE_ERROR;

    if (file_size % sizeof(student) != 0)
        return FILE_SIZE_ERROR;

    amount = file_size / sizeof(student);

    if (file_size != 0)
    {
        while (fread(&student_one, sizeof(student), 1, f))
        {
            find_average_mark(student_one.marks, &now_average_mark);
            average_mark += now_average_mark;
        }
    }

    average_mark /= amount;

    for (int i = 0; i < amount; i++)
    {
        get_student_by_pos(f, i, &student_one);

        find_average_mark(student_one.marks, &now_average_mark);

        if (now_average_mark < average_mark)
        {
            shift(f, i, amount);
            i--;
            amount--;
        }
    }

    if (ftruncate(fileno(f), sizeof(student)*amount) != OK)
        return ERROR_CROP_FILE;

    return OK;
}

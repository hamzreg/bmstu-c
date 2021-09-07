#include <stdio.h>
#include <string.h>
#include "find_file_size.h"
#include "sort_students.h"
#include "get_put_student.h"

int sort_students(FILE *f)
{
    student student_one, student_two;
    memset(&student_one, 0, sizeof(student));
    memset(&student_two, 0, sizeof(student));
    size_t file_size;
    int rc;
    int amount;
    int compare_surname, compare_name;

    rc = find_file_size(f, &file_size);

    if (rc != 0)
        return FILE_SIZE_ERROR;

    if (file_size % sizeof(student) != 0)
        return FILE_SIZE_ERROR;

    amount = file_size / sizeof(student);

    for (int i = 0; i < amount; i++)
    {
        for (int j = amount - 1; j > i; j--)
        {
            get_student_by_pos(f, j, &student_one);
            get_student_by_pos(f, j - 1, &student_two);

            compare_surname = strcmp(student_one.surname, student_two.surname);
            compare_name = strcmp(student_one.name, student_two.name);

            if (compare_surname < 0)
            {
                put_student_by_pos(f, j - 1, student_one);
                put_student_by_pos(f, j, student_two);
            }
            else if ((compare_surname == 0) && (compare_name < 0))
            {
                put_student_by_pos(f, j - 1, student_one);
                put_student_by_pos(f, j, student_two);
            }
        }
    }

    for (int i = 0; i < amount; i++)
    {
        get_student_by_pos(f, i, &student_one);
        printf("%s\n%s\n", student_one.surname, student_one.name);

        for (int j = 0; j < COUNT_SUBJECT; j++)
        {
            if (j != COUNT_SUBJECT - 1)
                printf("%u ", student_one.marks[j]);
            else
                printf("%u\n", student_one.marks[j]);
        }
    }

    return OK;
}

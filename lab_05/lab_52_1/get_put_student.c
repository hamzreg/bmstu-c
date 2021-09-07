#include <stdio.h>
#include "get_put_student.h"

void get_student_by_pos(FILE *f, const int pos, student *st)
{
    fseek(f, pos * sizeof(student), SEEK_SET);

    fread(st, sizeof(student), 1, f);
}

void put_student_by_pos(FILE *f, const int pos, student st)
{
    fseek(f, pos * sizeof(student), SEEK_SET);

    fwrite(&st, sizeof(student), 1, f);
}

#ifndef SORT_STUDENTS_H
#define SORT_STUDENTS_H
#include "struct.h"
#define FILE_SIZE_ERROR 1
#define OK 0

void get_student_by_pos(FILE *f, const int pos, student *st);

void put_student_by_pos(FILE *f, const int pos, student st);

int sort_students(FILE *f);

#endif

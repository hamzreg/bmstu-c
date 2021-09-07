#ifndef REMOVE_STUDENTS_H
#define REMOVE_STUDENTS_H
#include "struct.h"
#define FILE_SIZE_ERROR 1
#define NO_DELETED 4
#define ERROR_CROP_FILE 3
#define OK 0

void find_average_mark(unsigned int *const marks, double *now_average_mark);

void shift(FILE *f, const int pos, const int n);

int remove_students(FILE *f);

#endif


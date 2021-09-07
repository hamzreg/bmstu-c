#ifndef PRINT_STUDENT_INFO_H
#define PRINT_STUDENT_INFO_H
#include "struct.h"
#define OK 0
#define FILE_SIZE_ERROR 1
#define EMPTY_FILE 2
#define NO_THAT_STUDENT 3

int print_student_info(FILE *f_in, FILE *f_out, char *str);

#endif

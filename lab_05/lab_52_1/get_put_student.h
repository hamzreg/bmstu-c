#ifndef GET_PUT_STUDENT_H
#define GET_PUT_STUDENT_H
#include "struct.h"

void get_student_by_pos(FILE *f, const int pos, student *st);

void put_student_by_pos(FILE *f, const int pos, student st);

#endif

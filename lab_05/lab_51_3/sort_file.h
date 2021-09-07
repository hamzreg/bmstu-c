#ifndef SORT_FILE_H
#define SORT_FILE_H
#include "find_file_size.h"
#define OK 0
#define NO_INTEGERS 1

void get_number_by_pos(FILE *f, const int offset, int *const number);

void put_number_by_pos(FILE *f, const int offset, const int number);

int sort_file(FILE *f);

#endif


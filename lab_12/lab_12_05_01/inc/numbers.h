#ifndef NUMBERS_LIB_H
#define NUMBERS_LIB_H

#include <stdio.h>

#include "errors.h"
#include "macrologger.h"

int compare_int(const void *first, const void *second);

void swap(size_t size, char *number_one, char *number_two);

int sum_numbers(const int *first, const int *last);

#endif


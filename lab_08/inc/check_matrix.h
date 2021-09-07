#ifndef CHECK_MATRIX_H
#define CHECK_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <check.h>
#include "matrix.h"

#define NOT_EQUAL 0
#define EQUAL 1
#define MATRIX_SIZE 3

Suite *multiplicate_suite(void);

Suite *pow_matrix_suite(void);

#endif
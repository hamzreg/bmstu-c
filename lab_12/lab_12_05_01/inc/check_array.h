#ifndef CHECK_ARRAY_H
#define CHECK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "array.h"
#include "numbers.h"

#define EQUAL     1
#define NOT_EQUAL 0

Suite *mysort_suite(void);

Suite *key_suite(void);

#endif

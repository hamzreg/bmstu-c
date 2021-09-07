#ifndef CHECK_MY_SNPRINTF_H
#define CHECK_MY_SNPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "my_strings.h"

#define TEST_LEN      20

Suite *char_suite(void);

Suite *short_integer_suite(void);

Suite *string_suite(void);

Suite *octal_suite(void);

#endif

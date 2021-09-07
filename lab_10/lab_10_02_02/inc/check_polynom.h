#ifndef CHECK_POLYNOM_H
#define CHECK_POLYNOM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "polynom.h"
#include "multiplier.h"

#define EQUAL 0
#define NOT_EQUAL 1

Suite *get_value_suite(void);

Suite *get_derivative_suite(void);

Suite *add_polynoms_suite(void);

#endif

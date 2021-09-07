#ifndef BASE_FUNCTIONS_H
#define BASE_FUNCTIONS_H

#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "return_codes.h"
#include "polynom.h"
#include "multiplier.h"

int process_polynom(void);

int get_polynom_value(void);

int get_derivative(void);

int get_sum_polynoms(void);

int divide_polynom(void);

#endif

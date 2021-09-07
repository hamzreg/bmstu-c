#ifndef POLYNOM_H
#define POLYNOM_H

#include <stdio.h>
#include <stdlib.h>

#include "polynom_t.h"
#include "multiplier_t.h"
#include "multiplier.h"
#include "return_codes.h"
#include "constants.h"
#include "macrologger.h"

void init_polynom(polynom_t *const polynom);

int input_polynom(polynom_t *polynom, int mode);

void free_polynom(multiplier_t *head);

int print_polynom(multiplier_t *head);

int count_polunom_value(multiplier_t *head, const int data);

void differentiate_polynom(multiplier_t *head, const int power);

void add_polynoms(multiplier_t *first, multiplier_t *second);

void get_second_polynom(polynom_t *first, polynom_t *second);

#endif

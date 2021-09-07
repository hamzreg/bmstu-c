#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include <stdio.h>
#include <stdlib.h>

#include "polynom_t.h"
#include "multiplier_t.h"
#include "return_codes.h"
#include "macrologger.h"

multiplier_t *create_multiplier(const int data);

void multiplier_free(multiplier_t *multiplier);

void add_multiplier_end(polynom_t *polynom, multiplier_t *multiplier);

void delete_multiplier(polynom_t *polynom, const int position);

#endif

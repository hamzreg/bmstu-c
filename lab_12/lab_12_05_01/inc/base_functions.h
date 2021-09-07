#ifndef BASE_FUNCTIONS_H
#define BASE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/array_t.h"
#include "../inc/array.h"
#include "../inc/numbers.h"
#include "../inc/errors.h"
#include "../inc/macrologger.h"

int check_argc(const int argc, char **argv);

int read_array(const char *filename, array_t *array);

int write_array(const char *filename, array_t *array,
const int argc);

#endif

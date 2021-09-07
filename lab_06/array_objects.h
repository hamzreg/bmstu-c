#ifndef ARRAY_OBJECTS_H
#define ARRAY_OBJECTS_H
#include <stdio.h>
#include <string.h>
#include "object.h"
#include "return_codes.h"
#include "constants.h"

int create_array_objects(FILE *f, object *const items, int *const count);

void sort_array_objects(object *const items, const int start, const int end);

void print_array_object(const object item);

void print_array_objects(const object *const items, const int count);

void print_some_objects(const char *const str, const object *const items, const int count);

#endif



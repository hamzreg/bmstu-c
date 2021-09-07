#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include "numbers.h"
#include "constants.h"
#include "macrologger.h"

int my_strcmp(char *first, char *second);

int my_strlen(const char *str);


int specifier_string(char *buffer, int *i, size_t size,
char *string);

int specifier_short_int(char *buffer, int *i, size_t size,
short int number);

int specifier_octal(char *buffer, int *i, size_t size,
unsigned int number);


int insert_string(char *buffer, char *string,
int start, int size);

void reverse_string(char *string, int len);

int my_snprintf(char *restrict buffer, size_t size,
const char *restrict format, ...);

#endif
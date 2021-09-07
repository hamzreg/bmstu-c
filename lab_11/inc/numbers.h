#ifndef NUMBERS_H
#define NUMBERS_H

#include <stdio.h>
#include <stdlib.h>

#include "my_strings.h"
#include "constants.h"
#include "macrologger.h"

int get_len_number(short int number);

int get_len_octal(unsigned int number);

void convert_octal(char *string, unsigned int number);

void convert_number(char *string, int number, int len);

#endif

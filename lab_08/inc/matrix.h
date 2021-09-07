#ifndef MATRIX_H
#define MATRIX_H

#include "constants.h"
#include "matrix_t.h"
#include "macrologger.h"
#include "errors.h"

void free_matrix(int **matrix, const int rows);

int **allocate_matrix(const int rows, const int columns);

int input_matrix(matrix_t *matrix);

void print_matrix(matrix_t *matrix);

int reduce_matrix(matrix_t *matrix);

int get_max_size(const int one_size, const int two_size, int *const result_size);

int enlarge_matrix(matrix_t *matrix, const int size);

int input_powers(int *const power_a, int *const power_b);

int multiplicate(matrix_t matrix_a, matrix_t matrix_b, matrix_t *result);

void get_identity_matrix(matrix_t *matrix);

int pow_matrix(matrix_t *matrix, const int power);

#endif
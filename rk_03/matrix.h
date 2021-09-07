#ifndef MATRIX_H
#define MATRIX_H

#define MIN_COLUMN 0
#define MIN_ROW 0
#define MAGIC_ELEMENT -1
#define ERROR_ALLOCATE -2
#define OK 0
#define DATA_ERROR -3

int read_matrix(FILE *in_file, matrix_t *matrix);

int get_count_unit(matrix_t *matrix, const int row, const int column);

void replace_zero(matrix_t *matrix);

void shift(matrix_t *matrix, const int row);

void delete_full_zero_rows(matrix_t *matrix);

void get_count_not_zero(matrix_t matrix, int *count_not_zero);

void write_matrix_in_file(FILE *out_file, matrix_t matrix);

#endif
#ifndef PROCESS_H
#define PROCESS_H
#define NO_NUMBERS -1
#define ONE_NUMBER -2
#define OK 0
#define DIFFERENT_SIGNS 1
#define EQUAL_SIGNS 0

int compare_numbers(int const first_number, int const second_number);

int process(FILE *f, int *const number_sign_changes);

#endif

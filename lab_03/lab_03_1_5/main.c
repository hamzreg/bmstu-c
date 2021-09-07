#include <stdio.h>
#include <math.h>

#define OK 0
#define MAX_ROW_COUNT 10
#define MAX_COLUMN_COUNT 10
#define MIN_ROW_COUNT 1
#define MIN_COLUMN_COUNT 1
#define ERROR_TYPE_ROW_COUNT 1
#define ROW_COUNT_LESS_ONE 2
#define ROW_COUNT_MORE_TEN 3
#define ERROR_TYPE_COLUMN_COUNT 4
#define COLUMN_COUNT_LESS_ONE 5
#define COLUMN_COUNT_MORE_TEN 6
#define ERROR_TYPE_MATRIX_ELEMENT 7
#define NO_ELEMENTS_MORE_TEN 8

int sum_digits(int number)
{
    int sum_digits_number = 0;

    while (number > 0)
    {
        sum_digits_number += (number % 10);
        number /= 10;
    }

    return sum_digits_number;
}

int input(int *const row, int *const column, int (*matrix)[MAX_COLUMN_COUNT], int *const array, int *const size)
{
    printf("Input the row count: ");

    if (scanf("%d", row) != 1)
    {
        printf("The type of row count entered incorrectly.");
        return ERROR_TYPE_ROW_COUNT;
    }

    if (*row < MIN_ROW_COUNT)
    {
        printf("The row count less than one.");
        return ROW_COUNT_LESS_ONE;
    }

    if (*row > MAX_ROW_COUNT)
    {
        printf("The row count more than ten.");
        return ROW_COUNT_MORE_TEN;
    }

    if (scanf("%d", column) != 1)
    {
        printf("The type of column count entered incorrectly.");
        return ERROR_TYPE_COLUMN_COUNT;
    }

    if (*column < MIN_COLUMN_COUNT)
    {
        printf("The column count less than one.");
        return COLUMN_COUNT_LESS_ONE;
    }

    if (*column > MAX_COLUMN_COUNT)
    {
        printf("The column count more than ten.");
        return COLUMN_COUNT_MORE_TEN;
    }

    int fl = 0;

    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *column; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("The type of matrix element entered incorrectly.");
                return ERROR_TYPE_MATRIX_ELEMENT;
            }

            if (sum_digits(fabs(matrix[i][j])) > 10)
            {
                array[fl] = matrix[i][j];
                fl += 1;
            }
        }
    }

    if (fl == 0)
    {
        printf("In matrix no elements with sum more than ten.");
        return NO_ELEMENTS_MORE_TEN;
    }
    else
        *size = fl;

    return OK;
}

void shift(int *const array, const int size)
{
    int t;

    for (int i = 0; i < 3; i++)
    {
        t = array[0];

        for (int j = 0; j < size; j++)
        {
            array[j] = array[j + 1];
        }

        array[size - 1] = t;
    }
}

void matrix_filling(int matrix[][MAX_COLUMN_COUNT], const int row, const int column, int *const array)
{
    int k = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sum_digits(fabs(matrix[i][j])) > 10)
            {
                matrix[i][j] = array[k];
                k++;
            }
        }
    }
}

void output(int matrix[][MAX_COLUMN_COUNT], const int row, const int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}

int main(void)
{
    int matrix[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    int row, column;
    int array[MAX_ROW_COUNT * MAX_COLUMN_COUNT];
    int size;

    int input_code = input(&row, &column, matrix, array, &size);

    if (input_code != OK)
        return input_code;

    shift(array, size);
    matrix_filling(matrix, row, column, array);
    output(matrix, row, column);

    return OK;
}

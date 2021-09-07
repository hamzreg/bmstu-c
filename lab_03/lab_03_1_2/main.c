#include <stdio.h>
#include <math.h>

#define OK 0
#define MAX_ROW_COUNT 10
#define MAX_COLUMN_COUNT 10
#define MIN_ROW_COUNT 2
#define MIN_COLUMN_COUNT 2
#define ERROR_TYPE_ROW_COUNT 1
#define ROW_COUNT_LESS_TWO 2
#define ROW_COUNT_MORE_TEN 3
#define ERROR_TYPE_COLUMN_COUNT 4
#define COLUMN_COUNT_LESS_TWO 5
#define COLUMN_COUNT_MORE_TEN 6
#define ERROR_TYPE_MATRIX_ELEMENT 7

int input(int *const row, int *const column, int (*matrix)[MAX_COLUMN_COUNT])
{
    printf("Input the row count: ");

    if (scanf("%d", row) != 1)
    {
        printf("The type of row count entered incorrectly.");
        return ERROR_TYPE_ROW_COUNT;
    }

    if (*row < MIN_ROW_COUNT)
    {
        printf("The row count less than two.");
        return ROW_COUNT_LESS_TWO;
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
        printf("The column count less than two.");
        return COLUMN_COUNT_LESS_TWO;
    }

    if (*column > MAX_COLUMN_COUNT)
    {
        printf("The column count more than ten.");
        return COLUMN_COUNT_MORE_TEN;
    }

    for (int i = 0; i < *row; i++)
    {
        for (int j = 0; j < *column; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("The type of matrix element entered incorrectly.");
                return ERROR_TYPE_MATRIX_ELEMENT;
            }
        }
    }

    return OK;
}

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

void search_min_sum_digits(int matrix[][MAX_COLUMN_COUNT], const int row, const int column, int *const row_min, int *const column_min)
{
    int min_sum_digits = sum_digits(fabs(matrix[0][0]));
    int sum_number;
    
    *row_min = 0;
    *column_min = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            sum_number = sum_digits(fabs(matrix[i][j]));
            if (sum_number < min_sum_digits)
            {
                min_sum_digits = sum_number;
                *row_min = i;
                *column_min = j;
            } 
        }
    }
}

void delete_row(int matrix[][MAX_COLUMN_COUNT], const int row, const int column, const int row_min)
{
    for (int i = row_min; i < row - 1; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }
}

void delete_column(int matrix[][MAX_COLUMN_COUNT], const int row, const int column, const int column_min)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = column_min; j < column - 1; j++)
        {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
}

void output(int matrix[][MAX_COLUMN_COUNT], const int row, const int column)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < column - 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}

int main(void)
{
    int matrix[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    int row, column, row_min, column_min;

    int input_code = input(&row, &column, matrix);

    if (input_code != OK)
        return input_code;

    search_min_sum_digits(matrix, row, column, &row_min, &column_min);
    delete_row(matrix, row, column, row_min);
    delete_column(matrix, row, column, column_min);
    output(matrix, row, column);

    return OK;
}


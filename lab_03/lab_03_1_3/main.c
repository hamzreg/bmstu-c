#include <stdio.h>

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

int max_element_row(int *pointer, const int column)
{
    int *p = pointer;
    int max_element = *pointer;

    while (p < pointer + column)
    {
        if (*p > max_element)
            max_element = *p;
        p++;
    }

    return max_element;
}

void swap(int *pointer_one, int *pointer_two, const int column)
{
    int *p_one = pointer_one;
    int *p_two = pointer_two;
    int t;

    while (p_one < pointer_one + column)
    {
        t = *p_one;
        *p_one = *p_two;
        *p_two = t;

        p_one++;
        p_two++;
    }
}

void sort(int matrix[][MAX_COLUMN_COUNT], const int row, const int column)
{
    for (int k = 0; k < row; k++)
    {
        for (int i = 0; i < row - 1; i++)
        {
            if (max_element_row(matrix[i], column) < max_element_row(matrix[i + 1], column))
                swap(matrix[i], matrix[i + 1], column);
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

    int input_code = input(&row, &column, matrix);

    if (input_code != OK)
        return input_code;

    sort(matrix, row, column);
    output(matrix, row, column);

    return OK;
}

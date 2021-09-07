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
#define SYMMETRIC 8
#define NOT_SYMMETRIC 9

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

int is_symmetric(int *pointer, const int column)
{
    int *start = pointer;
    int *end = pointer + column - 1;

    while (start < pointer + column / 2)
    {
        if (*start == *end)
        {
            start++;
            end--;
        }
        else
            return NOT_SYMMETRIC; 
    }

    return SYMMETRIC;
}

void array_filling(int matrix[][MAX_COLUMN_COUNT], const int row, const int column, int *const array)
{
    int k = 0;

    for (int i = 0; i < row; i++)
    {
        if (is_symmetric(matrix[i], column) == SYMMETRIC)
            array[k] = 1;
        else
            array[k] = 0;

        k++;
    }
}
void output(const int *array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main(void)
{
    int array[MAX_COLUMN_COUNT];
    int matrix[MAX_ROW_COUNT][MAX_COLUMN_COUNT];
    int row, column;

    int input_code = input(&row, &column, matrix);

    if (input_code != OK)
        return input_code;

    array_filling(matrix, row, column, array);
    output(array, row);

    return OK;
}

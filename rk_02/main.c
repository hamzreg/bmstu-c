#include <stdio.h>

#define MAX_ROW 10
#define MAX_COLUMN 10
#define OK 0

void zero_matrix(int (*a)[MAX_COLUMN])
{
    for (int i = 0; i < MAX_ROW; i++)
    {
        for (int j = 0; j < MAX_COLUMN; j++)
        {
            a[i][j] = 0;
        }
    }
}

void fill_matrix(int (*a)[MAX_COLUMN])
{
    int number;
    int i = 0, j;

    while (scanf("%d", &number) == 1)
    {
        j = 0;

        while (number > 0)
        {
            a[i][j] = number % 10;
            number /= 10;
            j++;
        }

        i++;
    }
}

int even_line(int a[MAX_ROW])
{

}


int main(void)
{
    int matrix[MAX_ROW][MAX_COLUMN];
    int number;

    zero_matrix(matrix);

    fill_matrix(matrix);

    return OK;
}

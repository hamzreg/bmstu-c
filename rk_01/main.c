#include <stdio.h>

#define MAX_SIZE 1000
#define OK 0

void input(int *a, int *size)
{
    int element;
    int i = 0;

    while (scanf("%d", &element) == 1) 
    {
        a[i] = element;
        i++;
    }

    *size = i;
}

int count_unique(int *a, const int size)
{
    int amount = 0;
    int fl;
    for (int i = 0; i < size; i++)
    {
        fl = 0;

        if (a[i] > 0)
        {

            for (int j = i - 1; j > -1; j--)
            {
                if (a[i] == a[j])
                    fl = 1;
            }
        
            if (fl != 1)
                amount++;
        }
    }

    return amount;
}

int main(void)
{
    int array[MAX_SIZE];
    int size;

    input(array, &size);

    printf("%d", count_unique(array, size));

    return OK;
}

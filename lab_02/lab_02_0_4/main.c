#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 1
#define SIZE_LESS_ONE 2
#define SIZE_MORE_TEN 3
#define ERROR_TYPE_SIZE 4
#define ERROR_TYPE_ELEMENT 5
#define OK 0

int enter(int *const array, int *const size)
{
    printf("Input the size of array: ");

    if (scanf("%d", size) != 1)
    {
        printf("The type of array size entered incorreclty.");    
        return ERROR_TYPE_SIZE;
    }
    
    if (*size < MIN_SIZE)
    {
        printf("The array size less than one."); 
        return SIZE_LESS_ONE;
    }

    if (*size > MAX_SIZE)
    {
        printf("The array size more than ten.");
        return SIZE_MORE_TEN;
    }

    for (int i = 0; i < *size; i++)
    {
        printf("Input the element of array: ");
		
        if (scanf("%d", &array[i]) != 1)
        {
            printf("The type of element entered incorrectly.");
            return ERROR_TYPE_ELEMENT;
        }
    }

    return OK;
}

void sort_bubble(int *const array, const int size)
{
    int t;

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (array[j - 1] > array[j])
            {
                t = array[j - 1];
                array[j - 1] = array[j];
                array[j] = t;
            }
        }
    }
}
		
void output(const int *array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main(void)
{
    int n;

    int array[MAX_SIZE];

    int code_enter = enter(array, &n);

    if (code_enter != OK)
        return code_enter;

    sort_bubble(array, n);

    output(array, n);

    return OK;
}


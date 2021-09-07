#include <stdio.h>

#define MAX_SIZE 10
#define NEW_MAX_SIZE 20
#define MIN_SIZE 1
#define ZERO_NUMBER 0
#define FIRST_NUMBER 1
#define SIZE_LESS_ONE 2
#define SIZE_MORE_TEN 3
#define ERROR_TYPE_SIZE 4
#define ERROR_TYPE_ELEMENT 5
#define OK 0

int num_fibonacci(int i)
{
    if (i == 0)
        return ZERO_NUMBER;
    else if (i == 1)
        return FIRST_NUMBER;
    else
        return (num_fibonacci((i - 1)) + num_fibonacci((i - 2)));
}

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

int create_array(const int *array, int *const new_array, const int size)
{
    int new_size = 0;
    int j = 0, k = 0;

    for (int i = 0; i < size; i++)
    {
        new_array[j] = array[i];
        new_size += 1;
        j += 1;

        if (array[i] % 3 == 0)
        {
            new_array[j] = num_fibonacci(k);
            k += 1;
            j += 1;
            new_size += 1;
        }
    }

    return new_size;
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
    int n, new_n;

    int array[MAX_SIZE];
    int new_array[NEW_MAX_SIZE];

    int code_enter = enter(array, &n);

    if (code_enter != OK)
        return code_enter;

    new_n = create_array(array, new_array, n);
    output(new_array, new_n);

    return OK;
}

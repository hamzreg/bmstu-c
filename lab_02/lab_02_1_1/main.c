#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 1
#define SIZE_LESS_ONE 2
#define SIZE_MORE_TEN 3
#define ERROR_TYPE_SIZE 4
#define ERROR_TYPE_ELEMENT 5
#define NO_ODD_NUMBERS 6
#define OK 0

int enter(int *const array, int *const size)
{
    int fl = 0;

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
        printf("Input the element of the array: ");

        if (scanf("%d", &array[i]) != 1)
        {
            printf("The type of element entered incorrectly.");
            return ERROR_TYPE_ELEMENT;
        }

        if (array[i] % 2 != 0)
            fl = 1;
    }

    if (fl == 0)
    {
        printf("There are not numbres in array.");
        return NO_ODD_NUMBERS;
    }

    return OK;
}

int odd_product(const int *array, const int size)
{
    int product = 1;

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
            product *= array[i];
    }

    return product;
}

int main(void)
{
    int n;
    int array[MAX_SIZE];

    int code_enter = enter(array, &n);

    if (code_enter != OK)
        return code_enter;

    printf("The product of odd array elements is %d", odd_product(array, n));

    return OK;
}

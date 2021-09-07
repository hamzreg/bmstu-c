#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 1
#define SIZE_LESS_ONE 2
#define SIZE_MORE_TEN 3
#define ERROR_TYPE_SIZE 4
#define ERROR_TYPE_ELEMENT 5
#define NO_POSITIVE 6
#define NO_NEGATIVE 7
#define OK 0

int enter(int *const zero_pointer, int **const last_pointer, int *const amount)
{
    int size;
    int amount_positive = 0, amount_negative = 0;

    printf("Input the size of array: ");

    if (scanf("%d", &size) != 1)
    {
        printf("The type of array size entered incorreclty.");    
        return ERROR_TYPE_SIZE;
    }
    
    if (size < MIN_SIZE)
    {
        printf("The array size less than one."); 
        return SIZE_LESS_ONE;
    }

    if (size > MAX_SIZE)
    {
        printf("The array size more than ten.");
        return SIZE_MORE_TEN;
    }

    *last_pointer = zero_pointer + size;

    for (int *pointer = zero_pointer; pointer < *last_pointer; pointer++)
    {
        printf("Input the element of array: ");

        if (scanf("%d", pointer) != 1)
        {
            printf("The type of element entered incorrectly.");
            return ERROR_TYPE_ELEMENT;
        }

        if (*pointer > 0)
            amount_positive += 1;
        else if (*pointer < 0)
            amount_negative += 1;
    }

    if (amount_positive == 0)
    {
        printf("There are no positive numbers in array.");
        return NO_POSITIVE;
    }
 
    if (amount_negative == 0)
    {
        printf("There are no negative numbers in array.");
        return NO_NEGATIVE;
    }

    if (amount_negative < amount_positive)
        *amount = amount_negative;
    else
        *amount = amount_positive;

    return OK;
}

int product_numbers(int *zero_pointer, int *last_pointer, int amount)
{
    int product = 0;
    last_pointer = last_pointer - 1;

    while (amount > 0)
    {
        while (*zero_pointer >= 0)
        {
            zero_pointer += 1;
        }

        while (*last_pointer <= 0)
        {
            last_pointer -= 1;
        }

        product += *zero_pointer * *last_pointer;

        zero_pointer += 1;
        last_pointer -= 1;
        amount -= 1;
    }

    return product;
}	

int main(void)
{
    int array[MAX_SIZE];
    int *last_pointer = array + MAX_SIZE;
    int amount; 

    int code_enter = enter(array, &last_pointer, &amount);

    if (code_enter != OK)
        return code_enter;

    printf("The product of numbers if %d", product_numbers(array, last_pointer, amount));

    return OK;
}

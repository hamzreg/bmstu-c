#include <stdio.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define SIZE_LESS_ONE 2
#define SIZE_MORE_TEN 3
#define ERROR_TYPE_SIZE 4
#define ERROR_TYPE_ELEMENT 5
#define NO_PRIME 6
#define PRIME 0
#define OK 0

int prime(int number)
{
    if ((number == 1) || (number <= 0))
        return NO_PRIME;

    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return NO_PRIME;
    }

    return PRIME;
}

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
        printf("Input the element of array: ");
		
        if (scanf("%d", &array[i]) != 1)
        {
            printf("The type of element entered incorrectly.");
            return ERROR_TYPE_ELEMENT;
        }
	
        if (prime(array[i]) == PRIME)
            fl = 1;	
    }

    if (fl == 0)
    {
        printf("There are no primes in array.");
        return NO_PRIME;
    }

    return OK;
}

int create_array(const int *array, int *const new_array, const int size)
{
    int new_size = 0;
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (prime(array[i]) == OK)
        {
            new_array[j] = array[i];
            new_size += 1;
            j += 1;
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
    int n;

    int array[MAX_SIZE];
    int new_array[MAX_SIZE];

    int code_enter = enter(array, &n);

    if (code_enter != OK)
        return code_enter;

    int new_n = create_array(array, new_array, n);
    output(new_array, new_n);

    return OK;
}

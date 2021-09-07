#include <stdio.h>

#define FIRST_NUM    1
#define SECOND_NUM   2


int get_fib_num(const int position)
{
    if (position == FIRST_NUM || position == SECOND_NUM)
        return FIRST_NUM;
    
    return get_fib_num(position - 1) + get_fib_num(position - 2);
}


void fill_fibonacci_array(int *const array, const int size)
{
    for (int i = 0; i < size; i++)
        array[i] = get_fib_num(i + 1);
}


int create_set(const int *const first, int *const second,
const int first_size, int set_size)
{
    int new_size = 0;
    int fl = 0;

    for (int i = 0; i < first_size; i++)
    {
        fl = 0;

        for (int j = 0; j < i; j++)
            if (first[j] == first[i])
                fl = 1;
        
        if (!fl)
        {
            if (set_size)
                second[new_size] = first[i];
            new_size++;
        }
    }

    return new_size;
}

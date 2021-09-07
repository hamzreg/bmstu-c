/*
 * The program is written by Khamzina R., IU7-23B.
 * Given: the two natural numbers.
 * Find: the greatest common divisor.
*/

/*
 * The preprocessor must include to the
 * file stdio.h to enable input and 
 * output of values.
*/
#include <stdio.h>

/*
 * Replaces the macros names "OK" on 0,
 * "ERROR_TYPE" on 1, "LESS_EQUAL_ZERO" 
 * on 2.
*/
#define OK 0
#define ERROR_TYPE 1
#define LESS_EQUAL_ZERO 2

/*
 * The function which takes two natural 
 * numbers and returns their greatest
 * common divisor.
*/
int gcd(int a, int b)
{
    if ((a <= 0) || (b <= 0))
        return LESS_EQUAL_ZERO;

    int t;   
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }

    while (b > 0)
    {
        t = a;
        a = b;
        b = t % b;
    }

    return a;
}


/*
 * The function in which data is entered.
 * Returns 0 if the program work succesful
 * and data entered correctly.
*/
int main(void)
{
    int number_f, number_s;
	
    printf("Input the two natural numbers with space: ");
    int rc = scanf("%d %d", &number_f, &number_s);

    if (rc != 2)
    {
        printf("Tne type of numbers entered incorrectly.");
        return ERROR_TYPE;
    }
	
    int result = gcd(number_f, number_s);

    if (result == LESS_EQUAL_ZERO)
    {
        printf("The numbers less than zero or equal zero");
        return LESS_EQUAL_ZERO;
    }
	
    printf("The greatest common divisor is %d", result);
	
    return OK;
}

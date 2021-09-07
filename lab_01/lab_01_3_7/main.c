/*
 * The program is written by Khamzina R., IU7-23B.
 * Given: the argument and epsilon.
 * Find: the value of function witn 
 * this argument and epsilon, exact
 * value, absolute and relative errors.
*/

/*
 * The preprocessor must include to the
 * file stdio.h to enable input and ouput
 * of values, file math.h to using functions
 * fabs and atan.
*/
#include <stdio.h>
#include <math.h>

/*
 * Replaces the macros name "OK" on 0
 * "EPS" - on 1e-6.
*/
#define OK 0
#define TYPE_ERROR_X 1
#define X_MORE_THAN_ONE 2
#define TYPE_ERROR_EPS 3
#define EPS_MORE_THAN_ONE 4
#define EPS 1e-6

/*
 * The function which takes value of argument
 * and epsilon.
 * Returns approximate value.
*/
double approximation(double x, double eps)
{
    int n = 1;
    double now_member = x;
    double approx_amount = 0;

    while (fabs(now_member) > eps)
    {
        approx_amount += now_member;
        now_member = (now_member * (-1) * x * x * n) / (n + 2);
        n += 2;
    }

    return approx_amount;
}

/*
 * The function takes approximate value and 
 * exact value of function.
 * Returns absolute error.
*/
double abs_error(double approx, double exact)
{
    return fabs(exact - approx);
}

/*
 * The function takes approximate valude and
 * exact value of function.
 * Returns relative error.
*/
double rel_error(double approx, double exact)
{
    return fabs((exact - approx) / exact);
}

/*
 * The function in which data is enterd.
 * Returns 0 if data entered correctly
 * and program work succesful.
*/
int main(void)
{
    double x;
    double eps;
    printf("Input the argument x: ");
    
    int rx = scanf("%lf", &x);
    if (rx != 1)
    {
        printf("The type of argument entered incorrectly");
        return TYPE_ERROR_X;
    }
    
    if ((fabs(x) - 1) > EPS)
    {
        printf("The argument more than one");
        return X_MORE_THAN_ONE;
    }
    
    printf("Input the epsilon: ");
    int reps = scanf("%lf", &eps);
    
    if (reps != 1)
    {
        printf("The type of epsilon entered incorrectly");
        return TYPE_ERROR_EPS;
    }

    if ((eps - 1) > EPS)
    {
        printf("The epsilon more than one");
        return EPS_MORE_THAN_ONE;
    }
    
    printf("Approximate value is %.6f\n", approximation(x, eps));
    printf("Exact value is %.6f\n", atan(x));
    printf("Abs. mistake is %.6f\n", abs_error(approximation(x, eps), atan(x)));
    printf("Rel. mistake is %.6f\n", rel_error(approximation(x, eps), atan(x)));
    
    return OK;
}

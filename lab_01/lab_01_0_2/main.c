/*
 * The program is written by Khamzina R.R., IU7-23B.
 * Given: the bases of the isosceles
 * trapezoid and its height. 
 * Find: the isosceles trapezoid perimeter. 
*/

/*
 * Replaces the macros names "OK" on 0.
*/
#define OK 0

/*
 * The preprocessor must include to the file
 * stdio.h to enable input and output of values,
 * math.h to use functions sqrt, fabs, pow.
*/
#include <stdio.h>
#include <math.h>

/*
 * The function in which the perimeter is 
 * counted and displayed. Returns 0 if the 
 * program work succesful.
*/
int main(void)
{
    float f_base, s_base;
    float height;

    printf("Input the trapezoid bases with a space: ");
    scanf("%f %f", &f_base, &s_base);
    printf("Input the height of the trapezoid: ");
    scanf("%f", &height);

    float perimeter = f_base + s_base +
        2 * sqrt(height * height + pow((fabs(f_base - s_base) / 2), 2));
    printf("The perimeter of the trapezoid: %.5f", perimeter);

    return OK;
}

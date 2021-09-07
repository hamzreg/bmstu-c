/*
 * The program is written by Khamzina R., IU7-23B.
 * Given: the coordinates of the line
 * points and of the point A.
 * Find: the relative position of a
 * point and line.
*/

/*
 * The preprocessor must include to the
 * file stdio.h to enable input and 
 * output of values, to the file math.h
 * to using the function fabs.
*/
#include <stdio.h>
#include <math.h>

/*
 * Replaces the macros names "OK" on 0,
 * "EPS" - on 1e-6,
 * "ON LINE" - on 1, "UNDER LINE" - on 2,
 * "OVER LINE" - on 0.
*/
#define OK 0
#define OVER_LINE 0
#define ON_LINE 1
#define UNDER_LINE 2
#define TYPE_FIRST_POINT 3
#define TYPE_SECOND_POINT 4
#define LINE_NOT_EXIT 5
#define TYPE_POINT_A 6
#define EPS 1e-6

/*
 * The function which takes the coordinates
 * of the line points and of the point A.
 * Returns 1 if the point over the line,
 * 0 if the point on the line, 2 if the point
 * under the line.
*/
int line_point(double x1, double y1, double x2, double y2, double x, double y)
{
    double oblique_product = (x - x1) * (y2 - y1) - (y - y1) * (x2 - x1);
    
    if (fabs(oblique_product) <= EPS)
        return ON_LINE;
    else if (oblique_product > EPS)
        return UNDER_LINE;
    return OVER_LINE;
}

/*
 * The function in which data is entered.
 * Returns 0 if the program work succesful
 * and data entered correctly.
*/
int main(void)
{
    double x1, y1;
    double x2, y2;
    double x_p, y_p;
    printf("Input the coordinates of the first point of the line: ");

    int rc1 = scanf("%lf %lf", &x1, &y1);
    if (rc1 != 2)
    {
        printf("The coordinates of first line point entered incorrectly");
        return TYPE_FIRST_POINT;
    }
    
    printf("Input the coordinates of the second point of the line: ");
    int rc2 = scanf("%lf %lf", &x2, &y2);
    
    if (rc2 != 2)
    {
        printf("The coordinates of second line point entered incorrectly");
        return TYPE_SECOND_POINT;
    }
    
    if ((fabs(x1 - x2) <= EPS) && (fabs(y1 - y2) <= EPS))
    {
        printf("The line does not exist");
        return LINE_NOT_EXIT;
    }
    
    printf("Input the coordinates of the point: ");
    int rc_p = scanf("%lf %lf", &x_p, &y_p);
    
    if (rc_p != 2)
    {
        printf("The coordinates of point entered incorrectly");
        return TYPE_POINT_A;
    }
    
    printf("Possible results:\n");
    printf("zero - over the line;\n");
    printf("one - on the line;\n");
    printf("two - under the line.\n");
    printf("Result: %d", line_point(x1, y1, x2, y2, x_p, y_p));
    
    return OK;
}

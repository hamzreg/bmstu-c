/*
 * The program is written by Khamzina R., IU7-23B.
 * Given: the height of the human in
 * cm, the leght of the human chest 
 * in cm and the weight of the human
 * in kg.
 * Find: the normal weight of the human
 * and the index of the human.
*/

/*
 * The preprocessor must include to the
 * file stdio.h to enable input and output
 * of values.
*/
#include <stdio.h>

/*
 * Replase the macros name "OK" on 0,
 * "COEFFICIENT" - on 240, "METR" - on 100.
*/
#define OK 0
#define COEFFICIENT 240
#define METR 100

/* The function in which the normal weight
 * of the human and the index of the human
 * are counted and displayed. Returns 0 if
 * the program work succesful.
*/
int main(void)
{
    float height, len_chest, weight;

    printf("Input the height of the human in cm: ");
    scanf("%f", &height);
    printf("Input the length of the human chest in cm: ");
    scanf("%f", &len_chest);
    printf("Input the weight of the human in kg: ");
    scanf("%f", &weight);

    float normal_weight = height * len_chest / COEFFICIENT;
    printf("The normal weight of the human - %.5f kg\n", normal_weight);
    float weight_index = weight / ((height / METR) * (height / METR));
    printf("The index of the human - %.5f kg/(m*m)", weight_index);

    return OK;
}

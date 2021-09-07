/*
 * The program is written by Khamzina R., IU7-23B.
 * Given: the amount of money in kop.
 * Find: the maximum number of bottles
 * that you can buy if a water bottle
 * costs 45 kop., you can give an empty
 * one for 20 kop.
*/ 

/*
 * The preprocessor must include to the
 * file stdio.h to enable input and
 * output of values. 
*/
#include <stdio.h>

/*
 * Replaces the macros names "OK" on 0, COST_WATER
 * - 25, COST_BOTTLE - 20.
*/
#define OK 0
#define COST_WATER 25
#define COST_BOTTLE 20

/*
 * The function in which the maximum number
 * of bottles that can be bought is counted
 * and displayed. Returns 0 if the program
 * work succesful.
*/
int main(void)
{
    int condition;

    printf("Input the amount of money in kop.: ");
    scanf("%d", &condition);
    
    int amount = (condition - COST_BOTTLE) / COST_WATER;
    printf("Can buy %d bottles", amount);
    
    return OK;
}

#ifndef POLYNOM_T_H
#define POLYNOM_T_H

#include "multiplier_t.h"

typedef struct polynom_t
{
    int power;
    multiplier_t *head;
    multiplier_t *tail;
} polynom_t;

#endif

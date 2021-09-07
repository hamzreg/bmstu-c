#ifndef LIST_T_H
#define LIST_T_H

#include <stdio.h>

#include "node_t.h"

typedef struct list_t
{
    int size;
    node_t *head;
} list_t;

#endif

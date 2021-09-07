#ifndef NODE_T
#define NODE_T

#include <stdio.h>
#include "constants.h"

typedef struct node_t
{
    char *word;
    struct node_t *next;
} node_t;

#endif
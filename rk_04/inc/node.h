#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node_t.h"

node_t *create_node(char *word);

node_t *add_node(node_t *head, node_t *node);

#endif
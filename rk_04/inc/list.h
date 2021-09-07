#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_t.h"
#include "node.h"
#include "constants.h"

void list_init(list_t *list);

void free_list(node_t *head);

int read_list(list_t *list, const char *filename);

int write_list(node_t *head, const char *filename);

void reverse_list(node_t *head);

void print_list(node_t *head);


#endif
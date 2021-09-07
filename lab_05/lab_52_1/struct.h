#ifndef STRUCT_H
#define STRUCT_H
#define MAX_LEN_SURNAME 25
#define MAX_LEN_NAME 10
#define COUNT_SUBJECT 4

typedef struct
{
    char surname[MAX_LEN_SURNAME + 1];
    char name[MAX_LEN_NAME + 1];
    unsigned int marks[COUNT_SUBJECT];
} student;

#endif

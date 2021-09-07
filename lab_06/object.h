#ifndef OBJECT_H
#define OBJECT_H
#define MAX_LEN_NAME 25

typedef struct
{
    char name[MAX_LEN_NAME + 1];
    float mass;
    float volume;
} object;

#endif

#ifndef ARRAY_PROCESS_H
#define ARRAY_PROCESS_H
#define YES 1
#define NO 0
#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 16
#endif
#define MORE_WORD_LEN 5
#define OK 0

int separator(char ch);

int make_array(const char *str, char (*array)[MAX_WORD_LEN + 1], int *const size);

void shift(char (*array)[MAX_WORD_LEN + 1], const int i, int size);

void remove_repet(char (*array)[MAX_WORD_LEN + 1], int *size);

void arrange_array(char (*array)[MAX_WORD_LEN + 1], const int size);

#endif    

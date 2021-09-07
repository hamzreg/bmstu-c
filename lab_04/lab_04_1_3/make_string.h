#ifndef MAKE_STRING_H
#define MAKE_STRING_H
#define YES 1
#define NO 0
#define EMPTY 4
#define ONE_WORD 2
#define EQUAL 0
#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 16
#endif
#define MORE_WORD_LEN 5
#define OK 0

int separator(char ch);

int make_array(const char *str, char (*array)[MAX_WORD_LEN + 1], int *const size);

void shift(char *word, const int i, const int size);

void transform_word(char *word);

int make_string(char *str, char (*array)[MAX_WORD_LEN + 1], const int size);

#endif    

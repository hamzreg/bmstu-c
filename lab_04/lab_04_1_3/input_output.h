#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H
#define MAX_LINE_LEN 256
#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 16
#endif
#define MAX_WORD_COUNT 128
#define MORE_MAX_LEN 1
#define NOT_READ 2
#define ONLY_SEP 3
#define EMPTY 4
#define OK 0

int input(char *const str);

void output(const char *str);

#endif

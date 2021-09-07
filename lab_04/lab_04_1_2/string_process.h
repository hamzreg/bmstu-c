#ifndef STRING_PROCESS_H
#define STRING_PROCESS_H
#define LESS 1
#define MORE 2
#define EQUAL 0
#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 16
#endif
int compare_strings(const char *str1, const char *str2);

void swap(char *const str1, char *const str2);

#endif    
    

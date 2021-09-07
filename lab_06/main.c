#include <stdio.h>
#include <string.h>
#include "return_codes.h"
#include "constants.h"
#include "object.h"
#include "file_size.h"
#include "array_objects.h"

int main(int argc, char **argv)
{
    if ((argc < 2) || (argc > 3))
        return ERROR_ARGC;
    
    object items[MAX_COUNT_OBJECTS];
    int count_objects;
    FILE *f = fopen(argv[1], "r");
    
    if (f == NULL)
        return ERROR_FILE_OPEN;

    int code = check_file_size(f);

    if (code != OK)
        return code;

    code = create_array_objects(f, items, &count_objects);

    if (code != OK)
        return code;

    if (fclose(f) != OK)
        return ERROR_FILE_CLOSE;

    if (argc == 2)
    {
        sort_array_objects(items, 0, count_objects - 1);
        print_array_objects(items, count_objects);
    }

    if (argc == 3)
    {
        if (strcmp(argv[2], ALL) == 0)
            print_array_objects(items, count_objects);
        else
            print_some_objects(argv[2], items, count_objects);
    }

    return OK;
}

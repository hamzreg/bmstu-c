#include "../inc/base_functions.h"


int check_argc(const int argc, char **argv)
{
    if (argc < 3 || argc > 4)
    {
        LOG_ERROR("%s", "Invalid number of arguments");
        return ERROR_ARGC;
    }

    if (argc == 4)
        if (strcmp("f", argv[3]) != OK)
            return ERROR_COMMAND;
    
    return OK;
}


int read_array(const char *filename, array_t *array)
{
    FILE *in_file = fopen(filename, "r");

    if (in_file == NULL)
    {
        LOG_ERROR("%s", "File open error");
        return FILE_OPEN_ERROR;
    }
    LOG_INFO("%s", "Input file open");

    int code = get_array_len(in_file, array);

    if (code != OK)
        return code;
    LOG_INFO("Array len is %d", array.len);

    array->start = malloc(array->len * sizeof(int));

    if (array->start == NULL)
    {
        LOG_ERROR("%s", "Memory allocation error");
        return MEMORY_ERROR;
    }
    LOG_INFO("%s", "Array created");

    rewind(in_file);

    code = fill_array(in_file, array->start,
    array->start + array->len);

    if (code != OK)
    {
        free(array->start);
        return code;
    }
    LOG_INFO("%s", "Array filled");

    if (fclose(in_file))
    {
        free(array->start);

        LOG_ERROR("%s", "File close error");
        return FILE_CLOSE_ERROR;
    }
    LOG_INFO("%s", "Input file close");

    return OK;
}


int write_array(const char *filename, array_t *array,
const int argc)
{
    FILE *out_file = fopen(filename, "w");

    if (out_file == NULL)
    {
        free(array->start);

        LOG_ERROR("%s", "File open error");
        return FILE_OPEN_ERROR;
    }
    LOG_INFO("%s", "Output file open");

    if (argc == 3)
    {
        mysort(array->start, array->len, sizeof(int), compare_int);
        LOG_INFO("%s", "Array is sorted");

        write_array_file(out_file, array->start,
        array->start + array->len);

        free(array->start);
    }

    if (argc == 4)
    {
        array_t new;
        int *end;

        int code = key(array->start, array->start + array->len,
        &new.start, &end);

        free(array->start);

        if (code != OK)
            return code;
        LOG_INFO("%s", "Array filtered");

        new.len = end - new.start;
        LOG_INFO("New array len is %d", new_array.len);

        mysort(new.start, new.len, sizeof(int), compare_int);
        LOG_INFO("%s", "Array is sorted");

        write_array_file(out_file, new.start, new.start + new.len);
        free(new.start);
    }
    LOG_INFO("%s", "Numbers written to file");


    if (fclose(out_file))
    {
        LOG_ERROR("%s", "File close error");
        return FILE_CLOSE_ERROR;
    }
    LOG_INFO("%s", "File close");

    return OK;
}

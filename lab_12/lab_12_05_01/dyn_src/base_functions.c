#include <dlfcn.h>

#include "../inc/base_functions.h"

typedef int (*fn_get_len_t)(FILE*, array_t *const);

typedef int (*fn_fill_t)(FILE*, int *const, int *const);


typedef int (*fn_key_t)(const int*, const int*, int**, int**);

typedef void (*fn_mysort_t)(void*, size_t, size_t,
int (*compar)(const void *, const void *));

typedef int (*fn_compar_int_t)(const void*, const void*);

typedef void (*fn_write_t)(FILE*, const int* const,
const int* const);


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
    void *hlib = dlopen("./libs/libarray.so", RTLD_NOW);

    if (!hlib)
    {
        LOG_ERROR("Lib open error, line is %s", dlerror());
        return LIB_OPEN_ERROR;
    }

    fn_get_len_t len_array = (fn_get_len_t) dlsym(hlib, "len_array");

    if (!len_array)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

    fn_fill_t fill_array  = (fn_fill_t) dlsym(hlib, "fill_array");

    if (!fill_array)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

    FILE *in_file = fopen(filename, "r");

    if (in_file == NULL)
    {
        LOG_ERROR("%s", "File open error");
        return FILE_OPEN_ERROR;
    }
    LOG_INFO("%s", "Input file open");

    int code = len_array(in_file, array);

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

    dlclose(hlib);

    return OK;
}


int write_array(const char *filename, array_t *array,
const int argc)
{
    void *hlib = dlopen("./libs/libarray.so", RTLD_NOW);

    if (!hlib)
    {
        LOG_ERROR("Lib open error, line is %s", dlerror());
        return LIB_OPEN_ERROR;
    }

    fn_key_t key = (fn_key_t) dlsym(hlib, "key");

    if (!key)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

    fn_mysort_t mysort  = (fn_mysort_t) dlsym(hlib, "mysort");

    if (!mysort)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

    fn_compar_int_t compare = (fn_compar_int_t) dlsym(hlib, "compare");

    if (!compare)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

    fn_write_t write_array = (fn_write_t) dlsym(hlib, "write_array");

    if (!write_array)
    {
        LOG_ERROR("Func open error, line is %s", dlerror());
        return FUNC_LOAD_ERROR;
    }

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
        mysort(array->start, array->len, sizeof(int), compare);
        LOG_INFO("%s", "Array is sorted");

        write_array(out_file, array->start,
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

        mysort(new.start, new.len, sizeof(int), compare);
        LOG_INFO("%s", "Array is sorted");

        write_array(out_file, new.start, new.start + new.len);
        free(new.start);
    }
    LOG_INFO("%s", "Numbers written to file");


    if (fclose(out_file))
    {
        LOG_ERROR("%s", "File close error");
        return FILE_CLOSE_ERROR;
    }
    LOG_INFO("%s", "File close");

    dlclose(hlib);

    return OK;
}

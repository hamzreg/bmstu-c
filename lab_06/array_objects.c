#include "array_objects.h"

int create_array_objects(FILE *f, object *const items, int *const count)
{
    *count = 0;
    int code;
    
    while (!feof(f))
    {
        if (*count == MAX_COUNT_OBJECTS)
            return COUNT_OBJECTS_MORE_MAX;
 
        if (fgets(items[*count].name, MAX_LEN_NAME + 1, f) == NULL)
            return NO_ALL_FIELDS;

        if (strlen(items[*count].name) > MAX_LEN_NAME)
            return ERROR_LEN_NAME;

        code = fscanf(f, "%f\n", &(items[*count].mass));

        if (code != 1)
            return NO_ALL_FIELDS;

        if (items[*count].mass < 0)
            return ERROR_MASS;
 
        code = fscanf(f, "%f\n", &(items[*count].volume));

        if (code != 1)
            return NO_ALL_FIELDS;
        
        if (items[*count].volume < 0)
            return ERROR_VOLUME;
        
        (*count)++;
    }
   
    return OK;
}

void sort_array_objects(object *const items, const int start, const int end)
{
    object item;
    int left = start, right = end, middle = (start + end) / 2; 
    float now_density, average_density = items[middle].mass /
        items[middle].volume;

    while (left <= right)
    {
        now_density = items[left].mass / items[left].volume;

        while (now_density < average_density)
        {
            left++;
            now_density = items[left].mass / items[left].volume;
        }

        now_density = items[right].mass / items[right].volume;

        while (now_density > average_density)
        {
            right--;
            now_density = items[right].mass / items[right].volume;
        }

        if (left <= right)
        {
            item = items[left];
            items[left] = items[right];
            items[right] = item;

            left++;
            right--;
        }
    }

    if (right > start)
        sort_array_objects(items, start, right);

    if (left < end)
        sort_array_objects(items, left, end); 
}

void print_array_object(const object item)
{
    printf("%s", item.name);
    printf("%.6f\n", item.mass);
    printf("%.6f\n", item.volume);
}

void print_array_objects(const object *const items, const int count)
{
    for (int i = 0; i < count; i++)
        print_array_object(items[i]);
}

void print_some_objects(const char *const str, const object *const items, const int count)
{
    size_t len = strlen(str);

    for (int i = 0; i < count; i++)
        if (strncmp(items[i].name, str, len) == 0)
            print_array_object(items[i]);
}

#include <stdio.h>
#include "../inc/list.h"

int main(int argc, char **argv)
{
    list_t list;
    list_init(&list);

    int code = read_list(&list, argv[1]);

    if (code)
        return code;

    //reverse_list(list.head);

    code = write_list(list.head, argv[2]);

    free_list(list.head);

    return code;
}

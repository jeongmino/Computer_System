#include "show_bit.h"

void operation(int *arr, char *operator)
{
    if (!strcmp(operator, "+"))
        plus(arr);
    else if (!strcmp(operator, ">>"))
        right_shift(arr);
    else if (!strcmp(operator, "<<"))
        left_shift(arr);
    else if (!strcmp(operator, "|"))
        or_operation(arr);
    else if (!strcmp(operator, "&"))
        and_operation(arr);
    else if (!strcmp(operator, "^"))
        sym_diff(arr);
    else if (!strcmp(operator, "~"))
        not_operation(arr);
    // else if (!strcmp(operator, "!"))
    //     boolean_not_operation(arr);
    else if (!strcmp(operator, "="))
        return ;
    else
    {
        printf("Wrong operation\n");
        exit(1);
    }
}
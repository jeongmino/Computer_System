#include "show_bit.h"

void not_operation(int *arr)
{
    for (int i = 0; i < 32; i++)
    {
        if (arr[i])
            arr[i] = 0;
        else
            arr[i] = 1;
    }
}
#include "show_bit.h"

void plus(int *arr)
{
    int operand_bit;
    int *add_arr;
    int *ret;

    add_arr = (int *)malloc(sizeof(int) * 32);
    ret = (int *)malloc(sizeof(int) * 32);
    printf("input your number : ");
    scanf("%d", &operand_bit);
    change_into2(add_arr, operand_bit);
    print_bit(arr);
    printf("\n");
    print_bit(add_arr);
    printf("\n");
    for (int i = 31; i >= 0; i--)
    {
        ret[i] += add_arr[i] + arr[i];
        if (ret[i] >= 2)
        {
            ret[i] -= 2;
            if (i != 0)
                ret[i + 1] += 1;
        }
    }
    for (int i = 0; i < 32; i++)
        arr[i] = ret[i];
    free(ret);
    free(add_arr);
}
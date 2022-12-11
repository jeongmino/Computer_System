#include "show_bit.h"

void or_operation(int *arr)
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
    for (int i = 0; i < 32; i++)
    {
        if (arr[i] || add_arr[i])
            ret[i] = 1;
        else
            ret[i] = 0;
    }
    for (int i = 0; i < 32; i++)
        arr[i] = ret[i];
    free(ret);
    free(add_arr);
}

void and_operation(int *arr)
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
    for (int i = 0; i < 32; i++)
    {
        if (arr[i] & add_arr[i])
            ret[i] = 1;
        else
            ret[i] = 0;
    }
    for (int i = 0; i < 32; i++)
        arr[i] = ret[i];
    free(ret);
    free(add_arr);    
}

void    sym_diff(int *arr)
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
    for (int i = 0; i < 32; i++)
    {
        if ((arr[i] ^ add_arr[i]) == 1)
            ret[i] = 1;
        else
            ret[i] = 0;
    }
    for (int i = 0; i < 32; i++)
        arr[i] = ret[i];
    free(ret);
    free(add_arr);    
}
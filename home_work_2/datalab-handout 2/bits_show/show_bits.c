#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "show_bit.h"

void change_into2(int *arr, int bit)
{
    int mok, nmg, idx; 
    mok = 0;
    nmg = 0;
    idx = 0;
    if (bit >= 0)
    {
        do 
        {
            mok = bit / 2;
            nmg = bit - mok * 2;
            arr[idx++] = nmg;
            bit = mok;
        } while (mok != 0);
        while (idx < 32)
            arr[idx++] = 0;
    }
    else if (bit < 0 && bit != INT_MIN)
    {
        bit *= -1;
        for (int i = 0; i < 32; i++)
        {
            arr[i] = bit % 2;
            bit >>= 1;
        }
        for (int i = 0; i < 32; i++)
            (arr[i] == 0) ? (arr[i] = 1) : (arr[i] = 0);
        arr[0] += 1;
        for (int i = 0; i < 31; i++)
        {
            if (arr[i] == 2)
            {
                arr[i] = 0;
                arr[i + 1] += 1;
            }
            else
                break;
        }
    }
    else if (bit == INT_MIN)
    {
        arr[0] = 1;
        for (int i = 1; i < 32; i++)
            arr[i] = 0;
    }
    return ;
}

void print_bit(int *arr)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", arr[i]);
        if (i % 4 == 0 && i != 0)
            printf("  ");
    }
    return ;
}

int main(void)
{
    int bit, c;
    char operator[2];
    int *bit_arr;
    

    bit_arr = (int *)malloc(32 * sizeof(int));
    while (1)
    {
        bit = 0;
        c= 0;
        memset(bit_arr, 0, 32);
        memset(operator, 0, 2);
        printf("input your number : ");
        scanf("%d", &bit);
        printf("input your operator : ");
        scanf("%s", operator);
        change_into2(bit_arr, bit);
        operation(bit_arr, operator);
        print_bit(bit_arr);
        // for (int i = 31; i >= 0; i--)
        // {
        //     printf("%d", bit_arr[i]);
        //     if (i % 4 == 0 && i != 0)
        //         printf("  ");
        // }
        printf("\n");
    }
    free(bit_arr);
    return 0;
}
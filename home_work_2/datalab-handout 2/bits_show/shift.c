#include "show_bit.h"

void right_shift(int *arr)
{
    int shift;
    int *tmp = (int *)malloc(sizeof(int) * 32);
    const int LSB = arr[31];

    printf("how many you want shift? : ");
    scanf("%d", &shift);
    for (int i = 31; i >= shift; i--)
        tmp[i - shift] = arr[i];
    for (int i = 31; i >= 31 - shift; i--)
        tmp[i] = LSB;
    for (int i = 0; i < 32; i++)
        arr[i] = tmp[i];
    free(tmp);
}

void left_shift(int *arr)
{
    int shift;
    int *tmp = (int *)malloc(sizeof(int) * 32);

    printf("how many you want shift? : ");
    scanf("%d", &shift);
    for (int i = 32 - shift; i >= 0; i--)
        tmp[i + shift] = arr[i];
    for (int i = 0; i < shift; i++)
        tmp[i] = 0;
    for (int i = 0; i < 32; i++)
        arr[i] = tmp[i];
    free(tmp);
}
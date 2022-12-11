#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char* str1;
    char str2[100];

    str1 = malloc(9);
    strcpy(str1, "20102115");
    printf("str1: %s, %p\n", str1, str1);
    strcpy(str2, "20102115");
    printf("str2: %s, %p\n", str2, str2);
    free(str1);
    return (0);


}
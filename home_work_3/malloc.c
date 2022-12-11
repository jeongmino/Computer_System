#include <stdio.h>
#include <stdlib.h>

struct rec
{
    int i;
    float PI;
    char A;
};

int main(void)
{
    struct rec *ptr_one;

    ptr_one = malloc(sizeof(struct rec));
    printf("-----------------------------------------------------\n");
    printf("Memory is allocated at by %p (size: %lu)\n", ptr_one, sizeof(struct rec));
    ptr_one->i = 10;
    printf("First value: %d\n", ptr_one->i);
    ptr_one->PI = 3.14;
    printf("Second value: %f\n", ptr_one->PI);
    ptr_one->A = 'a';
    printf("Third value: %c\n", ptr_one->A);
    printf("-----------------------------------------------------\n");
    printf("Memory is deallocated at by %p\n", ptr_one);
    free(ptr_one);
    return (0);
}

#include <stdio.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n\n");
    int max = 4;
    int var[] = {100, 200, 300, 20102115};
    int i, *ptr;

    ptr = var;

    for (i = 0; i < max; i++)
    {

        printf("\n\n\nAdress of var[%d] = %p ", i, ptr);
        printf("\nValue of var[%d] = %d ", i, *ptr++);
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return (0);
}

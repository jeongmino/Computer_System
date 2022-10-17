#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int *array, position, c, n, value;

    printf("\n\nEnter number of elements in array: ");
    scanf("%d", &n);

    array = (int *)calloc(sizeof(int), n);
    if (array == NULL)
    {
        printf("malloc fail\n");
        return (0);
    }
    printf("\n\nEnter %d elements\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    printf("\n\nEnter the location where you want to  insert new element:  ");
    scanf("%d", &position);

    printf("\n\nEnter the value to insert: ");
    scanf("%d", &value);

    printf("\n\nResultant array is: ");
    c = -1;
    while (++c < n)
    {
        if (c == position -1)
            printf("%d ", value);
        printf("%d ", array[c]);
    }
    free(array);
    printf("\n\n\t\tCoding is Fun !\n\n\n");
}

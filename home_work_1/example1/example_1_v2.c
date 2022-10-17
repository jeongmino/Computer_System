#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int *array, position, c, n, value;

    printf("\n\nEnter number of elements in array: ");
    scanf("%d", &n);

    // make array using malloc (n + 1)
    array = (int*)malloc(sizeof(int) * (n + 1));
    if (array == NULL)
        return (1);
    printf("\n\nEnter %d elements\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    

    printf("\n\nEnter the location where you want to  insert new element:  ");
    scanf("%d", &position);

    printf("\n\nEnter the value to insert: ");
    scanf("%d", &value);

    for(c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    array[position - 1] = value;

    printf("\n\nResultant array is: ");

    for (c = 0; c <= n; c++)
        printf("%d ", array[c]);

    printf("\n\n\t\tCoding is Fun !\n\n\n");

    free(array);
    return (0);
}
#include <stdio.h>

void fibonacci (int num);
int main()
{
    int num = 0;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("invalid number of arguments\n");
        return (1);
    }
    fibonacci(num);
    return (0);
}
void fibonacci (int num)
{
    int a, b, c, i;
    a = 0;
    b = 1;

    if (num == 1)
    {
        printf("%d", a);
        return ;
    }
    if (num >= 2)
    {
        printf("%d\t%d", a, b);
        if (num == 2)
            return ;
    }
    for (i = 3; i <= num; i++)
    {
        c = a + b;
        printf("\t%d", c);
        a = b;
        b = c;
    }
}

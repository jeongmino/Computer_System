#include <stdio.h>

int main(void)
{
	long *dest;
	long t = 2;
	dest = NULL;
	*dest = t;

	printf("Addres of t = %p\n", &t);
	printf("value of dest = %ld\n", dest);
	printf("addrest of dest = %p\n", &dest);
	return (0);
}

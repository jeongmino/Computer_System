#include <stdio.h>

int main(void)
{
	int sub = 0x1;
	sub = sub << 31;
	int minus = 0xff;
    minus = minus << 24;
    minus = minus >> 24; // minus is -1; minus = 0xffffffff
	printf("sub = %d\n", sub);
	printf("minus = %d\n", minus);
	return (0);
}

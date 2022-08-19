#include <stdio.h>

int main(void)
{
	int		n;
	int		sum;

	scanf("%d", &n);
	sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	printf("%d\n", sum);
	return (0);
}

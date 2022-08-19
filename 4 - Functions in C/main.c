#include <stdio.h>

static int	max_of_four(int a, int b, int c, int d);

int	main(void)
{
	int		a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n", max_of_four(a, b, c, d));
	return (0);
}

static int	max_of_four(int a, int b, int c, int d)
{
	if (a > b)
	{
		if (a > c)
			return (a > d ? a : d);
	}
	else if (b > c)
			return (b > d ? b : d);
	return (c > d ? c : d);
}

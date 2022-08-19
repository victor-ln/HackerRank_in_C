#include <stdio.h>

static void	update(int *a, int *b);

int	main(void)
{
	int		a, b;
	int		*pa, *pb;

	pa = &a;
	pb = &b;
	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);
	return (0);
}

static void	update(int *a, int *b)
{
	int		c;

	c = *a;
	*a += *b;
	*b = (c > *b) ? c - *b : *b - c;
}

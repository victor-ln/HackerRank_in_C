#include <stdio.h>

static int find_nth_term(int n, int a, int b, int c);

int	main(void)
{
	int		n, a, b, c;

	scanf("%d %d %d %d", &n, &a, &b, &c);
	printf("%d", find_nth_term(n, a, b, c));
	return (0);
}

static int	find_nth_term(int n, int a, int b, int c)
{
	if (n < 1)
		return (0);
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	if (n == 3)
		return (c);
	return (find_nth_term(n - 1, a, b, c) + \
		find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c));
}

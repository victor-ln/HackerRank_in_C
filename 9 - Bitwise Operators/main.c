#include <stdio.h>

static void	calculate_the_maximum(int n, int k);

int	main(void)
{
	int		n, k;

	scanf("%d %d", &n, &k);
	calculate_the_maximum(n, k);
	return (0);
}

static void	calculate_the_maximum(int n, int k)
{
	int		a, o, x, n1, n2;

	n1 = 1;
	n2 = 2;
	a = (n1 & n2) < k ? n1 & n2 : 0;
	o = (n1 | n2) < k ? n1 | n2 : 0;
	x = (n1 ^ n2) < k ? n1 ^ n2 : 0;
	while (n1 < n)
	{
		n2 = n1 + 1;
		while (n2 <= n)
		{
			a = ((n1 & n2) < k) && ((n1 & n2) > a) ? n1 & n2 : a;
			o = ((n1 | n2) < k) && ((n1 | n2) > o) ? n1 | n2 : o;
			x = ((n1 ^ n2) < k) && ((n1 ^ n2) > x) ? n1 ^ n2 : x;
			n2++;
		}
		n1++;
	}
	printf("%d\n", a);
	printf("%d\n", o);
	printf("%d\n", x);
}

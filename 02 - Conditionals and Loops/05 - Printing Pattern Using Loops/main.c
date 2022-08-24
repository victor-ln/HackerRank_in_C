#include <stdio.h>

static void	print_pattern(int n);

int	main(void)
{
	int n;

	scanf("%d", &n);
	print_pattern(n);
	return (0);
}

static void	print_pattern(int n)
{
	int		i, j, k, t;
	
	i = n + n - 1;
	j = n;
	while (i)
	{
		k = n;
		while (j < k)
			printf("%d ", k--);
		t = j + j;
		while (--t)
			printf("%d ", j);
		k = j;
		while (k < n)
			printf("%d ", ++k);
		printf("\n");
		if (i > n)
			j--;
		else
			j++;
		i--;
	}
}

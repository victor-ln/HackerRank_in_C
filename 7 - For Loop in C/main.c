#include <stdio.h>

static void	print_extended(int n);
static void	print_even_or_odd(int n);

int	main(void)
{
	int		a, b;
	int		i;

	scanf("%d\n%d", &a, &b);
	i = a;
	for (; i <= b && (i >= 1 && i <= 9); i++)
		print_extended(i);
	for (; i <= b; i++)
		print_even_or_odd(i);
	return (0);
}

static void	print_extended(int n)
{
	char	*str[9] = {
		"one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine"
	};

	printf("%s\n", str[n - 1]);
}

static void	print_even_or_odd(int n)
{
	if (n & 1)
		printf("odd\n");
	else
		printf("even\n");
}

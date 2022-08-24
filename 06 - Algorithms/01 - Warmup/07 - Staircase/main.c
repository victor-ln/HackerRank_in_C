void	staircase(int n)
{
	int		i;
	int		j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			printf(" ");
		for (; j < n; j++)
			printf("#");
		printf("\n");
	}
}

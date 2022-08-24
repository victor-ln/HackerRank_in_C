#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		*arr;
	int		n;
	int		i;
	int		sum;

	sum = 0;
	scanf("%d\n", &n);
	if (n >= 1 && n <= 1000)
	{
		arr = malloc(sizeof(int) * n);
		i = 0;
		while (i < n)
		{
			scanf("%d", arr + i);
			if (arr[i] >= 1 && arr[i] <= 1000)
				sum += arr[i++];
		}
		free(arr);
	}
	printf("%d\n", sum);
	return (0);
}

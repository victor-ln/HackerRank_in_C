#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		num, *arr, i;

	scanf("%d", &num);
	arr = (int*) malloc(num * sizeof(int));
	for (i = 0; i < num; i++)
		scanf("%d", arr + i);
	for (i = num - 1; i >= 0; i--)
		printf("%d ", *(arr + i));
	free(arr);
	return (0);
}

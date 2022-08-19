#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char	*s;
	int		*arr;
	int		index;
	
	arr = calloc(sizeof(int), 10);
	s = calloc(sizeof(char), 1024);
	index = 0;
	scanf("%[^\n]%*c", s);
	while (s[index])
	{
		if (s[index] >= '0' && s[index] <= '9')
			arr[s[index] - 48]++;
		index++;
	}
	index = 0;
	while (index < 10)
		printf("%d ", arr[index++]);
	free(arr);
	free(s);
	return (0);
}

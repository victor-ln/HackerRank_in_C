#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;
	int		i, n;

	s = malloc(1024 * sizeof(char));
	scanf("%[^\n]", s);
	n = strlen(s);
	s = realloc(s, n + 1);
	i = 0;
	while (i < n)
	{
		if (s[i] == ' ')
			printf("\n");
		else
			printf("%c", s[i]);
		i++;
	}
	free(s);
	return (0);
}

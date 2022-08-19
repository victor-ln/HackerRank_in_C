#include <stdio.h>

int	main(void)
{
	char	s[8];

	while (scanf("%[^\n]%*c", s) != EOF)
		printf("%s\n", s);
	return (0);
}

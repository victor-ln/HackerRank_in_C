#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	next_permutation(int n, char **s);
static void	swap(char **ptr1, char **ptr2);

int	main(void)
{
	char	**s;
	int		n;

	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return (0);
}

/**
 * Returns 0 when there is no next permutation and 1 otherwise
 * Modifies array s to its next permutation
 * This lexicographic order algorithm was formulated by Edsger W.Dijkstra.
 */
static int	next_permutation(int n, char **s)
{
	int				i;
	int				j;

	i = n - 1;
	while (i && strcmp(s[i - 1], s[i]) >= 0)
		i--;
	if (!i)
		return (0);
	j = n;
	while (j > i && strcmp(s[j - 1], s[i - 1]) <= 0)
		j--;
	swap(s + (j - 1), s + (i - 1));
	i++;
	j = n;
	while (i < j)
	{
		swap(s + (i - 1), s + (j - 1));
		i++;
		j--;
	}
	return (1);
}

static void	swap(char **ptr1, char **ptr2)
{
	void	*swp;

	swp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = swp;
}

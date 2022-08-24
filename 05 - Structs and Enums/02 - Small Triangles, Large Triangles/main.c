#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int		a;
	int		b;
	int		c;
};

typedef struct triangle triangle;

float	triangle_area(triangle tr)
{
	return (sqrt((tr.a + tr.b + tr.c) * (-tr.a + tr.b + tr.c) * \
		(tr.a - tr.b + tr.c) * (tr.a + tr.b - tr.c)) / 4);
}

/**
 * Sort an array a of the length n
 */
void	sort_by_area(triangle* tr, int n)
{
	int			i;
	int			j;
	int			min;
	triangle	swp;

	i = 0;
	while (i < n)
	{
		j = i;
		min = j;
		while (j < n)
		{
			if (triangle_area(tr[j]) < triangle_area(tr[min]))
				min = j;
			j++;
		}
		swp = tr[i];
		tr[i] = tr[min];
		tr[min] = swp;
		i++;
	}
}

int	main(void)
{
	int			n;

	scanf("%d", &n);
	triangle	*tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++)
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	return (0);
}

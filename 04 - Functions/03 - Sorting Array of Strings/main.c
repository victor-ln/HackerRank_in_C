#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	string_sort(char** arr, const int len, \
	int (*cmp_func)(const char* a, const char* b));
static int	lexicographic_sort(const char* a, const char* b);
static int	lexicographic_sort_reverse(const char* a, const char* b);
static int	sort_by_length(const char* a, const char* b);
static int	sort_by_number_of_distinct_characters(const char* a, const char* b);

int	main(void)
{
	int		n;
	char**	arr;

	scanf("%d", &n);
	arr = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}
	string_sort(arr, n, lexicographic_sort);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
	string_sort(arr, n, lexicographic_sort_reverse);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
	string_sort(arr, n, sort_by_length);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");
}

static void	string_sort(char** arr, const int len, \
	int (*cmp_func)(const char* a, const char* b))
{
	int		i;
	int		j;
	int		min;
	char	*swp;

	i = -1;
	while (++i < len)
	{
		min = i;
		j = i;
		while (j < len)
		{
			if (cmp_func(arr[j], arr[min]))
				min = j;
			j++;
		}
		swp = arr[i];
		arr[i] = arr[min];
		arr[min] = swp;
	}
}

static int	lexicographic_sort(const char* a, const char* b)
{
	int		i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] < b[i])
			return (1);
		else if (a[i] > b[i])
			return (0);
		i++;
	}
	if (!a[i])
		return (1);
	return (0);
}


static int	lexicographic_sort_reverse(const char* a, const char* b)
{
	return (!lexicographic_sort(a, b));
}

static int	sort_by_number_of_distinct_characters(const char* a, const char* b)
{
	int		i;
	int		aLen;
	int		bLen;
	int		counterA;
	int		counterB;
	char	*analizedA;
	char	*analizedB;

	counterA = 0;
	counterB = 0;
	aLen = strlen(a);
	bLen = strlen(b);
	analizedA = calloc(sizeof(char), aLen);
	analizedB = calloc(sizeof(char), bLen);
	i = 0;
	while (i < aLen)
	{
		if (!i || !strchr(analizedA, a[i]))
			analizedA[counterA++] = a[i];
		i++;
	}
	i = 0;
	while (i < bLen)
	{
		if (!i || !strchr(analizedB, b[i]))
			analizedB[counterB++] = b[i];
		i++;
	}
	free(analizedA);
	free(analizedB);
	if (counterA != counterB)
		return (counterA < counterB);
	return (lexicographic_sort(a, b));
}

static int	sort_by_length(const char* a, const char* b)
{
	int		aLen;
	int		bLen;
	
	aLen = strlen(a);
	bLen = strlen(b);
	if (aLen == bLen)
		return (lexicographic_sort(a, b));
	else
		return (aLen < bLen);
}

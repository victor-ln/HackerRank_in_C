#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char*	readline(void);

int	main(void)
{
	char*	n_endptr;
	char*	n_str = readline();
	int		n = strtol(n_str, &n_endptr, 10);
	char	*str[9] = {
		"one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine"
	};

	if (n_endptr == n_str || *n_endptr != '\0')
		exit(EXIT_FAILURE);
	if (n > 9)
		printf("Greater than 9\n");
	else
		printf("%s\n", str[n - 1]);
	return (0);
}

static char*	readline(void)
{
	size_t	alloc_length = 1024;
	size_t	data_length = 0;
	char*	data = malloc(alloc_length);

	while (true)
	{
		char*	cursor = data + data_length;
		char*	line = fgets(cursor, alloc_length - data_length, stdin);

		if (!line)
			break ;
		data_length += strlen(cursor);
		if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
			break ;
		size_t	new_length = alloc_length << 1;
		data = realloc(data, new_length);
		if (!data)
			break ;
		alloc_length = new_length;
	}

	if (data[data_length - 1] == '\n')
		data[data_length - 1] = '\0';
	data = realloc(data, data_length);
	return (data);
}

#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int*	total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int**	total_number_of_pages;

int	main(void)
{
	int*	total_number_of_books;
	int**	total_number_of_pages;
	int		total_number_of_shelves;
	int		total_number_of_queries;
	int		type_of_query;
	int		x, y;

	scanf("%d", &total_number_of_shelves);
	scanf("%d", &total_number_of_queries);
	total_number_of_books = calloc(sizeof(int), total_number_of_shelves);
	total_number_of_pages = calloc(sizeof(int *), total_number_of_shelves);
	while (total_number_of_queries--)
	{

		scanf("%d", &type_of_query);
		if (type_of_query == 1)
		{
			scanf("%d %d", &x, &y);
			total_number_of_books[x]++;
			total_number_of_pages[x] = realloc(total_number_of_pages[x], \
						total_number_of_books[x] * sizeof(int));
			total_number_of_pages[x][total_number_of_books[x] - 1] = y;
		}
		else if (type_of_query == 2)
		{
			scanf("%d %d", &x, &y);
			printf("%d\n", *(*(total_number_of_pages + x) + y));
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", *(total_number_of_books + x));
		}
	}
	if (total_number_of_books)
		free(total_number_of_books);
	for (int i = 0; i < total_number_of_shelves; i++)
		if (*(total_number_of_pages + i))
			free(*(total_number_of_pages + i));
	if (total_number_of_pages)
		free(total_number_of_pages);
	return (0);
}

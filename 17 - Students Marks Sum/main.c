#include <stdio.h>
#include <stdlib.h>

static int	marks_summation(int* marks, int number_of_students, char gender);

int	main(void)
{
	int		number_of_students;
	char	gender;
	int		*marks;

	scanf("%d", &number_of_students);
	marks = (int *) malloc(number_of_students * sizeof (int));
	for (int student = 0; student < number_of_students; student++)
		scanf("%d", (marks + student));
	scanf(" %c", &gender);
	printf("%d", marks_summation(marks, number_of_students, gender));
	free(marks);
	return (0);
}

static	int marks_summation(int* marks, int number_of_students, char gender)
{
	int		i;
	int		sum;

	i = gender == 'g';
	sum = 0;
	while (i < number_of_students){
		sum += marks[i];
		i += 2;
	}
	return (sum);
}


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

static int	test_implementations_by_sending_three_elements(void);
static int	test_implementations_by_sending_five_elements(void);
static int	test_implementations_by_sending_ten_elements(void);
static int	sum(int count,...);
static int	min(int count,...);
static int	max(int count,...);

int	main(void)
{
	int		number_of_test_cases;

	scanf("%d", &number_of_test_cases);
	while (number_of_test_cases--) {
		if (test_implementations_by_sending_three_elements()) {
			printf("Correct Answer\n");
		} else {
			printf("Wrong Answer\n");
		}
		
		if (test_implementations_by_sending_five_elements()) {
			printf("Correct Answer\n");
		} else {
			printf("Wrong Answer\n");
		}
		
		if (test_implementations_by_sending_ten_elements()) {
			printf("Correct Answer\n");
		} else {
			printf("Wrong Answer\n");
		}
	}
	return (0);
}

static int	sum(int count,...)
{
	int			i;
	int			result;
	va_list		numbers;

	i = -1;
	result = 0;
	va_start(numbers, count);
	while (++i < count)
		result += va_arg(numbers, int);
	va_end(numbers);
	return (result);
}

static int	min(int count,...)
{
	int			i;
	int			aux;
	int			result;
	va_list		numbers;

	i = -1;
	result = MAX_ELEMENT;
	va_start(numbers, count);
	while (++i < count)
	{
		aux = va_arg(numbers, int);
		if (aux < result)
			result = aux;
	}
	va_end(numbers);
	return (result);
}

static int	max(int count,...)
{
	int			i;
	int			aux;
	int			result;
	va_list		numbers;

	i = -1;
	result = MIN_ELEMENT;
	va_start(numbers, count);
	while (++i < count)
	{
		aux = va_arg(numbers, int);
		if (aux > result)
			result = aux;
	}
	va_end(numbers);
	return (result);
}

static int	test_implementations_by_sending_three_elements(void)
{
	int		elements[3];

	srand(time(NULL));
	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

	fprintf(stderr, "Sending following three elements:\n");
	for (int i = 0; i < 3; i++) {
		fprintf(stderr, "%d\n", elements[i]);
	}

	int		elements_sum = sum(3, elements[0], elements[1], elements[2]);
	int		minimum_element = min(3, elements[0], elements[1], elements[2]);
	int		maximum_element = max(3, elements[0], elements[1], elements[2]);

	fprintf(stderr, "Your output is:\n");
	fprintf(stderr, "Elements sum is %d\n", elements_sum);
	fprintf(stderr, "Minimum element is %d\n", minimum_element);
	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);
	
	int		expected_elements_sum = 0;
	for (int i = 0; i < 3; i++) {
		if (elements[i] < minimum_element) {
			return 0;
		}
		
		if (elements[i] > maximum_element) {
			return 0;
		}
		
		expected_elements_sum += elements[i];
	}
	return (elements_sum == expected_elements_sum);
}

static int	test_implementations_by_sending_five_elements(void)
{
	int		elements[5];

	srand(time(NULL));
	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

	fprintf(stderr, "Sending following five elements:\n");
	for (int i = 0; i < 5; i++) {
		fprintf(stderr, "%d\n", elements[i]);
	}

	int		elements_sum = sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
	int		minimum_element = min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
	int		maximum_element = max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);

	fprintf(stderr, "Your output is:\n");
	fprintf(stderr, "Elements sum is %d\n", elements_sum);
	fprintf(stderr, "Minimum element is %d\n", minimum_element);
	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

	int		expected_elements_sum = 0;
	for (int i = 0; i < 5; i++) {
		if (elements[i] < minimum_element) {
			return 0;
		}
		
		if (elements[i] > maximum_element) {
			return 0;
		}
		
		expected_elements_sum += elements[i];
	}
	return (elements_sum == expected_elements_sum);
}

static int	test_implementations_by_sending_ten_elements(void)
{
	int		elements[10];

	srand(time(NULL));
	elements[0] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[1] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[2] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[3] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[4] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[5] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[6] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[7] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[8] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
	elements[9] = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;

	fprintf(stderr, "Sending following ten elements:\n");
	for (int i = 0; i < 10; i++) {
		fprintf(stderr, "%d\n", elements[i]);
	}

	int		elements_sum = sum(10, elements[0], elements[1], elements[2], elements[3], elements[4],
						   elements[5], elements[6], elements[7], elements[8], elements[9]);
	int		minimum_element = min(10, elements[0], elements[1], elements[2], elements[3], elements[4],
						   elements[5], elements[6], elements[7], elements[8], elements[9]);
	int		maximum_element = max(10, elements[0], elements[1], elements[2], elements[3], elements[4],
						   elements[5], elements[6], elements[7], elements[8], elements[9]);

	fprintf(stderr, "Your output is:\n");
	fprintf(stderr, "Elements sum is %d\n", elements_sum);
	fprintf(stderr, "Minimum element is %d\n", minimum_element);
	fprintf(stderr, "Maximum element is %d\n\n", maximum_element);

	int expected_elements_sum = 0;
	for (int i = 0; i < 10; i++) {
		if (elements[i] < minimum_element) {
			return 0;
		}
		
		if (elements[i] > maximum_element) {
			return 0;
		}
		
		expected_elements_sum += elements[i];
	}

	return (elements_sum == expected_elements_sum);
}

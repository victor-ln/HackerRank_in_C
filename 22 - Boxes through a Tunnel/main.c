#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 41

struct box
{
	int		length;
	int		width;
	int		height;
};

typedef struct box box;

/**
 * Returns the volume of the box
 */
int	get_volume(box b)
{
	return (b.height * b.width * b.length);
}

/**
 * Returns 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
 */
int	is_lower_than_max_height(box b)
{
	return (b.height < 41);
}

int main(void)
{
	int		n;

	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	for (int i = 0; i < n; i++)
		if (is_lower_than_max_height(boxes[i]))
			printf("%d\n", get_volume(boxes[i]));
	return (0);
}

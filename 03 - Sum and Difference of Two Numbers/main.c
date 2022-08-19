#include <stdio.h>

int	main(void)
{
	int		num[2];
	float	num_f[2];

	scanf("%d %d", num, num + 1);
	scanf("%f %f", num_f, num_f + 1);
	printf("%d %d\n", num[0] + num[1], num[0] - num[1]);
	printf("%.1f %.1f\n", num_f[0] + num_f[1], num_f[0] - num_f[1]);
	return (0);
}

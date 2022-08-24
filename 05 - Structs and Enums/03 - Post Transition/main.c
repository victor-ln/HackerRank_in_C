#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

struct package
{
	char*	id;
	int		weight;
};

typedef struct package package;

struct post_office
{
	int			min_weight;
	int			max_weight;
	package*	packages;
	int			packages_count;
};

typedef struct post_office post_office;

struct town
{
	char*			name;
	post_office*	offices;
	int				offices_count;
};

typedef struct town town;

void print_all_packages(town t)
{
	int		i;
	int		j;

	i = 0;
	printf("%s:\n",  t.name);
	while (i < t.offices_count)
	{
		j = 0;
		printf("\t%d:\n", i);
		while (j < t.offices[i].packages_count)
		{
			printf("\t\t%s\n", t.offices[i].packages[j].id);
			j++;
		}
		i++;
	}
}

void	send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index)
{
	package		*new_target_packages;
	int			weight;
	int			i;

	i = 0;
	new_target_packages = realloc(\
		target->offices[target_office_index].packages, \
		sizeof(package) * \
			(target->offices[target_office_index].packages_count + \
			source->offices[source_office_index].packages_count) \
	);
	while (i < source->offices[source_office_index].packages_count)
	{
		weight = source->offices[source_office_index].packages[i].weight;
		if (weight >= target->offices[target_office_index].min_weight && \
			weight <= target->offices[target_office_index].max_weight)
		{
			new_target_packages[target->offices[target_office_index].packages_count++] = \
				source->offices[source_office_index].packages[i];
			memmove(\
				source->offices[source_office_index].packages + i, \
				source->offices[source_office_index].packages + i + 1, \
				sizeof(package) * (--source->offices[source_office_index].packages_count - i) \
			);
		}
		else
			i++;
	}
	source->offices[source_office_index].packages = realloc(\
		source->offices[source_office_index].packages, \
		sizeof(package) * source->offices[source_office_index].packages_count
	);
	target->offices[target_office_index].packages = realloc(\
		new_target_packages, \
		sizeof(package) * target->offices[target_office_index].packages_count
	);
}

int	town_packages(town *town)
{
	int office_index;
	int packages;

	office_index = 0;
	packages = 0;
	while (office_index < town->offices_count)
		packages += town->offices[office_index++].packages_count;
	return (packages);
}

town	town_with_most_packages(town* towns, int towns_count)
{
	int		most_packages_town;
	int		most_packages;
	int		aux;
	int		i;

	i = 0;
	most_packages = 0;
	most_packages_town = 0;
	while (i < towns_count)
	{
		aux = town_packages(towns + i);
		if (aux > most_packages)
		{
			most_packages = aux;
			most_packages_town = i;
		}
		i++;
	}
	return (towns[most_packages_town]);
}

town*	find_town(town* towns, int towns_count, char* name)
{
	int		i;

	i = 0;
	while (i < towns_count)
	{
		if (!strcmp(towns[i].name, name))
			return (towns + i);
		i++;
	}
	return (0);
}

int	main(void)
{
	int		towns_count;

	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++)
	{
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++)
		{
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++)
			{
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int		queries;

	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--)
	{
		int		type;

		scanf("%d", &type);
		switch (type)
		{
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break ;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break ;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break ;
		}
	}
	return 0;
}
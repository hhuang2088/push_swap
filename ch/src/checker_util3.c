#include "checker.h"

int	space_check(char **line_split, char *line)
{
	int		i;
	int		j;
	int		spaces;

	i = 0;
	j = 0;
	spaces = 0;
	while (line_split[i])
		++i;
	while (line[j])
	{
		if (line[j] == ' ')
			++spaces;
		++j;
	}
	if (spaces != i - 1)
		return (0);
	return (1);
}

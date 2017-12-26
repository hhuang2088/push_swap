#include "checker.h"

int		is_int_input(char *input)
{
	int		neg;
	int		len;

	neg = 0;
	len = ft_strlen(input);
	neg = (input[0] == '-') ? 1 : 0;
	if (neg && len < 11)
		return (1);
	else if (len < 10)
		return (1);
	if (neg && ft_strcmp("-2147483648", input) >= 0)
		return (1);
	else if (!neg && ft_strcmp("2147483647", input) >= 0)
		return (1);
	return (0);
}

static int	free_linesplit(char **line_split)
{
	int	i;

	i = 0;
	while (line_split[i])
		free(line_split[i++]);
	free(line_split);
	return (0);
}

int		command_check_helper(char **line_split, int i)
{
	if (!ft_strcmp(line_split[i], "sa"))
		return (1);
	else if (!ft_strcmp(line_split[i], "sb"))
		return (1);
	else if (!ft_strcmp(line_split[i], "ss"))
		return (1);
	else if (!ft_strcmp(line_split[i], "ra"))
		return (1);
	else if (!ft_strcmp(line_split[i], "rb"))
		return (1);
	else if (!ft_strcmp(line_split[i], "rr"))
		return (1);
	else if (!ft_strcmp(line_split[i], "pa"))
		return (1);
	else if (!ft_strcmp(line_split[i], "pb"))
		return (1);
	else if (!ft_strcmp(line_split[i], "rra"))
		return (1);
	else if (!ft_strcmp(line_split[i], "rrb"))
		return (1);
	else if (!ft_strcmp(line_split[i], "rrr"))
		return (1);
	return (0);
}

int		command_check(char **line_split)
{
	int		i;
	int		line_check;

	i = 0;
	while (line_split[i])
	{
		if (!ft_strlen(line_split[i]))
			line_check = 1;
		line_check = command_check_helper(line_split, i);
		if (!line_check)
			return (free_linesplit(line_split));
		++i;
	}
	return (1);
}

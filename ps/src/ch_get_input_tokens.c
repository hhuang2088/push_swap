/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_get_input_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:16:11 by hehuang           #+#    #+#             */
/*   Updated: 2018/11/26 15:17:46 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char		**init_av_tokens(int new_ac)
{
	char	**av_tokens;

	if (!(av_tokens = (char**)malloc(sizeof(char*) * (new_ac + 1))))
		return (NULL);
	av_tokens[new_ac] = NULL;
	return (av_tokens);
}

static int		fill_av_tokens(char **av_tokens, char **av, int ac)
{
	char	**current_av;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		if (!(current_av = ft_strsplit(av[i++], ' ')))
			return (0);
		while (current_av[j])
		{
			av_tokens[k] = current_av[j];
			++k;
			++j;
		}
		free(current_av);
	}
	return (1);
}

int				get_new_ac(int ac, char **av)
{
	int new_ac;
	int	i;

	new_ac = 0;
	i = 0;
	while (i < ac)
		new_ac += word_count(av[i++], ' ');
	return (new_ac);
}

char			**ch_get_input_tokens(int ac, char **av, int new_ac)
{
	int		i;
	char	**av_tokens;

	i = 0;
	if (!(av_tokens = init_av_tokens(new_ac)))
		return (NULL);
	fill_av_tokens(av_tokens, av, ac);
	return (av_tokens);
}
